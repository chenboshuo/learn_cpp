// filename:Date.h
#include<iostream>
#include <array>
#include <stdexcept>
using namespace std;

#ifndef DATE_H
#define DATE_H

// class definition
class Date {
private:
  unsigned int month;
  unsigned int day;
  unsigned int year;

  // utility function to check if day day is proper for month and yeear
  unsigned int check_day(int test_day) const;

public:
  static const int months_per_year = 12;// months in a year
  explicit Date (int m=1, int d=1, int y=1900);
  void print() const;
  ~Date();// proovided to confirm destruction order
};

/**
 * Date constructor (should do range checking)
 * @param m month
 * @param d day
 * @param y year
 */
Date::Date(int m, int d, int y){
  if (m > 0 && m <= months_per_year) {
    month = m;
  } else {
    throw invalid_argument("month must be 1-12");
  }
  year = y;
  day = check_day(d); // validate the day
  cout << "Date object constructor for date ";
  print();
  cout << endl;
}


// print Date object to show when its constructor is called
void Date::print() const{
  cout << month << '/' << day << '/' << year ;
}

/**
 * utility function to confrim proper day value based on
 * month and year : handles leap years, too
 * @param  test_day day
 * @return          day
 */
unsigned int Date::check_day(int test_day) const{
  static const array<int, months_per_year+1> days_per_month =
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  // determine whether test_day is valid for specified month
  if (test_day > 0 && test_day <= days_per_month[month]) {
    return test_day;
  }

  // Feburary 29 check for leap year
  if (month == 2 && test_day == 29 && (year % 400 == 0 ||
    (year % 4 == 0 && year % 100 != 0))) {
    return test_day;
  }

  throw invalid_argument("Invalid day for current month and year ");
}

Date::~Date(){
  cout << "Date object destructor for date ";
  print();
  cout << endl;
}

#endif
