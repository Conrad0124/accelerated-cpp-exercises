#include "Student_info.h"
#include "grade.h"
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::max;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;
int main() {
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;
    while (read(cin, record)) {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }
    sort(students.begin(), students.end(), compare);
    for (vector<Student_info>::size_type i = 0;
         i != students.size(); ++i) {
        cout << students[i].name
             // string()构造匿名对象
             << string(maxlen + 1 - students[i].name.size(), ' ');
        try {
            double final_grade = grade(students[i]);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade
                 << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
            // catch(domain_error)语句声明本块只对domain_error类型的exception感兴趣，
            // 如果try部分抛出该类型异常，直接在此处捕捉并用该异常初始化e。
            // 实际上最好使用catch(const domain_error &e)
        }
        cout << endl;
    }
    return 0;
}