// filename : guest.cpp
#include <iostream>
#include <string>
#include <fstream>

#include "guest.h"
#include "date.h"
using namespace std;

int main(int argc, char const *argv[]) {
  Date today(1,2,2010);
  Guest a_man("100000", today,"Mr.a");
  a_man.show();
  // a_man.record();
  /*
    His name is: Mr.a
    ID_card: 100000
    check in date: 1900-1-1
    100000,1900-1-1,Mr.a, man
   */

  cout << "\n\n";
  Guest a_woman("109", today, "a", "girl");
  a_woman.show();
  // a_woman.record();
  /*
    Her name is: a
    ID_card: 109
    check in date: 2010-1-2
   */

  // 测试文件写入
  ofstream out("temp.txt",ios::app);
  out << a_woman;

  return 0;
}
/*
Her name is: Mr.a
ID_card: 100000
check in date: 2010-1-2


Her name is: a
ID_card: 109
check in date: 2010-1-2
 */
