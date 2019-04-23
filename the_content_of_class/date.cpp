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

  cout << "\n\nd1 += 7 is " << (d1 += 7) << endl;
  /* output
    d1 += 7 is January 3, 2011
   */

  d2.set_date(2, 28, 2008);
  cout << "\n\n  d2 is " << d2 << endl;
  cout << "++d2 is " << ++d2 << endl;
  /* output
    d2 is February 28, 2008
    ++d2 is February 29, 2008
   */

  Date d3(7, 13, 2010);

  cout << "\n\nTesting the prefix increasement operator" << endl;
  cout << "  d3 is " << d3 << endl;
  cout << "++d3 is " << ++d3 << endl;
  cout << "  d3 is " << d3 << endl;
  /* output
    Testing the prefix increasement operator
    d3 is July 13, 2010
  ++d3 is July 14, 2010
    d3 is July 14, 2010
   */

  cout << "\n\nTesting the prefix increment operator" << endl;
  cout << "d3   is " << d3 << endl;
  cout << "d3++ is" << d3++ << endl;
  cout << "d3   is " << d3 <<endl;
  /* output
    Testing the prefix increment operator
    d3   is July 14, 2010
    d3++ isJuly 14, 2010
    d3   is July 15, 2010
   */

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
 */
