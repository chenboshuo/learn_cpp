#include <iostream>   // 预处理命令
using namespace std;  // 使用标准命名空间std

// 整型类
class Integer {
 private:
  int val;  // 整数值
 public:
  Integer() { val = 0; }  // 无参数的构造函数
  // Integer(int v = 0){ val = v; }			// 带参数的构造函数
  // 函数的默认值与重载函数冲突,改为:
  Integer(int v) { val = v; }           // 带参数的构造函数
  void Show() { cout << val << endl; }  // 显示整数值
};

int main() {
  Integer a(2), b;  // 定义整型对象
  a.Show();         // 显示a
  b.Show();         // 显示b

  return 0;  // 返回值0, 返回操作系统
}
/**
 * output
 * 2
 * 0
 */
