#include <iostream>
using namespace std;
//不允许修改其它代码
//在此处，根据main函数，定义Box类
//使输出符合要求

class Box {
 private:
  double length;
  double breadth;
  double height;
  double values;

 public:
  void setLength(double num) { length = num; }

  void setBreadth(double value) { breadth = value; }
  void setHeight(double value) { height = value; }

  double getVolume(void) { return length * breadth * height; }
};
int main() {
  Box Box1;             // 声明 Box1，类型为 Box
  Box Box2;             // 声明 Box2，类型为 Box
  double volume = 0.0;  // 用于存储体积

  // box 1 详述
  Box1.setLength(6.0);
  Box1.setBreadth(7.0);
  Box1.setHeight(5.0);

  // box 2 详述
  Box2.setLength(12.0);
  Box2.setBreadth(13.0);
  Box2.setHeight(10.0);

  // box 1 的体积
  volume = Box1.getVolume();
  cout << "Box1 的体积：" << volume << endl;

  // box 2 的体积
  volume = Box2.getVolume();
  cout << "Box2 的体积：" << volume << endl;
  return 0;
}

// output
// Box1 的体积：210
// Box2 的体积：1560
