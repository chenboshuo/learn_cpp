// filename: time.cpp
#include "Time.h"
int main(int argc, char const *argv[]) {
  Time t; // create Time object

  // cascaded function calls
  t.set_hour(18).set_minute(30).set_second(22);

  // output time in universal and standard formats;
  cout << "Universal time: ";
  t.print_universal();

  cout << "\nStandard time: ";
  t.print_standard();

  cout << "\n\nNew standard time: ";
  t.set_time(20, 20, 20).print_standard();
  cout << endl;
}
/*
9.13 使用this指针（使函数串联形成可能）
output

Universal time: 18:30:22
Standard time: 06:30:22 PM

New standard time: 08:20:20 PM
*/
