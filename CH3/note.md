# Working with batches of data
存储一个学生的考试成绩和作业成绩，并得出一个最终成绩。
1. std::setprecision(n)和std::endl类似，是一个manipulator(manipulate the stream)，控制cout的输出是n位有效数字。setpricision在<iomanip>中定义。而std::endl同样做为manipulator却在<iostream>中定义，是因为它太常用了。
2. cout.precision()是一个member method，返回一个整数代表stream输出浮点数的有效数字，这个整数最好用<ios>头文件中的std::streamsize类型的变量承装。实际上cout.pricision()成员函数除了返回当前精度，如果给定参数n，同时也会设定之后的精度，但是为了程序的精简，使用setpricision()这个manipulator更好。
3. 我们需要给定变量初始值，不然变量的初始值会依靠变量的种类决定，例如std::string类型会默认初始化成empty string。而局部的built-in变量没有这种initializer，这种变量若程序员不初始化就会是undefined状态。
4. 使用cin>>x做为condition：如果输入（read）的request成功了，条件判断为true。`if(cin>>x)`<==>`cin>>x; if(cin)`。一旦cin读入失败，其内部的状态会改变，之后的所有read requst都会失败，直到我们reset cin
---
1. 定义std::vector使用了一个语言特性：template classes，在&sect;11中我们会学习如何定义一个template class 。vecotr是一个容器，vector<double>是一个type 。
2. 目前可以发现，编辑器默认，关键字用紫色、变量或对象用淡蓝色、函数或manipulator用黄色、library defined type名用青绿色、built-in type用深蓝色
3. sort()标准库函数，在<algorithm>中定义，重排容器中的元素（默认非降序排序）
4. 调用vector中元素的方法：1.用index检索，第一个元素的index为0，最后一个元素的index是size-1 。
5. 一个unsigned类型和signed类型组成表达式，最终会转换成unsigned。例如homewor.size()-100，即使前者小于100最终结果也是非负的。
6. 不要再头文件中使用using，不然会有命名空间污染！