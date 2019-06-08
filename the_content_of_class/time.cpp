// filename: time.cpp
#include "Time.h"
int main(int argc, char const *argv[]) {
  Time t;  // create Time object

  // test output and input
  cout << "please input as form hh:mm:ss" << endl;
  std::cin >> t;
  cout << t << endl;
  /* output
  please input as form hh:mm:ss
  20:33:12
  Universal tims is: 20:33:12
  Standard time is: 08:33:12 PM
   */

  // test +
  Time t1(23, 59, 59);
  Time t2(0, 0, 5);
  cout << "\n\nt1(23, 59, 59) + t2(0, 0, 5) is " << endl;
  cout << t1 + t2 << endl;
  /*
  t1(23, 59, 59) + t2(0, 0, 5) is
  Universal tims is: 00:00:04
  Standard time is: 12:00:04 AM
   */

  // test -
  Time t3;
  cout << "\n\nt3(0,0,0) - t1(23,59,59) is " << endl;
  cout << t3 - t1 << endl;
  /* output
  t3(0,0,0) - t1(23,59,59) is
  Universal tims is: 00:00:01
  Standard time is: 12:00:01 AM
   */
}
/*  实验 4.8 设计一个时间类Time，要求：
包含时(hour)、分(minute)和秒(second)私有数据成员, 包含构造函数。
重载关于一时间加上另一时间的加法运算符+
重载关于一时间减去另一时间的减加运算符-
重载输出运算符<<与输入运算符>>等。

output

please input as form hh:mm:ss
20:33:12
Universal tims is: 20:33:12
Standard time is: 08:33:12 PM


t1(23, 59, 59) + t2(0, 0, 5) is
Universal tims is: 00:00:04
Standard time is: 12:00:04 AM


t3(0,0,0) - t1(23,59,59) is
Universal tims is: 00:00:01
Standard time is: 12:00:01 AM
*/
