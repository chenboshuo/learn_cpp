// filename:Date.h
#include<iostream>
#include <array>
#include <stdexcept>
#include <string>
using namespace std;

#ifndef DATE_H
#define DATE_H

// class definition
class Date {
  friend ostream &operator<<( ostream &output, const Date &d);
 private:
  unsigned int month;
  unsigned int day;
  unsigned int year;

  static const array<int, 13> days_per_month;
  void help_increment();  // utility function for incrementing date

  // utility function to check if day day is proper for month and yeear
  // unsigned int check_day(int test_day) const;

 public:
  explicit Date (int m=1, int d=1, int y=1900); // default constructor
  void set_date(int m, int d, int y);  // set month, day, year
  Date &operator++();  // prefix increment operator
  Date operator++(int);  // postfix increment operator
  Date &operator+=(unsigned int additional_days);  // add days, modify object
  static bool is_leap_year(int y);  // is date in a leap year
  bool end_of_month(int d) const;
};

// Date constructor
Date::Date(int m, int d, int y){
  set_date(m, d, y);
}

// initialize static member; one class only
const array<int, 13> Date::days_per_month =
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/**
 * Date constructor (should do range checking)
 * @param m month
 * @param d day
 * @param y year
 */
void Date::set_date(int m, int d, int y){
  if (m > 0 && m <= 12) {
    month = m;
  } else {
    throw invalid_argument("month must be 1-12");
  }
  if (y >= 1900 && y <= 2100) {
    year = y;
  } else {
    throw invalid_argument("Year must be >= 1900 and <= 2000");
  }

  // test for a leap year
  if ((month == 2 && is_leap_year(year) && d >= 1 && d <= 29) ||
      (d >= 1 && d <= days_per_month[month])) {
    day = d;
  }else
    throw invalid_argument("Day is out of range for current month and year");
}

// overload postfix increment operator
Date &Date::operator++(){
  help_increment();  // increment date
  return *this;  // reference return to create value
}

/**
 * overloaded postfix increment operator;
 * note that the dummy(假的,虚拟的) integer parameter
 * does not have a parameter name
 */
Date Date::operator++(int){
  Date temp = *this;  // hold current state of object
  help_increment();

  // return unicremented, saved, tempoary object
  return temp;
}

// add specified number of days of days to date
Date &Date::operator+=(unsigned int additional_days){
  for(unsigned int i = 0; i < additional_days; ++i){
    help_increment();
  }
  return *this;
}


bool Date::is_leap_year(int y){
  if (y % 400 == 0 ||( y % 100 !=0 && y % 4 == 0)) {
    return true;
  } else {
    return false;
  }
}

// determine whether the day is the last year of the month
bool Date::end_of_month(int d) const{
  if (month == 2 && is_leap_year(year)) {
    return (d == 29);
  } else {
    return (d == days_per_month[month]);
  }
}

void Date::help_increment() {
  // day is not end of month
  if (!end_of_month(day)) {
    ++day;
  } else {
    if (month < 12) {  // day is end of month and month < 12
      ++month;
      day = 1;
    } else {  // last day of year
      ++year;
      month = 1;
      day = 1;
    }
  }
}

// overload output operator
ostream &operator<<(ostream &output, const Date &d){
  static string month_name[13] = {"", "January", "February",
    "March", "April", "May", "June", "July", "August",
    "September", "October", "November", "December"
  };
  output << month_name[d.month] << ' ' << d.day << ", "<< d.year;
  return output;  // enablees cascading
}

#endif
