#include<iostream>
#include<string>
int main(){
    // ask for the person's name
    std::cout<<"Please enter your first name:";
    // read the name
    std::string name;
    // 该表达式除了计算结果、读入string并存储到name变量中（副作用），
    // 还有flush的副作用
    std::cin>>name;
    // write the name
    std::cout<<"Hello,"<<name<<"!"<<std::endl;// std::endl有强制flush的作用
    return 0;
}