## 三、 Framing程序
我们需要做一个有边框的greeting，最容易想到的策略是：读入用户名字，根据用户的名字构造greeting(std::string)，根据greeting构造边框，最后一次输出各行。  
### 1. greeting变量的定义：
`const std::greeting="Hello"+name+"!";`  
这句代码需要明确三点：  
&emsp;1.我们可以在定义一个变量的同时对其赋值。这种操作称为初始化。如果变量类型和所赋的value类型不同（实际上，std::string和string literal就不是同一种类型），the implementation会将初始值类型转换成变量的类型。  
&emsp;2.这条语句使用 + operator 来进行字符串的连接（concatenate）,包括string变量+string literal，或者两个string变量，**但不能是两个字符串字面量**。这也印证了CH 0中提到的，同一个运算符会因为operand不同而具有不同的行为，这种现象称为运算符重载-overloading。  
&emsp;3.const修饰词：在定义一个变量时添加const会确保该变量的值不会改变。值得注意的是，如果我们定义一个变量是const，我们一定要当时就对其进行初始化，不然以后就没有机会了。显然我们不能定义变量name是const，因为默认初始化name为empty string，而后续我们一定会读入字符串将其存储到name中。  
<br>
补充：一个operator的行为会重载，但可以肯定的是一个运算符的关联性是不变的。
***
### 2.边框的构造
`std::string spaces(greeting.size(),' ');`  
&emsp;观察这条语句，当我们用赋值符号=来对一个变量进行初始化，我们明确指明了我们想要的值，当我们在变量名后面使用括号，而且括号里面有表达式（也可以是多个表达式用comma分隔）时，意思是我们要the implementation根据括号里的表达式construct一个变量，具体构建的方法完全取决于变量的type。  
&emsp;括号里的第一个表达式：`greeting.size()`  //这是调用成员函数的例子。  
&emsp;括号里第二个表达式：`' '`// character literal。字符字面量完全区别于字符串字面量，前者是C++core language中定义的类型，后者的类型远比前者复杂（将在&sect;10.2中介绍）。  
&emsp;综上，括号里的两个表达式的计算结果分别是一个正整数（n）和一个字符字面量('c')。根据std::string类型的定义，这会构造出一个包含n个'c'的字符串。

