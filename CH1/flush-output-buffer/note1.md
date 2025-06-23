# CH 2 Working with strings 
## 一、对象和变量
对象object是计算机中一块带有类型type的内存，而变量是一个有名字的对象。有时我们并不希望一个对象有名字（ch 3.2.2,&emsp;4.2.3,&emsp;10.6.1）  
一个对象的类型决定了可以施加到该对象身上的operations，这些操作也称为interfaces（接口）。定义某种类型的对象（有名字的对象是变量）意味着我们可以对该对象进行与其类型相应的操作，初始化就是这些操作之一。标准库要求std::string类型的对象一定会被初始化，即使用户不进行，系统会自行将其初始化成empty string。  
## 二、标准输入
read-读入-input  
write-写出-output 
语句：`std::cin >> name;`  // 从标准输入（键盘）读入一个字符串并将其存储到name中。具体地，这条语句首先丢弃whitespace characters(包括空格、tab、backspace、回车)，之后读入内容并存到name中，直到再次遇到whitespace或者EOF。  
如果将这条语句理解成表达式，计算结果是左侧的operand，副作用除了将所读内容存储到name以外，还有将“要求用户输入的提示” 显示到屏幕上——>引起fulsh的副作用。  
实际上，std::cout会用buffer将输入内容暂存，以优化标准输出操作符的执行： 没有这种暂存机制的话，系统不管到底有多少字符要输出（显示）都会花费时间去立刻执行当前的输出命令。而有了buffer的暂存机制，系统会积累输出到一定量，必要时通过flush才一次性进行输出。当buffer满了、执行std::cin操作或者我们特意要执行flush，系统会发生flush-->例如输出std::endl相当于我们让系统flush。我们需要在合适的时机对输出的buffer进行flush，否则在程序需要花很长时间去运行时，std::cout语句执行的时刻和我们实际看到输出的时刻有可能会隔很远。

