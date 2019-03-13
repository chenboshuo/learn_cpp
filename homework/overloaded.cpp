/**
 * 问题 C: 面向对象程序设计上机练习一（函数重载）
时间限制: 1 Sec  内存限制: 128 MB
提交: 18  解决: 16
[提交] [状态] [讨论版] [命题人:admin]
题目描述
利用数组和函数重载求5个数最大值（分别考虑整数、单精度、长整数的情况）。

输入
分别输入5个int型整数、5个float 型实数、5个long long型正整数。

输出
分别输出5个int型整数的最大值、5个float 型实数的最大值、5个long long型正整数的最大值。

样例输入
11 22 666 44 55
11.11 22.22 33.33 888.88 55.55
1234567 222222 333333 444444 555555

样例输出
666
888.88
1234567
 */
#include <iostream>

using namespace std;

int max(int x,int len){
  int _;
  for (int i = 0; i < len; i++) {
    std::cin >> x;
    _ = _ > x ? _ : x;
  }
  return _;
}

float max(float x,int len){
  float _;
  for (int i = 0; i < len; i++) {
    std::cin >> x;
    _ = _ > x ? _ : x;
  }
  return _;
}

long long max(long long x,int len){
  long long _;
  for (int i = 0; i < len; i++) {
    std::cin >> x;
    _ = _ > x ? _ : x;
  }
  return _;
}

int main(int argc, char const *argv[]) {
  int a;
  float b;
  long long c;

  std::cout << max(a,5) << '\n';
  std::cout << max(b,5) << '\n';
  std::cout << max(c,5) << '\n';

  return 0;
}
