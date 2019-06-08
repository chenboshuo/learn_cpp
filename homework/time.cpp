/**
 * Time类的定义
时间限制: 1 Sec  内存限制: 128 MB
提交: 3  解决: 1
[提交] [状态] [讨论版] [命题人:admin]
题目描述

通过本题目的练习可以掌握类与对象的定义；
设计一个时间类Time，私有数据成员有hour(时)、minute(分)、second(秒)；
公有成员函数有：setHour(int)设置数据成员hour的值（采用12小时制），非法的输入默认为12；setMinue(int)设置数据成员minute的值，非法输入默认为0；setSecond(int)设置数据成员second的值，非法输入默认为0；setTime(int，int，int)设置时、分、秒三个数据成员的值；
showTime()显示时间对象的值。
在主函数main()中调用相应成员函数，使得时间对象的值能从键盘接收，并正确显示。

提示：时、分、秒均按2位数值形式显示 。


输入

输入3个整数，用一个空格间隔

输出

输出 时、分、秒的值，中间用“：”间隔

样例输入

10 11 12

样例输出

10:11:12

提示

输入
58 23 85
输出
12:23:00
 */
#include <iostream>
class Time {
 private:
  int hour;
  int minute = 0;
  int second = 0;

 public:
  void setHour() {
    int value;
    if (std::cin >> value && value >= 0 && value <= 12) {
      hour = value;
    } else {
      hour = 12;
    }
  }

  void setMinute() {
    int value;
    if (std::cin >> value && value >= 0 && value < 60) {
      minute = value;
    } else {
      minute = 0;
    }
  }

  void setSecond() {
    int value;
    if (std::cin >> value && value >= 0 && value < 60) {
      second = value;
    } else {
      second = 0;
    }
  }

  void showTime() { printf("%02d:%02d:%02d\n", hour, minute, second); }
};

int main(int argc, char const *argv[]) {
  Time object;
  object.setHour();
  object.setMinute();
  object.setSecond();
  object.showTime();

  return 0;
}
/**
 * Input
 * 10 11 12
 *
 * output
 * 10:11:12
 *
 * input
 * -1 1 61
 *
 * output
 * 12:01:00
 */
