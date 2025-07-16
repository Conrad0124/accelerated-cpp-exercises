// average.cpp
#include <iostream>
#include <vector>
#include <windows.h>

// 功能：计算一个整数向量中所有正数的平均值
// Bug: `count` 变量的自增位置错误，导致分母包含了非正数。
double calculate_positive_average(const std::vector<int> &data) {
    long long sum = 0;
    int count = 0;

    for (int x : data) {
        if (x > 0) {
            sum += x;
        }
        // 错误！这行代码应该在上面的 if 语句块内部
        count++;
    }

    // 防止除以零
    if (count == 0) {
        return 0.0;
    }

    // 因为 `count` 是错的，所以这里的计算结果也是错的
    return static_cast<double>(sum) / count;
}

int main() {
    SetConsoleOutputCP(65001);
    std::vector<int> numbers = {10, -5, 20, 0, 15};
    std::cout << "本程序计算 {10, -5, 20, 0, 15} 中正数的平均值..." << std::endl;
    std::cout << "预期结果: (10 + 20 + 15) / 3 = 15" << std::endl;

    double avg = calculate_positive_average(numbers);

    std::cout << "实际计算结果: " << avg << std::endl;
    return 0;
}
/*
 * g++ -g average.cpp -o average.exe;
 * gdb ./average.exe// 进入gdb
 * list main;
 * break calculate_positive_average;
 * run
 * next
 * print sum
 * printf "sum is: %lld, count is:%d\n",sum,count;
 * print {(int)sum,(int)count}
 * display sum
 * undisplay<编号>
 * quit
 * 补充：
 * 命令 (缩写)                  使用场景
 * until <行号> (u)             在当前函数内向前快速跳跃，尤其适合跳出循环。
 * tbreak <位置> + c            最通用的跳转方法，可以跳到程序的任何地方。
 * finish                       从当前函数快速执行完毕并返回，用于“撤退”。
 * break...if...	            调试循环的终极武器，在特定条件下才中断。
 * step (s)(Step Into)          暂停在函数的第一行可执行代码处。
 */