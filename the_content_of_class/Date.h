#include<iostream>
using namespace std;

#ifndef DATE_H
#define DATE_H

// class definition
class Date {
private:
  unsigned int month;
  unsigned int day;
  unsigned int year;

public:
  Date (int m=1, int d=1, int y=2000);
  void print();
};

/**
 * Date constructor (should do range checking)
 * @param m month
 * @param d day
 * @param y year
 */
Date::Date(int m, int d, int y)
  : month(m), day(d), year(y){
}

void Date::print() {
  cout << month << '/' << day << '/' << year << endl;
}

#endif
