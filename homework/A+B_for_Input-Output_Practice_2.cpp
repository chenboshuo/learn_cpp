/**
问题 C: A+B for Input-Output Practice (II)
时间限制: 1 Sec  内存限制: 128 MB
提交: 509  解决: 315
[提交] [状态] [讨论版] [命题人:外部导入]
题目描述

Your task is to Calculate a + b.

输入

Input contains an integer N in the first line, and then N lines follow. Each line consists of a pair of integers a and b, separated by a space, one pair of integers per line.

输出

For each pair of input integers a and b you should output the sum of a and b in one line, and with one line of output for each line in input.

样例输入

2
1 5
10 20

样例输出

6
30
 */
#include <iostream>
int main(int argc, char const *argv[]) {
  int times, a, b;
  std::cin >> times;
  while (times--) {
    std::cin >> a >> b;
    std::cout << a + b << '\n';
  }
  return 0;
}
