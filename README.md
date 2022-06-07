# CS143
斯坦福2022春编译原理实验

cs143官方网站：http://web.stanford.edu/class/cs143/


## The Cool Reference Manual翻译
 
目录
+ 1 介绍

+ 2 开始

+ 3 类
  - 3.1 特点
  - 3.2 继承

+ 4 类型
  - 4.1 SELF类型
  - 4.2 类型检查 
  
+ 5 属性
  - 5.1 Void 
  
+ 6方法

+ 7 表达式
  - 7.1 常量
  - 7.2 标识符
  - 7.3 赋值 
  - 7.4 方法调用
  - 7.5 条件表达式 
  - 7.6 循环
  - 7.7 代码块
  - 7.8 Let 
  - 7.9 Case 
  - 7.10 New 
  - 7.11 Isvoid 
  - 7.12 算数和比较运算符

+ 8 基本类 13
  - 8.1 Object 
  - 8.2 IO
  - 8.3 Int 
  - 8.4 String 
  - 8.5 Bool
  
+ 9 Main 15

+ 10 词法结构 15
  - 10.1 整数、标识符以及特殊符号 
  - 10.2 Strings 
  - 10.3 注释
  - 10.4 关键字 
  - 10.5 空白处 
  
+ 11 Cool 语法16
  - 11.1 优先级 
  
+ 12 类型规则 16
  - 12.1 类型环境
  - 12.2 类型检查规则 
  
+ 13 操作语义 22
  - 13.1 Environment and the Store 
  - 13.2 Syntax for Cool Objects
  - 13.3 Class definitions 
  - 13.4 Operational Rules 
  
+ 14 Acknowledgements 30

### 1 介绍

这个手册介绍了cool编程语言，Classroom Object-Oriented Language，即面向对象的教学语言。cool是一个可以经过合理努力单季度或者一个学期完成它编译器的小型语言。cool保留了许多现代面向对象语言的特点，例如对象，静态类型以及自动内存管理。
cool编程是类的集合，一个类封装了变量和方法。类的示例是对象，在cool语言中，类和类型是确定的，每一个类定义了一个类型。类允许程序员去定义新的类型和特定于这些类的过程或者方法。继承允许新的类去继承已经存在类。
cool是一个表达式语言。cool是由表达式构建的语言，并且所有的表达式有一个值和类型。cool是类型安全的。过程被保证应用于正确的类型的数据。虽然静态类型对cool编程有很强的要求，它保证cool程序运行时不会发生运行时类型错误。
这个手册分为正式和非正式的部分。对于一个简短非正式的预览，第一部分足够了。正式描述从？节开始。


### 2 开始

这个编程任务





## 实验解析

此处的实验一与官网不同，官网是直接开始做词法分析，而本实验一是熟悉cool语言。cool语言是用于教学的面向对象语言，Classroom Oriented Object Language。注意，在做实验之前，一定要熟悉好
cool语言，毕竟你是要开发cool语言的编译器的，不熟悉cool语言语法怎么写编译器呢嘻嘻。主要是对cool_manual.pdf的阅读，私以为看1-12章即可。注意一定要熟悉.

### PA1

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

### PA2

从实验二开始就正式进入编写cool语言编译器了。实验二是词法分析，使用工具flex。故在开始编写程序之前一定要熟悉好flex的使用。感觉官网给的flex看上去有点晦涩，我又找了个博客：
https://www.cxyzjd.com/article/weixin_44007632/108666375

在此记录flex的学习笔记先：

flex语法分为三个部分（可以省略这些部分，不一定全部都有）：

definition
%%
rules
%%
user code

下面对三个部分进行分析

definition部分主要是两部分：第一部分是使用c语言代码进行预处理，比如引入头文件、定义宏。语法完全同c语言。定义于%{ %}包裹的部分。第二部分可以进行flex自己的定义，如一些正则表达式的定义
如： IDENTIFIER [a-zA-Z_]+[a-zA-Z0-9_]*

rules部分是对匹配相应的字符串进行相应操作，没有被匹配的原封不动写入输出文件，被匹配但是不采取任何动作的被丢弃。匹配有两个原则，一是尽可能匹配长的字符串；二是同等长度匹配，前面的优先被
匹配。写法如下：{正则表达式或定义}		{ 动作 }

user code部分是相应代码，这部分由于实验用不到，暂时省略

lex函数与变量：

yyin *FIlE类型，指向现在正在解析的当前文件
yyout *FILE类型，指向输出文件，在缺省情况下，二者指向标准输入输出
yytext *char类型，匹配模式的文本存储在这里面，注意使用时使用strcpy复制之，别直接使用
yyleng i给出匹配模式的长度
yylineno 给出当前的行数

yylex() 调用此函数开始分析，执行rules相关的匹配
 























