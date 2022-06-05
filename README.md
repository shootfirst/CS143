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























