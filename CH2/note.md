# Looping and counting
通过重新写一个更加灵活的framing greeting程序，学习C++中的四则运算(arithmetic)、循环、条件，并学习loop invariants的概念  
## 问题描述
&emsp;CH1中的framing程序的缺点：每一行输出都对应一段代码，并且有一个变量与之对应。这样即使我们只需要输出有一点点改动，都需要我们重写代码-->灵活性不好。  
&emsp;我们现在要分别地生成每一个输出的字符（除了greeting本身）来获得灵活性。因为一旦输出完成，我们没必要继续用变量存储了。
## 如何正确写一个while 或者 如何读懂一个while
&emsp;两个基本常识：  
1. while结束时，它的判断语句一定是false  
2. 循环不变量：一个带有含义的变量，要求其在while第一次检查条件之前是成立的，并且在达到while body末尾时是成立的。这种情况下可以保证每次循环后循环不变量的指示都是正确成立的，即使是跳出循环时，同样成立。
## writing a row
`const std::string::size_type cols=greeting.size()+pad*2+2;`  
之前提过两个**scopes**，分别是namespace和block，此处遇到了第三种作用域：class有自己的scope。size_type就是std::string类下的数据类型。