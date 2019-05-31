// filename : guest.cpp
#include <iostream>
#include <string>

#include "guest.h"
#include "date.h"
using namespace std;

int main(int argc, char const *argv[]) {
  Date today(1,2,2018);
  Guest a_man("100000", today,"Mr.a");
  a_man.show();
  a_man.record();
  /*
    His name is: Mr.a
    ID_card: 100000
    check in date: 1900-1-1
    100000,1900-1-1,Mr.a, man
   */

  cout << "\n\n";
  Guest a_woman("108", today, "a", "girl");
  a_woman.show();
  a_woman.record();
  /*
    His name is: a
    ID_card: 108
    check in date: 1900-1-1
    108,1900-1-1,a, man
   */

  return 0;
}
/*
His name is: Mr.a
ID_card: 100000
check in date: 1900-1-1
100000,1900-1-1,Mr.a, man


His name is: a
ID_card: 108
check in date: 1900-1-1
108,1900-1-1,a, man
 */
