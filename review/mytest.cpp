#include <iostream>
using namespace std;
int main() {
    int x = 1;
    const int &y = x;
    cout << y << endl;
    x = x + 1;
    cout << y << endl;
    return 0;
}