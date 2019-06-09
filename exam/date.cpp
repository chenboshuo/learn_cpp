/*
请使用Dev C++打开考生文件夹
D:\JSJWZH\CbtesExam\VC_A001\下的proj2.cpp。
其中定义了类Day和用于测试该类的主函数main。
类Day是一个用来描述日期的类，
其运算符成员函数-用来计算两个日期之间相差的天数，
为类实现该函数，其用法可参见主函数main。
为了简化该函数的实现，
假设该运算符函数的第一个日期对象操作数大于或等于第二个日期对象操作数，
即不考虑非法情况。同时要求两个日期在同一年，且不必考虑闰年。
运算符函数operator-的部分实现代码已在文件proj2.cpp中给出，
请在标有注释"//TOD0：”的行中添加适当的代码，
将运算符函数operator-补充完整，以实现其功能。
 */
#include <iostream>
using namespace std;

class Day {
 private:
  int year;
  int month;
  int day;

 public:
  Day(int y = 2000, int m = 1, int d = 1);  // 构造函数
  int operator-(const Day &d);              // 重载运算符 -
  void Print() const;                       // 输出日期
};

Day::Day(int y, int m, int d) {
  year = y;
  month = m;
  day = d;
}

int Day::operator-(const Day &d)  // 实现运算符函数 -
{
  int diffs, m;
  int monthday[13] = { // 存放每月的天数
                       0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
  };

  if (year == d.year &&
      month == d.month) {  // 若两日期在同年同月内, 则计算其相差的天数
    //**********found**********
    diffs = day - d.day;  // TODO: 在此增加代码
    //**********found**********
    return diffs;  // TODO: 在此增加一条语句
  } else
    diffs = monthday[d.month] - d.day + day;  // 计算除整月以外相差的天数
  for (m = d.month + 1; m < month; m++)
    //**********found**********
    diffs += monthday[m];  // TODO: 在此增加一条语句,
                           // 依次计算两个日期间相差的整月天数
  return diffs;
}

void Day::Print() const {
  cout << "Year = " << year << ", Month = " << month << " , Day = " << day
       << endl;
}

int main() {
  int y, m, d;
  cin >> y >> m >> d;
  Day d1(y, m, d);
  cin >> y >> m >> d;
  Day d2(y, m, d);
  int diff_days;
  d1.Print();
  d2.Print();
  diff_days = d1 - d2;  // 计算d1和d2相差天数
  cout << "Difference days: " << diff_days << endl;
  return 0;
}
