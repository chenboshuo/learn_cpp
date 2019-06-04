// filename: date.cpp
#include "Date.h"
#include <iostream>
// #include "Employee.h"

using namespace std;


int main(int argc, char const *argv[]) {
  Date d1(12, 27, 2010);
  Date d2; // defaults to January 1, 1900

  cout << "d1 is " << d1 << endl;
  cout << "d2 is " << d2 << endl;
  /* output
    d1 is December 27, 2010
    d2 is January 1, 1900
   */

  d2 = d1;
  cout << "after d2 = d1" << endl;
  cout << "d1 is " << d1 << endl;
  cout << "d2 is " << d2 << endl;

  return 0;
}
/**
 * 10.8 重载Date的运算符
 * 重载运算符使得日期是否自增

d1 is December 27, 2010
d2 is January 1, 1900


d1 += 7 is January 3, 2011


  d2 is February 28, 2008
++d2 is February 29, 2008


Testing the prefix increasement operator
  d3 is July 13, 2010
++d3 is July 14, 2010
  d3 is July 14, 2010


Testing the prefix increment operator
d3   is July 14, 2010
d3++ isJuly 14, 2010
d3   is July 15, 2010

please input as form yyyy-mm-dd
2018-02-01
after input d4 is February 1, 2018

d5 is March 1, 2000
d5 - 1 is February 29, 2000
d5 is March 1, 2000

d5 is January 1, 2000
d5 - 1 is December 31, 1999
 */
