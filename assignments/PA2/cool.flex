/*
 *  The scanner definition for COOL.
 */

/*
 *  Stuff enclosed in %{ %} in the first section is copied verbatim to the
 *  output, so headers and global definitions are placed here to be visible
 * to the code in the file.  Don't remove anything that was here initially
 */
%{
#include <cool-parse.h>
#include <stringtab.h>
#include <utilities.h>

/* The compiler assumes these identifiers. */
#define yylval cool_yylval
#define yylex  cool_yylex

/* Max size of string constants */
#define MAX_STR_CONST 1025
#define YY_NO_UNPUT   /* keep g++ happy */

extern FILE *fin; /* we read from this file */

/* define YY_INPUT so we read from the FILE fin:
 * This change makes it possible to use this scanner in
 * the Cool compiler.
 */
#undef YY_INPUT
#define YY_INPUT(buf,result,max_size) \
	if ( (result = fread( (char*)buf, sizeof(char), max_size, fin)) < 0) \
		YY_FATAL_ERROR( "read() in flex scanner failed");

char string_buf[MAX_STR_CONST]; /* to assemble string constants */
char *string_buf_ptr;

extern int curr_lineno;
extern int verbose_flag;

extern YYSTYPE cool_yylval;

/*
 *  Add Your own definitions here
 */

%}

/*
 * Define names for regular expressions here.
 * Integers are non-empty strings of digits 0-9.
 * Identifiers are strings (other than keywords) consisting ofletters, digits, and the underscore character.
 * Type identifiers begin with a capital letter.
 * object identifiersbegin with a lower case letter.
 */

DARROW          =>
CLASS           class
ELSE            else
IF              if
FI              fi
IN              in
INHERITS        inherits
LET             let
LOOP            loop
POOL            pool
THEN            then
WHILE           while
CASE            case
ESAC            esac
OF              of
NEW             new
ISVOID          isvoid
ASSIGN          <-
NOT             not
LE              <=

DIGIT           [0-9]+
TYPEID          [A-Z][a-zA-Z_]*
OBJECTID        [a-z][a-zA-Z_]*


%Start          COMMENT
%Start          STRING
%Start          SINGLE_LINE



%%


 /*
  *  single line comments
  */


<INITIAL>"--" { BEGIN(SINGLE_LINE);}

<SINGLE_LINE>[^\n]* {}

<SINGLE_LINE>[\n] {
    curr_lineno ++;
    BEGIN(INITIAL);
}


 /*
  *  comments
  */


<INITIAL>"(*" {
    BEGIN(COMMENT);
}

<COMMENT>"\n" {
    curr_lineno ++;
}

<COMMENT>"*)" {
    BEGIN(INITIAL);
}

<COMMENT><<EOF>> {
    cool_yylval.error_msg = "EOF in comment";
    BEGIN(INITIAL);
    return ERROR;
}

<COMMENT>[^\n(*)]* {}

<COMMENT>[(*)] {}

"*)" {
    cool_yylval.error_msg = "Unmatched *)";
    return ERROR;
}





 /*
  *  string constant
  */


<INITIAL>\" {
    BEGIN(STRING);
    yymore();
}

<STRING><<EOF>> {
    cool_yylval.error_msg = "EOF in string constant";
    BEGIN(INITIAL);
    return ERROR;
}

<STRING>[^\"\\\n\0]* {
    yymore();
}

<STRING>\\[^\n] {
    yymore();
}

<STRING>\\\n {
    curr_lineno ++;
    yymore();
}

<STRING>\0 {
    cool_yylval.error_msg = "String contains null character";
    BEGIN(INITIAL);
    return ERROR;
}

<STRING>\n {
    cool_yylval.error_msg = "Unterminated string constant";
    curr_lineno ++;
    BEGIN(INITIAL);
    return ERROR;
}

<STRING>\" {
    std::string in(yytext, yyleng);
    in = in.substr(1, in.length() - 2);

    std::string out = "";
    std::string::size_type pos;
    while ((pos = in.find_first_of("\\")) != std::string::npos) {
        out += in.substr(0, pos);
        if (pos >= in.length() - 1) {
            cool_yylval.error_msg = "Unterminated string constant";
            BEGIN(INITIAL);
            return ERROR;
        }
        
        switch(in[pos + 1]) {
            case 'b' :
            out += "\b";
            break;

            case 't' :
            out += "\t";
            break;

            case 'n' :
            out += "\n";
            break;

            case 'f' :
            out += "\f";
            break;

            default :
            out += in[pos + 1];
            break;
        }
        in = in.substr(pos + 2, in.length() - 2);
    }

    out += in;

    if (out.length() > MAX_STR_CONST) {
        cool_yylval.error_msg = "String constant too long";
        BEGIN(INITIAL);
        return ERROR;
    }

    cool_yylval.symbol = stringtable.add_string((char *)out.c_str());
    BEGIN(INITIAL);
    return STR_CONST;
}


 /*
  *  keywords
  */


{CLASS}     {  return (CLASS);  }
{ELSE}      {  return (ELSE);   }
{IF}        {  return (IF);     }
{FI}        {  return (FI);     }
{IN}        {  return (IN);     }
{INHERITS}  {  return (INHERITS);}
{LET}       {  return (LET);    }
{LOOP}      {  return (LOOP);   }
{POOL}      {  return (POOL);   }
{THEN}      {  return (THEN);   }
{WHILE}     {  return (WHILE);  }
{CASE}      {  return (CASE);   }
{ESAC}      {  return (ESAC);   }
{OF}        {  return (OF);     }
{NEW}       {  return (NEW);    }
{ISVOID}    {  return (ISVOID); }
{NOT}       {  return (NOT);    }


 /*
  *  operators
  */


{DARROW}	{ return (DARROW);   }
{ASSIGN}    {  return (ASSIGN);  }
{LE}        {  return (LE);      }
"<"         {  return int('<');  }
"="         {  return int('=');  }
"+"         {  return int('+');  }
"-"         {  return int('-');  }
"*"         {  return int('*');  }
"/"         {  return int('/');  }
"@"         {  return int('@');  }
"{"         {  return int('{');  }
"}"         {  return int('}');  }
"~"         {  return int('~');  }
";"         {  return int(';');  }
"."         {  return int('.');  }
","         {  return int(',');  }
"("         {  return int('(');  }
")"         {  return int(')');  }
":"         {  return int(':');  }


 /*
  *  type identifiers
  */


{TYPEID}    {
    cool_yylval.symbol = idtable.add_string(yytext);
    return TYPEID;
}


 /*
  *  object identifiers
  */


{OBJECTID}  {
    cool_yylval.symbol = idtable.add_string(yytext);
    return OBJECTID;
}


 /*
  *  integers
  */

{DIGIT}     {
    cool_yylval.symbol = inttable.add_string(yytext);
    return INT_CONST;
}


  /*
  *  true and false
  */

t[rR][uU][eE] {
    cool_yylval.boolean = true;
    return BOOL_CONST;
}

f[aA][lL][sS][eE] {
    cool_yylval.boolean = false;
    return BOOL_CONST;
}


 /*
  *  white space
  */


[ \t\b\f]+ {}

\n {  curr_lineno++; }


 /*
  *  error
  */


. {
    cool_yylval.error_msg = yytext;
    return ERROR;
}


%%
