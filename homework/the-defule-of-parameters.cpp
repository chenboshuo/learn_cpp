/**
 * 面向对象程序设计上机练习三（有默认参数的函数）
时间限制: 1 Sec  内存限制: 128 MB
提交: 40  解决: 31
[提交] [状态] [讨论版] [命题人:admin]
题目描述
利用默认参数的函数实现求2个或3个整数的最大值。

输入
输入3个int型整数。

输出
输出第1、2个整数及其最大值；
输出第1、2、3个整数及其最大值。

样例输入
88 66 99

样例输出
88 66 88
88 66 99 99
 */
#include <iostream>
#include <limits.h>
int max(int a, int b, int c = INT_MIN){
  int _ = a;
  if (a > _) {
    _ = a;
  }
  if (b > _){
    _ =b;
  }
  if (c > _) {
    _ = c;
  }
  return _;
}
int main(int argc, char const *argv[]) {

  int b1,b2,b3;
  std::cin >> b1 >> b2 >> b3;
  std::cout << b1 << " "<< b2 << " " <<max(b1,b2) << '\n';
  std::cout << b1 << " "<< b2 << " "<< b3 <<" " <<max(b1,b2,b3) << '\n';
  return 0;
}
