#include "Date.h"

int main(int argc, char const *argv[]) {
  Date date1(7, 4, 2004);
  Date date2; // date2 default memberwise assignment

  cout << "Date1 = ";
  date1.print();
  cout << "Date2 = ";
  date2.print();

  date2 = date1; // default memberwise assignment

  cout << "\nAfter default memberwise assignment, date2 = " ;
  date2.print();

  return 0;
}
/**
 * output
 * Date1 = 7/4/2004
Date2 = 1/1/2000

After default memberwise assignment, date2 = 7/4/2004
 */
