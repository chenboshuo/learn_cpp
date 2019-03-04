/**
 * 问题 B: 求最大-类和对象
时间限制: 1 Sec  内存限制: 128 MB
提交: 1  解决: 1
[提交] [状态] [讨论版] [命题人:admin]
题目描述

利用类的数据成员和成员函数完成下列操作：输入三个整数，输出它们的最大值。

输入

输入三个整数。

输出

输出3个整数的最大值。

样例输入

2 8 5

样例输出

8

提示

仅供参考。
*/
#include<iostream>
using namespace std;

class Max
{
private:
  int a,b,c;//数据成员a,b,c
public:
  //设置或读取a,b,c值的函数
  void setValue(int a1, int b1, int c1) {
    a = a1;
    b = b1;
    c = c1;
  }

  //成员函数max(a,b,c)
  int max() {
    int max = a;
    if (b > max ) {
      max = b;
    } else if (c > max ) {
      max = c;
    }
    return max;
  }

};

int main()
{

  //创建对象
  Max object;
  int a,b,c;
  cin >> a >> b >> c;
  //用对象去调用成员函数
  object.setValue(a,b,c);
  std::cout << object.max() << '\n';
return 0;
}
/**
 * intput
 *
 * 2 8 5
 *
 * output
 * 8
 */
