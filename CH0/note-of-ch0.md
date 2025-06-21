# Preface and ch0
AcceleratedCpp是关于C++98的教材，它在两方面不同于其他教材:  
1.直接使用高阶抽象；  
2.以解决问题为编程学习的导向，而不是语言特性本身。  
有选择性的忽略abstraction的一部分，仅关注与任务相关的部分。毕竟抽象的特性众多，好的程序员需要懂得哪些要关注、哪些要忽略。
## structure of this book
part 1：  
直接使用标准库的高阶抽象（如何使用standar library）-->ch 1:7  
part 2：  
讲解如何定义自己的抽象-->ch 8:end  
## ch0 getting started
（HelloWorld程序为例）   
### 1.预编译指令：  
C++语言中，许多基本功能都是在standard library中实现的而不是在core language本身中定义的。前者需要明确的声明（#include\<iostream>），声明后才能使用相关的facilities，而后者随时可用（例如 int）。  
iostream支持顺序/流型的输入输出。  
### 2.main函数：  
与.exe文件一一对应。运行一个.exe文件要从那个唯一的main为入口，反过来每一个项目中可以有许多.cpp文件，但为了链接成一个.exe，所有参与链接的文件中只能有一个main函数。具体来说，链接器收集好全部的编译好的代码，并找到那唯一的main，之后围绕它构建成一个完整、**独立**的.exe。  
补充：1.某些项目不是为了独立运行，而是以配件或功能模块的形式被其他程序调用。这种项目称之为：库（library），例如.dll和.lib  。2.ch 10.4中介绍main函数的参数。  
### 3.使用标准库输出
std::cout << "HelloWorld! << std::endl;  
<<&ensp;是**标准库输出操作符**  
std::cout&ensp;是**标准输出流**，是C++定义的一个facility用来输出。  
### 4.补充
1.**表达式（expression）**：要求“C++的implementation”（实现，主要是编译器及其配套的标准库）去计算。计算必须要有计算结果，但有时计算会附带”副作用“。有时副作用才是真正我们想要的。  
expression要有operator和operand。operand一定有type，C++的type有两种，一种是本身内置的类型，另一种是core language以外定义的类型。例如int（core language）、std::ostream（standard library）。  操作符的行为取决于其操作数的type。
操作符的关联性：以left-associative为例，一个表达式多次出现某一个操作符（<<），该操作符让其左侧操作数占整个表达式尽可能高的比例，右侧操作数尽可能占少的比例。  
(ste::cout <<"Hello" )<< std::endl; // 这个表达式，根据操作符的关联性可以分清每个操作符的操作数。前一部分的含义是，（根据操作数的type）将右侧操作数的内容显示到左操作数指向的stream上，将左侧操作数做为该表达式的计算结果。后一个操作符的左右操作数的类型分别是：std::ostream和manipulator。这种情况下，标准库输出操作符将右侧操作数代表的操作施加到左操作数上，并将左操作数返回。综上，整个表达式的返回值是std：：cout，副作用是输出"Hello"(string literal)，并换行。可见，<<&ensp;的左关联性以及其返回值实现了链式输出功能。    
表达式+；构成express statement，含义是丢弃其返回值，只要副作用。
2.**作用域**scope
C++有不同种类的scope，目前遇到的其中两个分别是：namespace（例如qualified name std::cout）和 curly braces  
3.**string literal**   
string literal has a mysterious type that we shall not even discuss until ch 10.2.  
每个字符串字面量要整体地在一行出现。
