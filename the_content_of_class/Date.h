// filename:Date.h
#include <array>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

#ifndef DATE_H
#  define DATE_H

// class definition
class Date {
  friend ostream &operator<<(ostream &output, const Date &d);
  friend istream &operator>>(istream &input, Date &d);

 private:
  unsigned int month;
  unsigned int day;
  unsigned int year;

  static const array<int, 13> days_per_month;
  void increment();  // utility function for incrementing date
  void decrement();  // utility function for decrementing date

  // utility function to check if day day is proper for month and yeear
  // unsigned int check_day(int test_day) const;

 public:
  explicit Date(int m = 1, int d = 1, int y = 1900);  // default constructor
  void set_date(int m, int d, int y);                 // set month, day, year
  Date &operator++();                     // prefix increment operator
  Date operator++(int);                   // postfix increment operator
  Date &operator+=(int additional_days);  // add days, modify object
  Date operator+(int n);
  Date operator-(int n);
  static bool is_leap_year(int y);  // is date in a leap year
  bool end_of_month(int d) const;
};

// Date constructor
Date::Date(int m, int d, int y) { set_date(m, d, y); }

// initialize static member; one class only
const array<int, 13> Date::days_per_month = { 0,  31, 28, 31, 30, 31, 30,
                                              31, 31, 30, 31, 30, 31 };

/**
 * Date constructor (should do range checking)
 * @param m month
 * @param d day
 * @param y year
 */
void Date::set_date(int m, int d, int y) {
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
  } else
    throw invalid_argument("Day is out of range for current month and year");
}

// overload postfix increment operator
Date &Date::operator++() {
  increment();   // increment date
  return *this;  // reference return to create value
}

/**
 * overloaded postfix increment operator;
 * note that the dummy(假的,虚拟的) integer parameter
 * does not have a parameter name
 */
Date Date::operator++(int) {
  Date temp = *this;  // hold current state of object
  increment();

  // return unicremented, saved, tempoary object
  return temp;
}

// add specified number of days of days to date
Date &Date::operator+=(int additional_days) {
  if (additional_days >= 0) {
    for (int i = 0; i < additional_days; ++i) { increment(); }
  } else {
    additional_days *= -1;
    for (int i = 0; i < additional_days; ++i) { decrement(); }
  }
  return *this;
}

// reload + operator
Date Date::operator+(int n) {
  Date temp = *this;
  if (n >= 0) {
    for (int i = 0; i < n; ++i) { temp.increment(); }
  } else {
    n *= -1;  // make n a posititve number
    for (int i = 0; i < n; ++i) { temp.decrement(); }
  }
  return temp;
}

// reload - operator
Date Date::operator-(int n) {
  Date temp = *this;
  if (n >= 0) {
    for (int i = 0; i < n; ++i) { temp.decrement(); }
  } else {
    n *= -1;  // make n a posititve number
    for (int i = 0; i < n; ++i) { temp.increment(); }
  }
  return temp;
}

bool Date::is_leap_year(int y) {
  if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0)) {
    return true;
  } else {
    return false;
  }
}

// determine whether the day is the last year of the month
bool Date::end_of_month(int d) const {
  if (month == 2 && is_leap_year(year)) {
    return (d == 29);
  } else {
    return (d == days_per_month[month]);
  }
}

void Date::increment() {
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

// TODO
void Date::decrement() {
  if (day > 2) {
    --day;
  } else {
    if (month > 2 && month != 3) {
      --month;
      day = days_per_month[month];
    } else if (month == 3) {
      month = 2;
      day = (is_leap_year(year)) ? 29 : 28;
    } else {
      --year;
      month = 12;
      day = 31;
    }
  }
}

// overload output operator
ostream &operator<<(ostream &output, const Date &d) {
  static string month_name[13] = {
    "",     "January", "February",  "March",   "April",    "May",     "June",
    "July", "August",  "September", "October", "November", "December"
  };
  output << month_name[d.month] << ' ' << d.day << ", " << d.year;
  return output;  // enablees cascading
}

// input form yyyy-mm-dd
istream &operator>>(istream &input, Date &d) {
  input >> setw(4) >> d.year;
  input.ignore(1);  // skip "-"
  input >> setw(2) >> d.month;
  input.ignore(1);  // skip "-"
  input >> setw(2) >> d.day;
  return input;
}

#endif
