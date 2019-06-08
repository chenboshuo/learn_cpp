/**
 * 问题 A: 面向对象程序设计上机练习四（变量引用）
时间限制: 1 Sec  内存限制: 128 MB
提交: 76  解决: 43
[提交] [状态] [讨论版] [命题人:admin]
题目描述
将变量的引用作为函数形参，实现2个int型数据交换。

输入
输入2个int型整数。

输出
输出2个整数交换前后的值。

样例输入
88 66

样例输出
88 66
66 88
 */
#include <iostream>
void swap(int &a, int &b) {
  int _;
  _ = a;
  a = b;
  b = _;
}
int main(int argc, char const *argv[]) {
  int a;
  int b;
  std::cin >> a >> b;
  std::cout << a << ' ' << b << '\n';
  swap(a, b);
  std::cout << a << ' ' << b << '\n';
  return 0;
}
