# CS143
斯坦福2022春编译原理实验

cs143官方网站：http://web.stanford.edu/class/cs143/

此处的实验一与官网不同，官网是直接开始做词法分析，而本实验一是熟悉cool语言。cool语言是用于教学的面向对象语言，Classroom Oriented Object Language。注意，在做实验之前，一定要熟悉好
cool语言，毕竟你是要开发cool语言的编译器的，不熟悉cool语言语法怎么写编译器呢嘻嘻。主要是对cool_manual.pdf的阅读，私以为看1-12章即可。注意一定要熟悉.

## PA1

实验一是写一个栈机器，目的是熟悉cool语言。我觉得关键在三点。

一是熟悉题目要求：如图

![](PA1.png)

二是熟悉cool语法：

由于cool编译器非常不友好，报错很不明显。所有必须先熟悉好cool语法才能写下去。我就是一开始太急了，没有完全熟悉就开始写（老毛病了）。我犯错：一没有明白对象的字段全部是私有的，在外部不
能直接调用，manual原文： Attributes are visible throughout a class in which they are declared or inherited,二不知道不能对self进行赋值，self是不能修改的，原文：The 
identifier self may be referenced, but it is an error to assign to self or to bind self in a let, acase, or as a formal parameter. It is also illegal to have 
attributes named self.二者均可以用设立setter和getter方法去破解。熟悉了语法，做起来还是很轻松的。

三是是注意atoi.cl文件的使用，可以调用A2I类相关接口实现String和Int之间的转化。指导书原文：If you wish, youmay use the classes defined in atoi.cl

注意以上三点，实验一还是很轻松的

## PA2

从实验二开始就正式进入编写cool语言编译器了。实验二是词法分析，使用工具flex。

首先说明下实验二需要阅读学习的部分：

    - cool-manual 第10章 lexical structure

    - flex-manual，重点是三大模块的前两个结构规范，flex函数与变量

    - PA2.pdf

需要修改的文件：cool.flex

官方评测脚本：https://courses.edx.org/assets/courseware/v1/2aa4dec0c84ec3a8d91e0c1d8814452b/asset-v1:StanfordOnline+SOE.YCSCS1+1T2020+type@asset+block/pa1-grading.pl

评测步骤：

    - make clean

    - make lexer

    - perl pa1-grading.pl


词法分析大概可以分为一下几个部分：

    - 单行注释
    - 多行注释
    - 字符串常量
    - 标识符
    - 运算符号
    - 数字常量
    - 布尔常量
    - 空白符号
    - 其他

除了前三个，后面较为简单。注意运算符号好像没有>，这是通过实验给的lexer测出来的，空白符这不要漏掉空格。其余均可在指导书中获取信息。

现在解析前三个如何词法分析。这三个分别为single_line,comment,string状态。

若遇到--则进入single_line，结束标志为换行符。

若遇到（* 则进入comment，在多行注释中需要注意，若遇到eof，则必须转入initial状态，否则会陷入无限循环。其次便是遇到*）则需要退出多行注释状态，这点实现稍微复杂，要确保*）不会被匹配称为
comment的一部分。

若遇到"则进入string，主要麻烦在转义字符的匹配。首先对于\\、\n、\0、\"四个符号之外可以随意匹配。遇到eof则需要转入initial状态。遇到\\则分情况讨论，若接下来是\n，则需要行数++，其余只
需继续匹配即可。遇到\n则返回error。遇到"则识别结束，开始对字符串的转移字符处理。

好了这是我一开始的做法，处理完good.cl和bad.cl的输出与coolc的输出无区别，可是这两个有很多地方没有测试到位。后面发现还有官方评测脚本，于是下载下来评分，只有30几分，出了好多错误，于是跟
着相关测试脚本一个个去修改，主要是一下几个问题：

多行注释出错：无法处理嵌套注释，根据提示修改，在<INITIAL,COMMENT>两种状态下遇到（* 时将嵌套深度++。遇到*）时将嵌套深度--，嵌套深度为全局静态变量，初始值为0

无法识别出true与false：开始以为自己对true与false的词法格式没有看明白，最后才发现是识别顺序的问题，最后把识别顺序改为keywords true and false，然后才是其他的，必须要确保true 和
false的识别在标识符前面。

空字符串出错：这主要是没有阅读清楚题目的意思，如果字符串中出现null，必须坚持识别完整个字符串，而不是遇到null就报错，从下一个又继续开始识别。所以遇到\0照样接收，只是最后遇到"结束时扫
描整个字符串，遇到\0则整个识别为error就行。

eof字符串出错：遇到elf时还需注意yyrestart(yyin)，看flex文档说明（做之前一定要看明白flex-manual，里面很详细很全！！！）：

If the scanner reaches an end-of-file, subsequent calls are undefined unless either yyin is pointed at a new input file (in which case scanning continues from that 
file), or `yyrestart()' is called. `yyrestart()' takes one argument, a `FILE *' pointer (which can be nil, if you've set up YY_INPUT to scan from a source other than 
yyin), and initializes yyin for scanning from that file. Essentially there is no difference between just assigning yyin to a new input file or using `yyrestart()' to 
do so; the latter is available for compatibility with previous versions of flex, and because it can be used to switch input files in the middle of scanning. It can 
also be used to throw away the current input buffer, by calling it with an argument of yyin; but better is to use YY_FLUSH_BUFFER (see above). Note that `yyrestart()' 
does not reset the start condition to INITIAL (see Start Conditions, below).

还是有点疑惑，为什么comment遇到elf不加没事，string加yyrestart(yyin)才让我通过呢？这难道是评测脚本的问题？还是我有细节没有注意？以后研究。

最后是空字符的识别：应该是如下几个 \t\r\f\v\n，遇到\n注意换行，不要漏了空格！也是没有仔细阅读cool-manual 第10章 lexical structure。


## PA3

实验三是语法分析，使用bison，如果没有flex和bison的基础（比如我）可能得耽误不少时间去学习。

实验三需要阅读的部分：

    - PA3.pdf

    - bison-manual
    
    - cool-tour.pdf第六章（PA3有提及）
    
    - cool-manual 第11章和第12章最前面（不需阅读12.1）
    
要看的还是蛮多的，得仔细阅读，正好考验自己的英文阅读水平。

需要修改的文件：cool.y

官方评测脚本：https://courses.edx.org/asset-v1:StanfordOnline+SOE.YCSCS1+1T2020+type@asset+block@pa2-grading.pl

评测步骤：

make clean

make lexer

make parser

perl pa2-grading.pl


语法分析，在阅读完以上代码后，最主要还是对下面这张图，按此图来写基本上差不多的，当然也有一些小细节需要注意：


![](parser.png)

第一个是let的书写，由于let也存在递归结构，单独分出lettype可以更方便地去书写。

第二个是注意formal的expression和其他的expression是有区别的，它们直接是"，"隔开，我一开始一直没有找到这个区别，导致评分一直没有上去

最后就是错误处理，可以看cs144的视频关于语法分析错误处理部分，我的理解主要就是递归出现的地方，需要加上错误处理：class_list、feature_list、 exp_list、let四个地方


## PA4

实验四有点难，代码量加大。

首先说明一下需要仔细阅读的材料：

    - PA4.pdf
    
    - cool-manual 第12章
    
    - symtab.h与tree.h相关接口
    
需要修改的文件：cool-tree.h  semant.h  semant.cc(主要)



官方评测脚本：https://courses.edx.org/asset-v1:StanfordOnline+SOE.YCSCS1+1T2020+type@asset+block@pa2-grading.pl

    
下面说明一下思路：

实验要求：输入没有type的ast，输出有type的ast。即每个表达式都要有type的标记，同时还有检查是否有错误。原文：The semantic phaseshould correctly annotate ASTs with types and 
should work correctly with the coolc code generator.

错误的处理：PA4.pdf原文：You are expected to recoverfrom all errors except for ill-formed class hierarchies.故若第一次遍历出错，则直接结束语法制导翻译。其他错误则抛开此
小错误，从下一个继续开始。

关键数据结构1：ClassTable

添加两个unordered_map，一是inherit_map，存储类继承图；二是class_map，存储类名和类变量的对应关系。

关键数据结构2：Envmt（第二次遍历想到）

SymbolTable是符号表，定义在symtab.h，存储标识符的名称和类别，这是它的关键接口：enterscope()、exitscope()、addid(SYM s, DAT *i)、lookup(SYM s)、probe(SYM s)，一个ClassTable，
以及current_class构成了环境。


program_class类的semant方法是语法制导翻译的入口，是语法制导翻译的核心代码，以下所有都围绕此方法展开。


    + 首先semant方法中，实验给的代码调用了ClassTable的构造函数，传入的参数则是包括除了所有非基本类的所有类的链表classes。所以，我们必须在构造方法中将所有类加入到table中。

        * 在构造方法中，首先会调用基本类的初始化install_basic_classes()，此方法应该修改，方法最后调用调用add_class_to_classtable()，将5个基本类加入table。

        * 调用add_class_to_classtable()，然后将传入的classes链表中所有类加入table。
        
            - add_class_to_classtable()中，主要是对加入时的类进行一次检查，此次检查主要是三个判断：类名不能是SELF_TYPE；不能继承Str、Bool和Int三个基本类；类不能重复定义。PA4.pdf
              提到过：In addition, Cool has restrictions on inheriting from the basic classes (see the manual). It is also an error if class A inherits from class B but 
              class B is not defined. 为什么在这里对这三个进行检查，是因为这三个检查成本低，在加入时即可检查，而且检查条件不像检查继承图是否无环那样需要所有类都加入后才能检查。在满
              足上述三个条件后，将此class加入inherit_map和class_map中。若检查出错，则不能加入到table，注意我们的一开始写的错误检查原则。

    + 然后开始第一次遍历ast，主要是检查是否无环、是否未定义Main类，是否继承的类未被定义，这三个检查必须是所有类都被加入继承图，才能检查。可以通过一次遍历完成所有检查。
    
        * 无环检查主要是对哈希表的每一项，不停求其父节点，直到到达No_type，假如最后到达了自己，则有环。
        
    + 若第一次遍历出错则不能进行第二次ast遍历。第二次ast遍历更为复杂，主要是scope check和type check。需要用到环境，代表omc

    + 第一次遍历未出错，进行第二次遍历。首先是环境新建，传入之前class_table作为参数
    
    + 开始遍历classes里面的所有类
    
    + 首先进入到该类作用域
    
    + 对该类的所有属性进行收集gather_attribute()，放入SymbolTable符号表，因为属性在类中是全局的
    
        * gather_attribute()中，注意，首先应该将所有祖先的attrubite加入，这里使用递归。
        
        * 然后再加入自己类的，若发生重复定义，则报错，不将其加入table，继续处理其他属性。注意features中不仅有属性，还有方法，对于方法，我们不做任何处理。
        
    + 最后就是最核心，最关键的一步，调用此类的type_check()。首先总的说一下，每个cool-tree.h中的inode都有自己的type_check方法，对于expression的type_check，应该着重参考cs143课程或
      者cool-manual 第12章。注意到我们的主要目标就是给ast










































