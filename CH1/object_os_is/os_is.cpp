#include<iostream>
#include<string>
int main(){
    std::ostream &os=std::cout;
    std::istream &is=std::cin;
    std::string z(8,'*');
    std::string t=z;
    os<<t<<std::endl;
    std::string name;
    is>>name;
    os<<"hello "+name+" !"<<std::endl;
    return 0;
}
