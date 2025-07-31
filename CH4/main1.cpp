#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::istream;
using std::setprecision;
using std::streamsize;
using std::string;
using std::vector;
double grade(double midterm, double final, double homework) {
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}
double median(vector<double> vec) {
    // vec_sz is a local type name
    typedef vector<double>::size_type vec_sz;
    vec_sz size = vec.size();
    if (size == 0)
        // a more general way of complaining
        throw domain_error("median of an empty vector");
    sort(vec.begin(), vec.end());
    vec_sz mid = size / 2;
    return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}
// 函数重载，本函数可能抛出异常。
double grade(double midterm, double final, const vector<double> &hw) {
    if (hw.size() == 0)
        throw domain_error("student has done no howework");
    return grade(midterm, final, median(hw));
}
// reading homework grades
istream &read_hw(istream &in, vector<double> &hw) {
    if (in) {
        hw.clear();
        double x;
        while (in >> x)
            hw.push_back(x);
        /* 不论while因为什么结束，都需要将cin“拨正” ，
         * 不要在if外面将其拨正，不然返回值将失去意义 */
        in.clear();
    }
    return in;
}
struct Student_info {
    string name;
    double midterm, final;
    vector<double> homework;
};
istream &read(istream &is, Student_info &s) {
    is >> s.name >> s.midterm >> s.final;
    read_hw(is, s.homework);
    return is;
}
double grade(const Student_info &s) {
    return grade(s.midterm, s.final, s.homework);
}
// predicate
bool compare(const Student_info &x, const Student_info &y) {
    return x.name < y.name;
}
int main() {
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;
    cout << "please enter your midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;
    cout << "Enter all your homework grades, "
            "followed by end-of-file: ";
    vector<double> homework;
    read_hw(cin, homework);
    try {
        double final_grade = grade(midterm, final, homework);
        streamsize prec = cout.precision();
        cout << "Your final grade is " << setprecision(3)
             << final_grade << setprecision(prec) << endl;
    } catch (domain_error) {
        cout << endl
             << "You must enter your grades. "
                "Please try again. "
             << endl;
        return 1;
    }
    return 0;
}