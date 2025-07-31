# Organizing programs and data
要想解决大规模问题，我们必须将程序拆分成多个独立的、被命名的部分，否则程序会变得unmanageable ! --> 最基本的工具就是函数和数据结构，而C++允许二者结合，称为class 。  
使用functions and data structures来组织我们的计算之后，还需将程序分离到不同files中，从而实现各个.cpp文件分别compile（编译之后组合到一起）  
## organizing our computations
&emsp;无论何时我们要在**多个地方**进行计算，都应考虑在函数中开展。一是考虑复用性，二是方便以后程序的功能修改。还有一个微妙的好处是：一个函数是根据其功能命名的，有了名字后我们可以更多的考虑what it dose，而不是how it works，方便我们更加抽象地思考。  
&emsp;对于程序运行可能遇到的异常情况，很多时候我们不知道程序的使用者是谁（用户、开发者）也不知道使用者的目的，所以我们需要一个more general way of complaining--> throwing an exception 。 当一个程序抛出一个异常，程序就会停止并将一个exception object(该对象包含了异常信息)传递给另一块程序，以供caller使用。exception object 携带的异常信息，最朴素的情况就是简单的事实——“一个异常发生了”  
&emsp;std::domain_error 是一个标准库定义类型(在`<stdexcept>`中定义)，用来表示一个函数的参数超出了其定义域。我们创建一个domain_error的对象时，我们可以给它一个string来描述异常信息。catch到该异常的程序可以使用该string进行诊断。  
&emsp; `const vector<double>&` 类型：reference to vector of const double， 例如：  
```
vecotr<double> homework;
vector<double> &hw=homework// saying hw is a synonym for homework
```
常识：一个reference类型的参数，如果不加const修饰，通常暗示将对该参数进行改变。  
### Reading homework grades
这是本书第一个难点 ———— 将homework grades 读入一个vector  
该函数需要返回两个值：homework 向量 和 读入请求是否成功的indication 。  
在C++语言中我们无法直接实现函数返回多个值，但存在一个间接方法：给该函数一个引用类参数，通过该参数对需要改变的object进行操作。这种方法在**需要读入数据** 的函数中很常见。框架是：  
```
istream& read_hw(istream& in,vector<double>& hw){
    // we must fill this part
    return in;
}
```
观察上程序可以发现，两个引用类参数没有加const关键字修饰，这暗示我们会对参数进行修改。如果我们这样使用：  
```
vector<double> homework;
read_hw(cin,homeword);
```
在函数中存在cin和homework的nonconst引用，这种情况下要求我们传入read_hw()的参数是个 **左值lvalue** 我们希望对该参数所引用的对象进行修改，所以实际传递的参数不可以是暂时性的对象（**must be nontemporary objects**），例如表达式（表达式计算完就消失了，不会长时间占有一块内存）。左值可以是一个变量、一个引用或者是一个返回引用的函数的结果。e.g.:sum/count 不是lvalue!  
cin做为一个istream类型的对象，本质上是一个用来存储各种关于我们输入的信息的数据结构，逻辑上，我们使用cin进行输入时，cin的值会改变，这是很自然的。  
另一方面read_hw()函数以引用的方式输入cin，又以引用的方式返回cin。这表明使用者可以： `if(read_hw(cin,homework))` <==> `read_hw(cin,homeword);if(cin)`  
之前的输入方法：`while(cin>>x){hw.push_back(x)}`并不适用。有两点原因：这是一个用来向一个向量中读入数据的函数，这个函数供使用者使用，hw这个参数是使用者定义的，这在函数之外，我们的函数在被调用的时候并不知道第二个参数是什么状态，很可能在被调用时该参数不是空的 --> 解决方法：使用hw.clear()成员函数。第二点原因：这个while会在遇到EOF或者遇到不能做为grade的数据类型时候停下来。前者可能在我们的一次input request失败时发生，而我们期待其仅仅在我们成功输入全部数据时发生，这具有误导性；后者一旦发生，cin的状态会编程 failure state，这导致后续的所有input request都会失败。--> 解决方法：in.clear()复位cin的状态。完整的read_hw()程序:  
```
istream& read_hw(istream& in,vector<double>& hw){
    // 此处的if语句代表：如果in本身是failure状态时，不进行读入工作，直接return 。
    if(in){
        hw.clear();// hw是用户自行传入的，我们要将其清空再工作
        double x;
        while(in>>x)
            hw.push_back(x);
        in.clear();// 如果read操作失败直接将其纠正回工作状态
    }
    return in;
}
```
**read_hw()函数和简答的while(cin>>x){}相比，是一个健壮、灵活、可复用的代码。这体现在**    
1. 封装性与复用性：将读入一个向量这项工作完整地封装成了一个独立单元，可以重复调用而且方便以后代码功能升级。
2. 传入的参数是istream &，而不是特指cin，这大大增强了灵活性。除了处理标准输入，还适用于文件流读入、字符串流读入。
3. 状态管理：if(cin){/*...*/}首先检查输入流的状态，输入流状态出错直接跳过所有操作；in.clear()也同样起到状态检查（纠正）的作用。
4. 对输入参数的检查：hw.clear()确保函数行为是可预测的。
5. 返回值为istream &类型，直接返回in，这样支持状态检查和链式调用。read_hw(read(cin,homework1),homework2);
---
### 总结
&emsp;截至目前，我们定义函数使用过三种参数：  
1. 传值参数：例如median()函数，尽管效率不高，需要对homework 这个向量进行拷贝，不管这个向量规模多大，但它保证我们不会改变这个向量。  
2. const vector<double> &hw：使用const的引用类型，既保证了效率又确保我们不会对传入参数进行修改。median()函数没使用这种参数是因为其内部要用到std::sort() 。  
3. vector<double> &hw: nonconst reference暗示我们会对传入参数进行modify。
4. 重复一遍：Arguments that correspond to nonconst reference parameters must be lvalues—
---
try{}catch(error){} statement:  
首先执行try后面的语句块，如果其中throw了一个异常，立刻停止，紧接着执行catch中的内容。如果try语句块中没有异常，则完全跳过catch 。 这里需要注意，如果try发生了异常，其语句块中follow该异常的部分会被跳过。注意这里的follow是指时间上follow 异常，而不是文本上follow该异常。例如：  
```
try{
    streamsize prec=cout.precision();
    cout<<"Your final grade is "<<setprecision(3)
    <<grade(midterm,final,homework)<<setprecision(prec);
}
```
在调用grade()函数是可能抛出异常，cout表达式虽然会从左到右计算`<<operator`但implementation并没有规定每个`<<operator`先算左侧的operand还是右侧的operand，这导致setprecision(3)并不一定会在grade()之前执行，甚至“Your final grade is "字符串都有可能在grade()之后执行。所以一个语句，应避免有超过一个的副作用 --> `double grade(double,double,vector<double>& )`本身有一个副作用（抛出异常）所以不将其放入cout表达式中。  
## Organizing data
之前的内容是组织我们的计算，将各个功能封装成可复用的函数。但形成的main1.cpp只可以进行一个同学的成绩计算。我们现在需要合理组织、管理数据，实现计算一整个班级同学的成绩。  
double grade(const Student_info &s)函数调用了double grade(double,double,const vector<double> &hw)函数，该函数可能抛出异常，然而我们在本函数中并没有尝试抓住该异常，这样异常会直接传给函数调用者，这是好的，因为调用者比程序员更清楚如何处理没有做作业的异常。  

头文件：  
都文件应该使用全套限定名（例如std::string::size_type），坚决避免使用using
此外，最好源文件中包含一次自己的头文件，这样可以让编译器帮我们检查函数定义和函数声明的一致性。

