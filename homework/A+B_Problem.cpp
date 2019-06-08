/**
 * A + B Problem
  时间限制: 1 Sec  内存限制: 128 MB
  提交: 650  解决: 343
  [提交] [状态] [讨论版] [命题人:外部导入]
  题目描述

  Calculate A + B.

  输入

  Each line will contain two integers A and B. Process to end of file.

  输出

  For each case, output A + B in one line.

  样例输入

  1 1
  2 2
  3 3

  样例输出

  2
  4
  6
 */
#include <iostream>
int main(int argc, char const *argv[]) {
  int a, b;
  while (std::cin >> a >> b) { std::cout << a + b << '\n'; }
  return 0;
}
