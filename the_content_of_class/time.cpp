// filename: time.cpp
#include "Time.h"
int main(int argc, char const *argv[]) {
  Time t1;// all arguments defaulted
  std::cout << "Constructed with:\n\nt1:all arguments defaulted\n  ";
  t1.print_universal(); // 00:00:00
  std::cout << "\n  ";
  t1.print_standard();//12:00:00 AM

  Time t2(2);// minute and second defaulted
  std::cout << "\n\nt2:minute and second defaulted\n  ";
  t2.print_universal(); // 02:00:00
  std::cout << "\n  ";
  t2.print_standard();// 2:00:00 AM

  Time t3(21, 34);// second defaulted
  std::cout << "\n\nt3: second defaulted\n  ";
  t3.print_universal(); // 21:34:00
  std::cout << "\n  ";
  t3.print_standard();// 9:34:00 PM

  Time t4(12, 25, 42);// hour, minute and second specified
  std::cout << "\n\nt4:hour, minute and second specified\n  ";
  t4.print_universal(); // 12:25:42
  std::cout << "\n  ";
  t4.print_standard();// 12:25:42 AM

  // attempt to initialize t5 with invalid value
  try{
    Time t5(27, 74, 99);// all bad value specified
  }
  catch( invalid_argument &e){
    std::cerr << "\n\nExpection while initializing t5: "<< e.what() << '\n';
  }

  return 0;
}
  /*
9.5 Time实例探究：具有默认值的构造函数
  同时修改了一个拼写错误
  两个打印的函数去掉回车

  通过构造函数提供默认的实参， 可以保证即使在构造函数中没有任何值，构造函数仍可以初始化成员
output：
  Finished in 4 ms
  Constructed with:

  t1:all arguments defaulted
    00:00:00
    12:00:00 AM

  t2:minute and second defaulted
    02:00:00
    2:00:00 AM

  t3: second defaulted
    21:34:00
    9:34:00 PM

  t4:hour, minute and second specified
    12:25:42
    12:25:42 PM
 */
