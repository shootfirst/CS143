
//**************************************************************
//
// Code generator SKELETON
//
// Read the comments carefully. Make sure to
//    initialize the base class tags in
//       `CgenClassTable::CgenClassTable'
//
//    Add the label for the dispatch tables to
//       `IntEntry::code_def'
//       `StringEntry::code_def'
//       `BoolConst::code_def'
//
//    Add code to emit everyting else that is needed
//       in `CgenClassTable::code'
//
//
// The files as provided will produce code to begin the code
// segments, declare globals, and emit constants.  You must
// fill in the rest.
//
//**************************************************************

#include <unordered_map>
#include <algorithm>
#include <vector>
#include "cgen.h"
#include "cgen_gc.h"

extern void emit_string_constant(ostream& str, char *s);
extern int cgen_debug;

//
// Three symbols from the semantic analyzer (semant.cc) are used.
// If e : No_type, then no code is generated for e.
// Special code is generated for new SELF_TYPE.
// The name "self" also generates code different from other references.
//
//////////////////////////////////////////////////////////////////////
//
// Symbols
//
// For convenience, a large number of symbols are predefined here.
// These symbols include the primitive type and method names, as well
// as fixed names used by the runtime system.
//
//////////////////////////////////////////////////////////////////////
Symbol
       arg,
       arg2,
       Bool,
       concat,
       cool_abort,
       copy,
       Int,
       in_int,
       in_string,
       IO,
       length,
       Main,
       main_meth,
       No_class,
       No_type,
       Object,
       out_int,
       out_string,
       prim_slot,
       self,
       SELF_TYPE,
       Str,
       str_field,
       substr,
       type_name,
       val;
//
// Initializing the predefined symbols.
//
static void initialize_constants(void)
{
  arg         = idtable.add_string("arg");
  arg2        = idtable.add_string("arg2");
  Bool        = idtable.add_string("Bool");
  concat      = idtable.add_string("concat");
  cool_abort  = idtable.add_string("abort");
  copy        = idtable.add_string("copy");
  Int         = idtable.add_string("Int");
  in_int      = idtable.add_string("in_int");
  in_string   = idtable.add_string("in_string");
  IO          = idtable.add_string("IO");
  length      = idtable.add_string("length");
  Main        = idtable.add_string("Main");
  main_meth   = idtable.add_string("main");
//   _no_class is a symbol that can't be the name of any
//   user-defined class.
  No_class    = idtable.add_string("_no_class");
  No_type     = idtable.add_string("_no_type");
  Object      = idtable.add_string("Object");
  out_int     = idtable.add_string("out_int");
  out_string  = idtable.add_string("out_string");
  prim_slot   = idtable.add_string("_prim_slot");
  self        = idtable.add_string("self");
  SELF_TYPE   = idtable.add_string("SELF_TYPE");
  Str         = idtable.add_string("String");
  str_field   = idtable.add_string("_str_field");
  substr      = idtable.add_string("substr");
  type_name   = idtable.add_string("type_name");
  val         = idtable.add_string("_val");
}

static char *gc_init_names[] =
  { "_NoGC_Init", "_GenGC_Init", "_ScnGC_Init" };
static char *gc_collect_names[] =
  { "_NoGC_Collect", "_GenGC_Collect", "_ScnGC_Collect" };


//  BoolConst is a class that implements code generation for operations
//  on the two booleans, which are given global names here.
BoolConst falsebool(FALSE);
BoolConst truebool(TRUE);

//*********************************************************
//
// Define method for code generation
//
// This is the method called by the compiler driver
// `cgtest.cc'. cgen takes an `ostream' to which the assembly will be
// emmitted, and it passes this and the class list of the
// code generator tree to the constructor for `CgenClassTable'.
// That constructor performs all of the work of the code
// generator.
//
//*********************************************************

void program_class::cgen(ostream &os)
{
  // spim wants comments to start with '#'
  os << "# start of generated code\n";

  initialize_constants();
  CgenClassTable *codegen_classtable = new CgenClassTable(classes,os);

  os << "\n# end of generated code\n";
}


//////////////////////////////////////////////////////////////////////////////
//
//  emit_* procedures
//
//  emit_X  writes code for operation "X" to the output stream.
//  There is an emit_X for each opcode X, as well as emit_ functions
//  for generating names according to the naming conventions (see emit.h)
//  and calls to support functions defined in the trap handler.
//
//  Register names and addresses are passed as strings.  See `emit.h'
//  for symbolic names you can use to refer to the strings.
//
//////////////////////////////////////////////////////////////////////////////

static void emit_load(char *dest_reg, int offset, char *source_reg, ostream& s)
{
  s << LW << dest_reg << " " << offset * WORD_SIZE << "(" << source_reg << ")"
    << endl;
}

static void emit_store(char *source_reg, int offset, char *dest_reg, ostream& s)
{
  s << SW << source_reg << " " << offset * WORD_SIZE << "(" << dest_reg << ")"
      << endl;
}

static void emit_load_imm(char *dest_reg, int val, ostream& s)
{ s << LI << dest_reg << " " << val << endl; }

static void emit_load_address(char *dest_reg, char *address, ostream& s)
{ s << LA << dest_reg << " " << address << endl; }

static void emit_partial_load_address(char *dest_reg, ostream& s)
{ s << LA << dest_reg << " "; }

static void emit_load_bool(char *dest, const BoolConst& b, ostream& s)
{
  emit_partial_load_address(dest,s);
  b.code_ref(s);
  s << endl;
}

static void emit_load_string(char *dest, StringEntry *str, ostream& s)
{
  emit_partial_load_address(dest,s);
  str->code_ref(s);
  s << endl;
}

static void emit_load_int(char *dest, IntEntry *i, ostream& s)
{
  emit_partial_load_address(dest,s);
  i->code_ref(s);
  s << endl;
}

static void emit_move(char *dest_reg, char *source_reg, ostream& s)
{ s << MOVE << dest_reg << " " << source_reg << endl; }

static void emit_neg(char *dest, char *src1, ostream& s)
{ s << NEG << dest << " " << src1 << endl; }

static void emit_add(char *dest, char *src1, char *src2, ostream& s)
{ s << ADD << dest << " " << src1 << " " << src2 << endl; }

static void emit_addu(char *dest, char *src1, char *src2, ostream& s)
{ s << ADDU << dest << " " << src1 << " " << src2 << endl; }

static void emit_addiu(char *dest, char *src1, int imm, ostream& s)
{ s << ADDIU << dest << " " << src1 << " " << imm << endl; }

static void emit_div(char *dest, char *src1, char *src2, ostream& s)
{ s << DIV << dest << " " << src1 << " " << src2 << endl; }

static void emit_mul(char *dest, char *src1, char *src2, ostream& s)
{ s << MUL << dest << " " << src1 << " " << src2 << endl; }

static void emit_sub(char *dest, char *src1, char *src2, ostream& s)
{ s << SUB << dest << " " << src1 << " " << src2 << endl; }

static void emit_sll(char *dest, char *src1, int num, ostream& s)
{ s << SLL << dest << " " << src1 << " " << num << endl; }

static void emit_jalr(char *dest, ostream& s)
{ s << JALR << "\t" << dest << endl; }

static void emit_jal(char *address,ostream &s)
{ s << JAL << address << endl; }

static void emit_return(ostream& s)
{ s << RET << endl; }

static void emit_gc_assign(ostream& s)
{ s << JAL << "_GenGC_Assign" << endl; }

static void emit_disptable_ref(Symbol sym, ostream& s)
{  s << sym << DISPTAB_SUFFIX; }

static void emit_init_ref(Symbol sym, ostream& s)
{ s << sym << CLASSINIT_SUFFIX; }

static void emit_label_ref(int l, ostream &s)
{ s << "label" << l; }

static void emit_protobj_ref(Symbol sym, ostream& s)
{ s << sym << PROTOBJ_SUFFIX; }

static void emit_method_ref(Symbol classname, Symbol methodname, ostream& s)
{ s << classname << METHOD_SEP << methodname; }

static void emit_label_def(int l, ostream &s)
{
  emit_label_ref(l,s);
  s << ":" << endl;
}

static void emit_beqz(char *source, int label, ostream &s)
{
  s << BEQZ << source << " ";
  emit_label_ref(label,s);
  s << endl;
}

static void emit_beq(char *src1, char *src2, int label, ostream &s)
{
  s << BEQ << src1 << " " << src2 << " ";
  emit_label_ref(label,s);
  s << endl;
}

static void emit_bne(char *src1, char *src2, int label, ostream &s)
{
  s << BNE << src1 << " " << src2 << " ";
  emit_label_ref(label,s);
  s << endl;
}

static void emit_bleq(char *src1, char *src2, int label, ostream &s)
{
  s << BLEQ << src1 << " " << src2 << " ";
  emit_label_ref(label,s);
  s << endl;
}

static void emit_blt(char *src1, char *src2, int label, ostream &s)
{
  s << BLT << src1 << " " << src2 << " ";
  emit_label_ref(label,s);
  s << endl;
}

static void emit_blti(char *src1, int imm, int label, ostream &s)
{
  s << BLT << src1 << " " << imm << " ";
  emit_label_ref(label,s);
  s << endl;
}

static void emit_bgti(char *src1, int imm, int label, ostream &s)
{
  s << BGT << src1 << " " << imm << " ";
  emit_label_ref(label,s);
  s << endl;
}

static void emit_branch(int l, ostream& s)
{
  s << BRANCH;
  emit_label_ref(l,s);
  s << endl;
}

//
// Push a register on the stack. The stack grows towards smaller addresses.
//
static void emit_push(char *reg, ostream& str)
{
  emit_store(reg,0,SP,str);
  emit_addiu(SP,SP,-4,str);
}

//
// Fetch the integer value in an Int object.
// Emits code to fetch the integer value of the Integer object pointed
// to by register source into the register dest
//
static void emit_fetch_int(char *dest, char *source, ostream& s)
{ emit_load(dest, DEFAULT_OBJFIELDS, source, s); }

//
// Emits code to store the integer value contained in register source
// into the Integer object pointed to by dest.
//
static void emit_store_int(char *source, char *dest, ostream& s)
{ emit_store(source, DEFAULT_OBJFIELDS, dest, s); }


static void emit_test_collector(ostream &s)
{
  emit_push(ACC, s);
  emit_move(ACC, SP, s); // stack end
  emit_move(A1, ZERO, s); // allocate nothing
  s << JAL << gc_collect_names[cgen_Memmgr] << endl;
  emit_addiu(SP,SP,4,s);
  emit_load(ACC,0,SP,s);
}

static void emit_gc_check(char *source, ostream &s)
{
  if (source != (char*)A1) emit_move(A1, source, s);
  s << JAL << "_gc_check" << endl;
}


///////////////////////////////////////////////////////////////////////////////
//
// coding strings, ints, and booleans
//
// Cool has three kinds of constants: strings, ints, and booleans.
// This section defines code generation for each type.
//
// All string constants are listed in the global "stringtable" and have
// type StringEntry.  StringEntry methods are defined both for String
// constant definitions and references.
//
// All integer constants are listed in the global "inttable" and have
// type IntEntry.  IntEntry methods are defined for Int
// constant definitions and references.
//
// Since there are only two Bool values, there is no need for a table.
// The two booleans are represented by instances of the class BoolConst,
// which defines the definition and reference methods for Bools.
//
///////////////////////////////////////////////////////////////////////////////

//
// Strings
//
void StringEntry::code_ref(ostream& s)
{
  s << STRCONST_PREFIX << index;
}

//
// Emit code for a constant String.
// You should fill in the code naming the dispatch table.
//

void StringEntry::code_def(ostream& s, int stringclasstag)
{
  IntEntryP lensym = inttable.add_int(len);

  // Add -1 eye catcher
  s << WORD << "-1" << endl;

  code_ref(s);  s  << LABEL                                             // label
      << WORD << stringclasstag << endl                                 // tag
      << WORD << (DEFAULT_OBJFIELDS + STRING_SLOTS + (len+4)/4) << endl // size
      << WORD;


 /***** Add dispatch information for class String ******/
      emit_disptable_ref(Str, s);

      s << endl;                                              // dispatch table
      s << WORD;  lensym->code_ref(s);  s << endl;            // string length
  emit_string_constant(s,str);                                // ascii string
  s << ALIGN;                                                 // align to word
}

//
// StrTable::code_string
// Generate a string object definition for every string constant in the
// stringtable.
//
void StrTable::code_string_table(ostream& s, int stringclasstag)
{
  for (List<StringEntry> *l = tbl; l; l = l->tl())
    l->hd()->code_def(s,stringclasstag);
}

//
// Ints
//
void IntEntry::code_ref(ostream &s)
{
  s << INTCONST_PREFIX << index;
}

//
// Emit code for a constant Integer.
// You should fill in the code naming the dispatch table.
//

void IntEntry::code_def(ostream &s, int intclasstag)
{
  // Add -1 eye catcher
  s << WORD << "-1" << endl;

  code_ref(s);  s << LABEL                                // label
      << WORD << intclasstag << endl                      // class tag
      << WORD << (DEFAULT_OBJFIELDS + INT_SLOTS) << endl  // object size
      << WORD;

 /***** Add dispatch information for class Int ******/
      emit_disptable_ref(Int, s);

      s << endl;                                          // dispatch table
      s << WORD << str << endl;                           // integer value
}


//
// IntTable::code_string_table
// Generate an Int object definition for every Int constant in the
// inttable.
//
void IntTable::code_string_table(ostream &s, int intclasstag)
{
  for (List<IntEntry> *l = tbl; l; l = l->tl())
    l->hd()->code_def(s,intclasstag);
}


//
// Bools
//
BoolConst::BoolConst(int i) : val(i) { assert(i == 0 || i == 1); }

void BoolConst::code_ref(ostream& s) const
{
  s << BOOLCONST_PREFIX << val;
}

//
// Emit code for a constant Bool.
// You should fill in the code naming the dispatch table.
//

void BoolConst::code_def(ostream& s, int boolclasstag)
{
  // Add -1 eye catcher
  s << WORD << "-1" << endl;

  code_ref(s);  s << LABEL                                  // label
      << WORD << boolclasstag << endl                       // class tag
      << WORD << (DEFAULT_OBJFIELDS + BOOL_SLOTS) << endl   // object size
      << WORD;

 /***** Add dispatch information for class Bool ******/
      emit_disptable_ref(Bool, s);
      s << endl;                                            // dispatch table
      s << WORD << val << endl;                             // value (0 or 1)
}

//////////////////////////////////////////////////////////////////////////////
//
//  CgenClassTable methods
//
//////////////////////////////////////////////////////////////////////////////

//***************************************************
//
//  Emit code to start the .data segment and to
//  declare the global names.
//
//***************************************************

void CgenClassTable::code_global_data()
{
  Symbol main    = idtable.lookup_string(MAINNAME);
  Symbol string  = idtable.lookup_string(STRINGNAME);
  Symbol integer = idtable.lookup_string(INTNAME);
  Symbol boolc   = idtable.lookup_string(BOOLNAME);

  str << "\t.data\n" << ALIGN;
  //
  // The following global names must be defined first.
  //
  str << GLOBAL << CLASSNAMETAB << endl;
  str << GLOBAL; emit_protobj_ref(main,str);    str << endl;
  str << GLOBAL; emit_protobj_ref(integer,str); str << endl;
  str << GLOBAL; emit_protobj_ref(string,str);  str << endl;
  str << GLOBAL; falsebool.code_ref(str);  str << endl;
  str << GLOBAL; truebool.code_ref(str);   str << endl;
  str << GLOBAL << INTTAG << endl;
  str << GLOBAL << BOOLTAG << endl;
  str << GLOBAL << STRINGTAG << endl;

  //
  // We also need to know the tag of the Int, String, and Bool classes
  // during code generation.
  //
  str << INTTAG << LABEL
      << WORD << intclasstag << endl;
  str << BOOLTAG << LABEL
      << WORD << boolclasstag << endl;
  str << STRINGTAG << LABEL
      << WORD << stringclasstag << endl;
}


//***************************************************
//
//  Emit code to start the .text segment and to
//  declare the global names.
//
//***************************************************

void CgenClassTable::code_global_text()
{
  str << GLOBAL << HEAP_START << endl
      << HEAP_START << LABEL
      << WORD << 0 << endl
      << "\t.text" << endl
      << GLOBAL;
  emit_init_ref(idtable.add_string("Main"), str);
  str << endl << GLOBAL;
  emit_init_ref(idtable.add_string("Int"),str);
  str << endl << GLOBAL;
  emit_init_ref(idtable.add_string("String"),str);
  str << endl << GLOBAL;
  emit_init_ref(idtable.add_string("Bool"),str);
  str << endl << GLOBAL;
  emit_method_ref(idtable.add_string("Main"), idtable.add_string("main"), str);
  str << endl;
}

void CgenClassTable::code_bools(int boolclasstag)
{
  falsebool.code_def(str,boolclasstag);
  truebool.code_def(str,boolclasstag);
}

void CgenClassTable::code_select_gc()
{
  //
  // Generate GC choice constants (pointers to GC functions)
  //
  str << GLOBAL << "_MemMgr_INITIALIZER" << endl;
  str << "_MemMgr_INITIALIZER:" << endl;
  str << WORD << gc_init_names[cgen_Memmgr] << endl;
  str << GLOBAL << "_MemMgr_COLLECTOR" << endl;
  str << "_MemMgr_COLLECTOR:" << endl;
  str << WORD << gc_collect_names[cgen_Memmgr] << endl;
  str << GLOBAL << "_MemMgr_TEST" << endl;
  str << "_MemMgr_TEST:" << endl;
  str << WORD << (cgen_Memmgr_Test == GC_TEST) << endl;
}

void CgenClassTable::set_class_tag_internal(CgenNodeP cur, int cur_dep) {

  class_depth[cur->get_name()] = cur_dep;
  int begin_idx = tag_to_class.size();
  tag_to_class.push_back(cur->get_name());
  auto children = cur->get_children();
  for (List<CgenNode> *l = children; l; l = l->tl()) {
    CgenNodeP cur_child = l->hd();
    set_class_tag_internal(cur_child, cur_dep + 1);
  }
  int end_idx = tag_to_class.size() - 1;
  class_tag_range[cur->get_name()] = {begin_idx, end_idx};
}

// set a tag for every class
// use dfs seq number for simplify case expression
void CgenClassTable::set_class_tag() {

  CgenNodeP root_class = root();
  set_class_tag_internal(root_class, 0);

  // set the correct class tag
  stringclasstag = class_tag_range[idtable.lookup_string("String")].first;
  intclasstag = class_tag_range[idtable.lookup_string("Int")].first;
  boolclasstag = class_tag_range[idtable.lookup_string("Bool")].first;

  if (cgen_debug) {
    cout << "The class tag range is: " << std::endl;
    for (auto& [k, v] : class_tag_range) {
      cout << k << " " << v.first << " " << v.second << endl;
    }
    cout << "The class depth in inherite tree" << std::endl;
    for (auto& [k, v] : class_depth) {
      cout << k << ' ' << v << std::endl;
    }
  }
}

//********************************************************
//
// Emit code to reserve space for and initialize all of
// the constants.  Class names should have been added to
// the string table (in the supplied code, is is done
// during the construction of the inheritance graph), and
// code for emitting string constants as a side effect adds
// the string's length to the integer table.  The constants
// are emmitted by running through the stringtable and inttable
// and producing code for each entry.
//
//********************************************************

void CgenClassTable::code_constants()
{
  //
  // Add constants that are required by the code generator.
  //
  stringtable.add_string("");
  inttable.add_string("0");

  stringtable.code_string_table(str,stringclasstag);
  inttable.code_string_table(str,intclasstag);
  code_bools(boolclasstag);
}



CgenClassTable::CgenClassTable(Classes classes, ostream& s) : nds(NULL) , str(s)
{
  //  stringclasstag = 2 /* Change to your String class tag here */;
  //  intclasstag =    3 /* Change to your Int class tag here */;
  //  boolclasstag =   4 /* Change to your Bool class tag here */;

   enterscope();
   if (cgen_debug) cout << "Building CgenClassTable" << endl;
   install_basic_classes();
   install_classes(classes);
   build_inheritance_tree();

    if (cgen_debug) cout << "Set Class Tag" << std::endl;
    set_class_tag();

   code();
   exitscope();
}

void CgenClassTable::install_basic_classes()
{

// The tree package uses these globals to annotate the classes built below.
  //curr_lineno  = 0;
  Symbol filename = stringtable.add_string("<basic class>");

//
// A few special class names are installed in the lookup table but not
// the class list.  Thus, these classes exist, but are not part of the
// inheritance hierarchy.
// No_class serves as the parent of Object and the other special classes.
// SELF_TYPE is the self class; it cannot be redefined or inherited.
// prim_slot is a class known to the code generator.
//
  addid(No_class,
	new CgenNode(class_(No_class,No_class,nil_Features(),filename),
			    Basic,this));
  addid(SELF_TYPE,
	new CgenNode(class_(SELF_TYPE,No_class,nil_Features(),filename),
			    Basic,this));
  addid(prim_slot,
	new CgenNode(class_(prim_slot,No_class,nil_Features(),filename),
			    Basic,this));

//
// The Object class has no parent class. Its methods are
//        cool_abort() : Object    aborts the program
//        type_name() : Str        returns a string representation of class name
//        copy() : SELF_TYPE       returns a copy of the object
//
// There is no need for method bodies in the basic classes---these
// are already built in to the runtime system.
//
  install_class(
   new CgenNode(
    class_(Object,
	   No_class,
	   append_Features(
           append_Features(
           single_Features(method(cool_abort, nil_Formals(), Object, no_expr())),
           single_Features(method(type_name, nil_Formals(), Str, no_expr()))),
           single_Features(method(copy, nil_Formals(), SELF_TYPE, no_expr()))),
	   filename),
    Basic,this));

//
// The IO class inherits from Object. Its methods are
//        out_string(Str) : SELF_TYPE          writes a string to the output
//        out_int(Int) : SELF_TYPE               "    an int    "  "     "
//        in_string() : Str                    reads a string from the input
//        in_int() : Int                         "   an int     "  "     "
//
   install_class(
    new CgenNode(
     class_(IO,
            Object,
            append_Features(
            append_Features(
            append_Features(
            single_Features(method(out_string, single_Formals(formal(arg, Str)),
                        SELF_TYPE, no_expr())),
            single_Features(method(out_int, single_Formals(formal(arg, Int)),
                        SELF_TYPE, no_expr()))),
            single_Features(method(in_string, nil_Formals(), Str, no_expr()))),
            single_Features(method(in_int, nil_Formals(), Int, no_expr()))),
	   filename),
    Basic,this));

//
// The Int class has no methods and only a single attribute, the
// "val" for the integer.
//
   install_class(
    new CgenNode(
     class_(Int,
	    Object,
            single_Features(attr(val, prim_slot, no_expr())),
	    filename),
     Basic,this));

//
// Bool also has only the "val" slot.
//
    install_class(
     new CgenNode(
      class_(Bool, Object, single_Features(attr(val, prim_slot, no_expr())),filename),
      Basic,this));

//
// The class Str has a number of slots and operations:
//       val                                  ???
//       str_field                            the string itself
//       length() : Int                       length of the string
//       concat(arg: Str) : Str               string concatenation
//       substr(arg: Int, arg2: Int): Str     substring
//
   install_class(
    new CgenNode(
      class_(Str,
	     Object,
             append_Features(
             append_Features(
             append_Features(
             append_Features(
             single_Features(attr(val, Int, no_expr())),
            single_Features(attr(str_field, prim_slot, no_expr()))),
            single_Features(method(length, nil_Formals(), Int, no_expr()))),
            single_Features(method(concat,
				   single_Formals(formal(arg, Str)),
				   Str,
				   no_expr()))),
	    single_Features(method(substr,
				   append_Formals(single_Formals(formal(arg, Int)),
						  single_Formals(formal(arg2, Int))),
				   Str,
				   no_expr()))),
	     filename),
        Basic,this));

}

// CgenClassTable::install_class
// CgenClassTable::install_classes
//
// install_classes enters a list of classes in the symbol table.
//
void CgenClassTable::install_class(CgenNodeP nd)
{
  Symbol name = nd->get_name();

  if (probe(name))
    {
      return;
    }

  // The class name is legal, so add it to the list of classes
  // and the symbol table.
  nds = new List<CgenNode>(nd,nds);
  addid(name,nd);
}

void CgenClassTable::install_classes(Classes cs)
{
  for(int i = cs->first(); cs->more(i); i = cs->next(i)) {
    install_class(new CgenNode(cs->nth(i),NotBasic,this));
  }
}

//
// CgenClassTable::build_inheritance_tree
//
void CgenClassTable::build_inheritance_tree()
{
  for(List<CgenNode> *l = nds; l; l = l->tl())
      set_relations(l->hd());
}

//
// CgenClassTable::set_relations
//
// Takes a CgenNode and locates its, and its parent's, inheritance nodes
// via the class table.  Parent and child pointers are added as appropriate.
//
void CgenClassTable::set_relations(CgenNodeP nd)
{
  CgenNode *parent_node = probe(nd->get_parent());
  nd->set_parentnd(parent_node);
  parent_node->add_child(nd);
}

void CgenNode::add_child(CgenNodeP n)
{
  children = new List<CgenNode>(n,children);
}

void CgenNode::set_parentnd(CgenNodeP p)
{
  assert(parentnd == NULL);
  assert(p != NULL);
  parentnd = p;
}




















// my add start

void CgenClassTable::generate_name_tab()
{
    str << CLASSNAMETAB << LABEL;
    for (int i = 0; i < tag_to_class.size(); ++i) {
        str << WORD; 
        StringEntryP tt = stringtable.lookup_string(tag_to_class[i] -> get_string());
        tt->code_ref(str);
        str << endl;
    }
}


void CgenClassTable::generate_objTab()
{
    str << CLASSOBJTAB << LABEL;
    for (int i = 0; i < tag_to_class.size(); ++i) {
        str << WORD; emit_protobj_ref(tag_to_class[i], str); str << endl;
        str << WORD; emit_init_ref(tag_to_class[i], str); str << endl;
    }
}

void CgenClassTable::generate_dispatchTab_for_each_class(CgenNodeP cur, std::ostream& str) {

  std::vector<CgenNodeP> path;

  while (cur -> get_name() != Object) {
    path.push_back(cur);
    cur = cur->get_parentnd();
  }
  path.push_back(cur);

  std::reverse(path.begin(), path.end());

  std::unordered_map<Symbol, int> method_idx;
  std::vector<std::pair<Symbol, Symbol>> methods;

  for (auto _class : path) {
    Features features = _class->get_features();
    for (int i = features->first(); features->more(i); i = features->next(i)) {

      Feature feature = features->nth(i);
      if (feature->getType() == FeatureType::METHOD_) {
        Symbol method_name = feature->get_name();
        if (method_idx.find(method_name) == method_idx.end()) {
          // the first definition of method
          methods.push_back({_class->get_name(), method_name});
          method_idx[method_name] = methods.size() - 1;
        } else {
          // override method
          methods[method_idx[method_name]] = {_class->get_name(), method_name};
        }
      }
    }
  }

  for (auto& [class_name, method_name] : methods) {
    str << WORD; emit_method_ref(class_name, method_name, str); str << endl;
  }

  // fill the method2offset_map
  auto& t = method2offset_map[path.back()->get_name()];
  const int nn = methods.size();
  for (int i = 0; i < nn; ++i) {
    t[methods[i].second] = i;
  }
}


void CgenClassTable::generate_dispatchTab()
{
    for(List<CgenNode> *l = nds; l; l = l->tl()) {
        emit_disptable_ref(l -> hd() -> get_name(), str); str << LABEL;
        generate_dispatchTab_for_each_class(l -> hd(), str);
    }

}


std::vector<std::pair<Symbol, Symbol>> CgenClassTable::collect_all_attr(CgenNodeP cur) {
  std::vector<CgenNodeP> path;
  while (cur->get_name() != Object) {
    path.push_back(cur);
    cur = cur->get_parentnd();
  }
  path.push_back(cur);

  std::reverse(path.begin(), path.end());

  std::vector<std::pair<Symbol, Symbol>> all_attrs;

  for (auto& _class : path) {

    Features features = _class->get_features();
    for (int i = features->first(); features->more(i); i = features->next(i)) {
      Feature feature = features->nth(i);
      if (feature->getType() == FeatureType::ATTR_) {
        all_attrs.push_back({feature->get_name(), feature->get_type()});
      }
    }
  }

  auto& t = attr2offset_map[path.back()->get_name()];
  const int nn = all_attrs.size();
  for (int i = 0; i < nn; ++i) {
    t[all_attrs[i].first] = i;
  }

  return all_attrs;
}

void CgenClassTable::generate_protObj()
{
    for(List<CgenNode> *l = nds; l; l = l->tl()) {
        CgenNode* cur = l->hd();
        //  The garbage collection tag is -1.
        str << WORD << -1 << endl;

        emit_protobj_ref(cur->get_name(), str); str << LABEL;

        // The class tag is a 32-bit integer identifying the class of the object and thus should be unique for each class
        str << WORD << class_tag_range[cur->get_name()].first << endl;

        auto all_attrs = collect_all_attr(cur);
        if (cur -> get_name() == Int || cur -> get_name() == Bool) {
            // one attr
            str << WORD << 4 << endl;
            // dispatch table
            str << WORD; emit_disptable_ref(cur -> get_name(), str); str << endl;
            // default value is zero
            str << WORD << 0 << endl;
        }
        else if (cur -> get_name() == Str) {
            // two attr
            str << WORD << 5 << endl;
            // dispatch table
            str << WORD; emit_disptable_ref(cur -> get_name(), str); str << endl;
            // default length is zero
            str << WORD; inttable.lookup_string("0") -> code_ref(str); str << endl;
            emit_string_constant(str, "");

        }
        else {
            str << WORD << DEFAULT_OBJFIELDS + all_attrs.size() << endl;
            // dispatch table
            str << WORD; emit_disptable_ref(cur -> get_name(), str); str << endl;
            for (auto &x : all_attrs) {
              // For the basic classes Int, Bool, and String, the attributes should be set to the defaults specified in the Cool Reference Manual.
                if ((x.second == Str) || (x.second == Bool) || (x.second == Int)) {
                    str << WORD; emit_protobj_ref(x.second, str); str << endl;
                }
              //  For the other classes, the attributes of the prototypes may be whatever you find convenient for your implementation.
                else {
                    str << WORD << 0 << endl;
                }
            }
        }
    }
}



/*  
----------
| old fp  |    <----- old sp
----------
| self    |
----------
|   ra    |    
----------
|         |    <----- new sp fp
----------
*/
static void emit_method_begin(std::ostream& s)
{
    s << "\t# push fp, s0, ra" << endl;
    emit_addiu(SP, SP, -12, s);
    emit_store(FP, 3, SP, s);
    emit_store(SELF, 2, SP, s);
    emit_store(RA, 1, SP, s);
    s << "\t# fp points to the return address" << endl;
    emit_addiu(FP, SP, 12, s);
    s << "\t# s0 is a0" << endl;
    emit_move(SELF, ACC, s);

}

static void emit_method_end(std::ostream& s, int argc)
{
    s << "\t# restore register" << endl;
    emit_load(FP, 3, SP, s);
    emit_load(SELF, 2, SP, s);
    emit_load(RA, 1, SP, s);
    emit_addiu(SP, SP, (argc + 3) * WORD_SIZE, s);
    emit_return(s);
}



void CgenClassTable::prepare_class_init()
{
    for(List<CgenNode> *l = nds; l; l = l -> tl()) {
        CgenNode* cur_class = l -> hd();
        setCurClass(cur_class);
        enterScope();

        auto& t = attr2offset_map[cur_class -> get_name()];
        addSymbol(self, BASE_LOC_TYPE::SELF_, 0);
        for (auto it = t.begin(); it != t.end(); it ++) {
            addSymbol(it -> first, BASE_LOC_TYPE::SELF_, it -> second + DEFAULT_OBJFIELDS);
        }

        emit_init_ref(cur_class->get_name(), str); str << LABEL;
        // save register
        emit_method_begin(str);
        // first, we should initialize parents attribute
        if (cur_class -> get_name() != Object) {
            CgenNodeP parent = cur_class -> get_parentnd();
            emit_move(ACC, SELF, str);
            str << JAL; emit_init_ref(parent->get_name(), str); str << endl;
            emit_move(SELF, ACC, str);
        }
        // then, we initialize self attribute
        Features features = cur_class -> get_features();
        if (cur_class -> get_name() != Str && cur_class -> get_name() != Bool && cur_class -> get_name() != Int) {
            for (int i = features -> first(); features -> more(i); i = features -> next(i)) {
                Feature feature = features->nth(i);
                if (feature->getType() == FeatureType::ATTR_) {
                    feature -> code(str, *this);
                }
            }
        }
        // recover register
        emit_method_end(str, 0);
        exitScope();
    }
}

void CgenClassTable::generate_method_code()
{
    for(List<CgenNode> *l = nds; l; l = l->tl()) {
        CgenNodeP cur_class = l -> hd();
        setCurClass(cur_class);
        if (cur_class -> get_name() == Object || 
            cur_class -> get_name() == IO ||
            cur_class -> get_name() == Int ||
            cur_class -> get_name() == Str ||
            cur_class -> get_name() == Bool) {
            continue;
        }
        
        enterScope();

        auto& t = attr2offset_map[cur_class -> get_name()];
        addSymbol(self, BASE_LOC_TYPE::SELF_, 0);
        for (auto it = t.begin(); it != t.end(); it ++) {
            addSymbol(it -> first, BASE_LOC_TYPE::SELF_, it -> second + DEFAULT_OBJFIELDS);
        }
        
        Features features = cur_class -> get_features();
        for (int i = features -> first(); features -> more(i); i = features -> next(i)) {
            Feature feature = features->nth(i);
            if (feature->getType() == FeatureType::METHOD_) {
                emit_method_ref(cur_class -> get_name(), feature -> get_name(), str); str << LABEL;

                str << "\t# now we start generate method code" << endl;
                feature -> code(str, *this);
            }
        }
        
        exitScope();
    }
}

// my add end

















void CgenClassTable::code()
{
  if (cgen_debug) cout << "coding global data" << endl;
  code_global_data();

  if (cgen_debug) cout << "choosing gc" << endl;
  code_select_gc();

  if (cgen_debug) cout << "coding constants" << endl;
  code_constants();

//                 Add your code to emit
//                   - prototype objects
//                   - class_nameTab
//                   - dispatch tables
//

// my add begin
  generate_name_tab();
  generate_objTab();
  generate_dispatchTab();
  generate_protObj();
// my add end

  if (cgen_debug) cout << "coding global text" << endl;
  code_global_text();

//                 Add your code to emit
//                   - object initializer
//                   - the class methods
//                   - etc...

// my add begin
  prepare_class_init();
  generate_method_code();
// my add end

}



CgenNodeP CgenClassTable::root()
{
   return probe(Object);
}


///////////////////////////////////////////////////////////////////////
//
// CgenNode methods
//
///////////////////////////////////////////////////////////////////////

CgenNode::CgenNode(Class_ nd, Basicness bstatus, CgenClassTableP ct) :
   class__class((const class__class &) *nd),
   parentnd(NULL),
   children(NULL),
   basic_status(bstatus)
{
   stringtable.add_string(name->get_string());          // Add class name to string table
}


//******************************************************************
//
//   Fill in the following methods to produce code for the
//   appropriate expression.  You may add or remove parameters
//   as you wish, but if you do, remember to change the parameters
//   of the declarations in `cool-tree.h'  Sample code for
//   constant integers, strings, and booleans are provided.
//
//*****************************************************************









// cool-tree.h implement begin

void attr_class::code(ostream &s, CgenClassTable& cgen_class) {
    if (init -> get_type() == NULL) {
      return;
    }
    init -> code(s, cgen_class);
    s << "\t# assign init value to the offset of self" << endl;
    auto location = cgen_class.getSymbolToLoc().lookUp(name);
    emit_store(ACC, location.offset, SELF, s);
    emit_move(ACC, SELF, s);

}

void method_class::code(ostream &s, CgenClassTable& cgen_class) {
    cgen_class.enterScope();
    s << "\t# add args" << endl;
    std::vector<Symbol> argv;
    for (int i = formals -> first(); formals -> more(i); i = formals -> next(i)) {
        argv.push_back((formals -> nth(i)) -> get_name());
    }
    int n = argv.size();

    std::reverse(argv.begin(), argv.end());
    for (int i = 0; i < n; ++i) {
      cgen_class.addSymbol(argv[i], BASE_LOC_TYPE::FP_, i + 1);
    }

/*  
----------
| args n  |    
----------
| args n-1|  sp grow
----------    |
|   ...   |   | 
----------    |
| args 1  |   v
----------
*/

    // method begin 
    emit_method_begin(s);
    expr -> code(s, cgen_class);
    emit_method_end(s, n);
    cgen_class.exitScope();
    
    
}

int CgenClassTable::get_method_offset(Symbol class_name, Symbol method_name) {
      if (class_name == SELF_TYPE) {
        class_name = cur_class->get_name();
      }
      if (method2offset_map.find(class_name) == method2offset_map.end()) {
         std::cerr << "get_method_offset error! cannot find:"  \
                   << class_name << "::" << method_name << std::endl;
      }
      auto& t = method2offset_map[class_name];
      if(t.find(method_name) == t.end()) {
        std::cerr << "get_method_offset error! cannot find:" << class_name << "::" << method_name << std::endl;
      }
      return t[method_name];
}


void assign_class::code(ostream &s, CgenClassTable& cgen_class) {
    expr -> code(s, cgen_class);
    auto& symbol_to_loc = cgen_class.getSymbolToLoc();
    auto location = symbol_to_loc.lookUp(name);

    if (location.base_loc == BASE_LOC_TYPE::SELF_) {
        emit_store(ACC, location.offset, SELF, s);
    }
    else {
        emit_store(ACC, location.offset, FP, s);
    }
}

void static_dispatch_class::code(ostream &s, CgenClassTable& cgen_class) {
  
  s << "\t# push args" << endl;
  for (int i = actual->first(); actual->more(i); i = actual->next(i)) {
    Expression expression = actual->nth(i);
    expression->code(s, cgen_class);
    emit_push(ACC, s);
  }
  

  expr->code(s, cgen_class);

  int no_void_label = cgen_class.get_next_labelid();
  s << "\t# check if void" << endl;
  emit_bne(ACC, ZERO, no_void_label, s);

  s << "\t# prepare arg to call abort" << endl;
  Symbol file_name = cgen_class.getCurClass()->get_filename();
  emit_partial_load_address(ACC, s);
  stringtable.lookup_string(file_name->get_string())->code_ref(s);
  s << endl;
  int line_no = get_line_number();
  emit_load_imm(T1, line_no, s);
  emit_jal("_dispatch_abort", s);

  emit_label_def(no_void_label, s);

  
  emit_partial_load_address(T1, s); emit_disptable_ref(type_name, s); s << endl;
  int method_offset = cgen_class.get_method_offset(type_name, name);
  emit_load(T1, method_offset, T1, s);
  emit_jalr(T1, s);

}

void dispatch_class::code(ostream &s, CgenClassTable& cgen_class) {

  s << "\t# push args" << endl;
  for (int i = actual->first(); actual->more(i); i = actual->next(i)) {
    Expression expression = actual->nth(i);
    expression->code(s, cgen_class);
    emit_push(ACC, s);
  }
 
  expr->code(s, cgen_class);

  int no_void_label = cgen_class.get_next_labelid();
  emit_bne(ACC, ZERO, no_void_label, s);
  Symbol file_name = cgen_class.getCurClass()->get_filename();
  emit_partial_load_address(ACC, s);
  stringtable.lookup_string(file_name->get_string())->code_ref(s);
  s << endl;
  int line_no = get_line_number();
  emit_load_imm(T1, line_no, s);
  emit_jal("_dispatch_abort", s);
  emit_label_def(no_void_label, s);

  emit_load(T1, DISPTABLE_OFFSET, ACC, s);
  Symbol type_name = expr->get_type();
  int method_offset = cgen_class.get_method_offset(type_name, name);
  emit_load(T1, method_offset, T1, s);
  emit_jalr(T1, s);

}

void cond_class::code(ostream &s, CgenClassTable& cgen_class) {
    pred -> code(s, cgen_class);
    int else_label = cgen_class.get_next_labelid();
    int end_label = cgen_class.get_next_labelid();
    emit_fetch_int(T1, ACC, s);

    emit_beq(ZERO, T1, else_label, s);
    then_exp -> code(s, cgen_class);
    emit_branch(end_label, s);

    emit_label_def(else_label, s);
    else_exp -> code(s, cgen_class);

    emit_label_def(end_label, s);
    

}

void loop_class::code(ostream &s, CgenClassTable& cgen_class) {
    
    int start_label = cgen_class.get_next_labelid();
    int end_label = cgen_class.get_next_labelid();
    

    emit_label_def(start_label, s);

    pred -> code(s, cgen_class);
    emit_fetch_int(T1, ACC, s);

    emit_beq(ZERO, T1, end_label, s);

    body -> code(s, cgen_class);

    s << "\t# jump to start" << endl;
    emit_branch(start_label, s);

    emit_label_def(end_label, s);

    s << "\t# return result is void" << endl;
    emit_move(ACC, ZERO, s);
}


void typcase_class::code(ostream &s, CgenClassTable& cgen_class) {
  
  expr->code(s, cgen_class);
  int end_label = cgen_class.get_next_labelid();
  int no_zero_label = cgen_class.get_next_labelid();
  int case_error1_label = cgen_class.get_next_labelid();


  s << "\t# void expression, we call abort" << endl;
  emit_bne(ACC, ZERO, no_zero_label, s);
  Symbol file_name = cgen_class.getCurClass()->get_filename();
  emit_partial_load_address(ACC, s);
  stringtable.lookup_string(file_name->get_string())->code_ref(s);
  s << endl;
  int line_no = get_line_number();
  emit_load_imm(T1, line_no, s);
  emit_jal("_case_abort2", s);


  emit_label_def(no_zero_label, s);
  emit_load(T1, TAG_OFFSET, ACC, s);

  std::vector<Case> sorted_result;
  for (int i = cases->first(); cases->more(i); i = cases->next(i)) {
    sorted_result.push_back(cases->nth(i));
  }
  std::sort(sorted_result.begin(), sorted_result.end(), [&](Case& a, Case& b) -> bool {
    return cgen_class.get_depth(a->get_type_decl()) > cgen_class.get_depth(b->get_type_decl());
  });
  const int n = sorted_result.size();

  for (int i = 0; i < n; ++i) {
    
    Case cur_case = sorted_result[i];
    Symbol type_decl = cur_case->get_type_decl();
    auto [begin_idx, end_idx] = cgen_class.get_subclass_idrang(type_decl);
    int next_branch_idx = cgen_class.get_next_labelid();

    s << "\t# check if match" << endl;
    emit_blti(T1, begin_idx, next_branch_idx, s);
    emit_bgti(T1, end_idx, next_branch_idx, s);
    
    s << "\t# new scope" << endl;
    cgen_class.enterScope();
    emit_push(ACC, s);
    int cur_stack_offset = cgen_class.push_variable();
    cgen_class.addSymbol(cur_case->get_name(), BASE_LOC_TYPE::FP_, cur_stack_offset);
    cur_case->get_expr()->code(s, cgen_class);
    emit_addiu(SP, SP, 4, s);
    s << "\t# exit new scope" << endl;
    cgen_class.exitScope();
    cgen_class.pop_variable(1);

    s << "\t# if we fit, we get to the end" << endl;
    emit_branch(end_label, s);

    s << "\t# we do not fit it, so generate next lable" << endl;
    emit_label_def(next_branch_idx, s);
  }

  s << "\t# we do not match, we call abort" << endl;
  emit_label_def(case_error1_label, s);
  emit_jal("_case_abort", s);

  s << "\t# successfully match !" << endl;
  emit_label_def(end_label, s);
}

void block_class::code(ostream &s, CgenClassTable& cgen_class) {
  for (int i = body->first(); body->more(i); i = body->next(i)) {
    Expression expr = body->nth(i);
    expr->code(s, cgen_class);
  }
}

void let_class::code(ostream &s, CgenClassTable& cgen_class) {

    if (init -> get_type() == NULL) {
        if (type_decl == Int || type_decl == Bool || type_decl == Str) {
            emit_partial_load_address(ACC, s); emit_protobj_ref(type_decl, s); s << endl;
            emit_jal("Object.copy", s);
        }
        else {
            emit_move(ACC, ZERO, s);
        }
    }
    else {
        init -> code(s, cgen_class);
    }
    s << "\t# now we push the value we creating into stack" << endl;
    emit_push(ACC, s);
    cgen_class.enterScope();
    cgen_class.addSymbol(identifier, BASE_LOC_TYPE::FP_, cgen_class.push_variable());

    body -> code(s, cgen_class);

    cgen_class.pop_variable(1);
    cgen_class.exitScope();
    emit_addiu(SP, SP, 4, s);
}

static void load_two_int(std::ostream &s, CgenClassTable& cgen_class,
                   Expression e1, Expression e2) {
  e1 -> code(s, cgen_class);
    emit_push(ACC, s);

    e2 -> code(s, cgen_class);
    emit_jal("Object.copy", s);

    emit_load(T1, 1, SP, s);

    emit_addiu(SP, SP, 4, s);

    emit_load(T2, DEFAULT_OBJFIELDS, T1, s);
    emit_load(T3, DEFAULT_OBJFIELDS, ACC, s);
}

void plus_class::code(ostream &s, CgenClassTable& cgen_class) {
  load_two_int(s, cgen_class, e1, e2);
  emit_add(T2, T2, T3, s);
  emit_store(T2, DEFAULT_OBJFIELDS, ACC, s);
}

void sub_class::code(ostream &s, CgenClassTable& cgen_class) {
  load_two_int(s, cgen_class, e1, e2);
  emit_sub(T2, T2, T3, s);
  emit_store(T2, DEFAULT_OBJFIELDS, ACC, s);
}

void mul_class::code(ostream &s, CgenClassTable& cgen_class) {
  load_two_int(s, cgen_class, e1, e2);
  emit_mul(T2, T2, T3, s);
  emit_store(T2, DEFAULT_OBJFIELDS, ACC, s);
}

void divide_class::code(ostream &s, CgenClassTable& cgen_class) {
  load_two_int(s, cgen_class, e1, e2);
  emit_div(T2, T2, T3, s);
  emit_store(T2, DEFAULT_OBJFIELDS, ACC, s);
}

void neg_class::code(ostream &s, CgenClassTable& cgen_class) {

    e1 -> code(s, cgen_class);
    
    s << "\t# copy thr object and do neg" << endl;
    emit_jal("Object.copy", s);

    emit_load(T1, DEFAULT_OBJFIELDS, ACC, s);

    s << "\t# do neg" << endl;
    emit_neg(T1, T1, s);

    s << "\t# store" << endl;
    emit_store(T1, DEFAULT_OBJFIELDS, ACC, s);

}

void lt_class::code(ostream &s, CgenClassTable& cgen_class) {
    load_two_int(s, cgen_class, e1, e2);
    int label = cgen_class.get_next_labelid();
    emit_load_bool(ACC, BoolConst(1), s);
    emit_blt(T2, T3, label, s);
    emit_load_bool(ACC, BoolConst(0), s);
    emit_label_def(label, s);
}


void eq_class::code(ostream &s, CgenClassTable& cgen_class) {

    e1 -> code(s, cgen_class);

    s << "\t# e1 we push, because if we store it in a register, it will be covered in e2 code method" << endl;
    emit_push(ACC, s);

    e2 -> code(s, cgen_class);

    s << "\t# e2 in T2" << endl;
    emit_move(T2, ACC, s);

    s << "\t# e1 in T1" << endl;
    emit_load(T1, 1, SP, s);
    emit_addiu(SP, SP, 4, s);

    int out_label = cgen_class.get_next_labelid();

    if (e1->type == Int || e1->type == Str || e1->type == Bool) {
        emit_load_bool(ACC, BoolConst(TRUE), s);
        emit_load_bool(A1, BoolConst(FALSE), s);
        emit_jal("equality_test", s);
        return;
    }

    emit_load_bool(ACC, BoolConst(TRUE), s);
    s << "\t# compare their address" << endl;
    emit_beq(T1, T2, out_label, s);
    emit_load_bool(ACC, BoolConst(FALSE), s);
    emit_label_def(out_label, s);

}


void leq_class::code(ostream &s, CgenClassTable& cgen_class) {
    load_two_int(s, cgen_class, e1, e2);
    int label = cgen_class.get_next_labelid();
    emit_load_bool(ACC, BoolConst(1), s);
    emit_bleq(T2, T3, label, s);
    emit_load_bool(ACC, BoolConst(0), s);
    emit_label_def(label, s);
}


void comp_class::code(ostream &s, CgenClassTable& cgen_class) {
    e1 -> code(s, cgen_class);
    emit_load(T1, 3, ACC, s);
    int label = cgen_class.get_next_labelid();
    emit_load_bool(ACC, BoolConst(1), s);
    emit_beq(T1, ZERO, label, s);
    emit_load_bool(ACC, BoolConst(0), s);
    emit_label_def(label, s);
}


void int_const_class::code(ostream& s, CgenClassTable& cgen_class)  
{
    emit_load_int(ACC, inttable.lookup_string(token->get_string()), s);
}

void string_const_class::code(ostream& s, CgenClassTable& cgen_class)
{
    emit_load_string(ACC, stringtable.lookup_string(token->get_string()), s);
}

void bool_const_class::code(ostream& s, CgenClassTable& cgen_class)
{
    emit_load_bool(ACC, BoolConst(val), s);
}

void new__class::code(ostream &s, CgenClassTable& cgen_class) {
    if (type_name != SELF_TYPE) {

        // load protobj to acc, and call objcopy
        std::string des = type_name -> get_string();
        emit_load_address(ACC, (char *)(des + PROTOBJ_SUFFIX).c_str(), s);
        emit_jal("Object.copy", s);

        // call class_init
        s << JAL; emit_init_ref(type_name, s); s << endl;
    }
    else {
        // we do not have LOC_SELF_CLASS name, so we can only use class tag

        s << "\t# load class_objTab" << endl;
        emit_load_address(T1, "class_objTab", s);

        s << "\t# get our class tag" << endl;
        emit_load(T2, 0, SELF, s);

        s << "\t# mult 8 to get protObj, because every class entry in class_objTab occupy 8 bytes" << endl;
        emit_sll(T2, T2, 3, s);
        s << endl;

        s << "\t# now we get the address of LOC_SELF_CLASS in class_objTab" << endl;
        emit_addu(T1, T1, T2, s);
        s << endl;

        s << "\t# store T1 because we will use it to find obj_init after call Object.copy" << endl;
        emit_push(T1, s);

        s << "\t# we load obj to a0" << endl;
        emit_load(ACC, 0, T1, s);
        s << endl;

        s << "\t# go to Object.copy" << endl;
        emit_jal("Object.copy", s);

        s << "\t# now we restore T1 value" << endl;
        emit_load(T1, 1, SP, s);
        emit_addiu(SP, SP, 4, s);
        s << endl;


        s << "\t# get init address" << endl;
        emit_load(T1, 1, T1, s);
        s << endl;

        s << "\t# go to init" << endl;
        emit_jalr(T1, s);
        s << endl;

    }
}

void isvoid_class::code(ostream &s, CgenClassTable& cgen_class) {
    e1 -> code(s, cgen_class);
    emit_move(T1, ACC, s);
    emit_load_bool(ACC, BoolConst(TRUE), s);
    int last_lable = cgen_class.get_next_labelid();
    // if zero, means isvoid, jump to lable 
    emit_beqz(T1, last_lable, s);
    // if not zero, means not isvoid, do not jump, implementing this instruction
    emit_load_bool(ACC, BoolConst(FALSE), s);
    emit_label_def(last_lable, s);
}

void no_expr_class::code(ostream &s, CgenClassTable& cgen_class) {

}

void object_class::code(ostream &s, CgenClassTable& cgen_class) {
    if (name == self) {
        s << "\t# the lable is self, so we load s0 to a0, s0 store the address of self" << endl;
        emit_move(ACC, SELF, s);
        return;
    }
    auto location = cgen_class.getSymbolToLoc().lookUp(name);
    if (location.base_loc == BASE_LOC_TYPE::SELF_) {
        s << "\t# here we use self as pointer" << endl;
        emit_load(ACC, location.offset, SELF, s);
    }
    else {
        s << "\t# here we use fp as pointer" << endl;
        emit_load(ACC, location.offset, FP, s);
    }
}


// cool-tree.h end
