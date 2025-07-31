#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
istream &read_hw(istream &, vector<double> &hw);
int main() {
    vector<double> homework;
    read_hw(cin, homework);
    typedef vector<double>::size_type vec_sz;
    vec_sz size = homework.size();
    streamsize prec = cout.precision();
    for (int i = 0; i < size; i++) {
        cout << setprecision(4) << homework[i] << " ";
    }
    cout << setprecision(prec) << endl;
    return 0;
}
istream &read_hw(istream &in, vector<double> &hw) {
    if (in) {
        hw.clear();
        double x;
        while (in >> x) {
            hw.push_back(x);
        }
        in.clear();
    }
    return in;
}