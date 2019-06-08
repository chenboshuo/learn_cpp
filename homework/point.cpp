/**
 * Point类的定义
时间限制: 1 Sec  内存限制: 128 MB
提交: 1  解决: 1
[提交] [状态] [讨论版] [命题人:admin]
题目描述

通过本题目的练习可以掌握类与对象的定义；
设计一个点类Point，它具有私有数据成员x(横坐标)、y(纵坐标)；公有成员函数：setPoint(int,int)用于设置点对象的值，ShowPoint()用于输出点对象的信息
在主函数中调用成员函数setPoint(int,int)为点对象设置值，并调用成员函数ShowPoint()输出点的信息。


输入

 无

输出

 一对圆括号内，x和y的值用逗号间隔

样例输入

无

样例输出

(10,11)
 */
#include <iostream>
class Point {
 private:
  int x, y;  // 存储坐标

 public:
  void setPoint(int value_x, int value_y) {
    x = value_x;
    y = value_y;
  }

  void showPoint(void) { std::cout << "(" << x << "," << y << ")" << '\n'; }
};

int main(int argc, char const *argv[]) {
  Point object;
  object.setPoint(10, 11);
  object.showPoint();

  return 0;
}
// output
// (10,11)
