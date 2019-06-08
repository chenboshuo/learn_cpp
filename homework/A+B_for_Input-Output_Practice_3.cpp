/**
 * A+B for Input-Output Practice (III)（利用while实现多组输入）
时间限制: 1 Sec  内存限制: 128 MB
提交: 522  解决: 333
[提交] [状态] [讨论版] [命题人:外部导入]
题目描述

Your task is to Calculate a + b.

输入

Input contains multiple test cases. Each test case contains a pair of integers a
and b, one pair of integers per line. A test case containing 0 0 terminates the
input and this test case is not to be processed.

输出

For each pair of input integers a and b you should output the sum of a and b in
one line, and with one line of output for each line in input.

样例输入

1 5
10 20
0 0

样例输出

6
30

 */
#include <iostream>
int main(int argc, char const *argv[]) {
  int a, b;
  while (1) {
    std::cin >> a >> b;
    if (a == 0 && b == 0) { break; }
    std::cout << a + b << '\n';
  }
  return 0;
}
