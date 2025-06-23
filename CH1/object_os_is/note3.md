## details
&emsp;一、类似char类型是一个bulit-in type，wchar_t类型也是一个在core language中定义的类型，目的是通过占用更多字节（两个byte）从而表格更多字符或语言。  
&emsp;二、std::string类型实在标准库中定义的，要用预编译指令`#include<string>`来包含。  
&emsp;三、 关于std::cout和std::ostream的关系  
std::cout的类型确实是std::ostream，但为什么前者看上去比后者封装性更高、更复杂，看上去像是后者的子类呢？这是因为std::cout实际上是已经被创造完的全局对象。根据std::ostream类的设计，对应的实体应该有连接到某缓冲区的功能，而std::cout已经被连接到某一具体的缓冲区上了。就像是ostream类描述了一个水龙头类，而cout是一个已经具体应用在花园水龙头、用来浇花的实体水龙头。std::cout和std::cin分别应用<<或者>>运算符时，由于运算符本身是左关联的，而且表达式返回值是std::cout和std::cin，这种设计允许了链式输出/输入。  
## exercises
1-0 本章之前已经完成  
1-1 +operator可以连接两个std::string或者std::string + string literal，但是不可以连接两个字符串字面量。实际上两个字符串字面量要想连接可以直接用whitespace分隔开即可。  
1-2根据+operator的左关联性，首先计算两个string literal相加，这是错误的。  
1-3和1-4 都是正确的，{}块作用域内有效，执行到块结束后局部变量被摧毁；内部新的块状作用域在其内部可以将外部重名变量覆盖，可以看成是两个变量。  
1-5 错误，出了内部的块状作用域后变量x已经不存在。  
