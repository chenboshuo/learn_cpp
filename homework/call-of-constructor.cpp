/**
 * 问题 A: 构造函数的调用
时间限制: 1 Sec  内存限制: 128 MB
提交: 26  解决: 24
[提交] [状态] [讨论版] [命题人:admin]
题目描述
通过本题目的练习可以掌握构造函数和析构函数的调用；
创建类A；类中仅包含构造函数和析构函数，按照程序的输出写出类的定义和主函数main中的代码。


输出
输出数据有4行，分别代表对构造函数和析构函数的调用；本练习要求所编写程序的输出必须与示例相同。

样例输出
Constructing an object of A
Constructing an object of A
Destructing an object of A
Destructing an object of A
 */
#include <iostream>
class Test {
 private:
 public:
  Test() { std::cout << "Constructing an object of A" << '\n'; };
  ~Test() { std::cout << "Destructing an object of A" << '\n'; };
};

int main(int argc, char const *argv[]) {
  Test class_a;
  Test p;
  return 0;
}
