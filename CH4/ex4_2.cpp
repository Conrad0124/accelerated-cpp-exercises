#include <iomanip> // 为了使用 setw
#include <iostream>
#include <string>
using namespace std;

int main() {
    for (int i = 1; i <= 100; ++i) {
        string s_i = to_string(i);
        string::size_type l = s_i.size();
        cout << i << setw(10 - l) << i * i << endl;
    }
    return 0;
}