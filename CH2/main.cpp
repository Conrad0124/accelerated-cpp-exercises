#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main() {
    cout << "Please enter your first name:";
    string name;
    cin >> name;
    const string greeting = "Hello," + name + "!";
    const int pad = 2;
    const int rows = pad * 2 + 3;
    const string::size_type cols = greeting.size() + pad * 2 + 2;
    cout << endl;
    // 目前写下了r行
    int r = 0;
    // 目前写了c列
    while (r != rows) {
        string::size_type c = 0;
        while (c != cols) {
            if (r == pad + 1 && c == pad + 1) {
                cout << greeting;
                c += greeting.size();
            } else {
                if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1) {
                    cout << "*";
                } else
                    cout << " ";
                ++c;
            }
        }
        cout << endl;
        ++r;
    }
}