// filename: Time.h
// Time calss definition.
#include<iostream>
#include <iomanip>
#include <stdexcept> // for invalid_argument exception class
using namespace std;
// 避免头文件多次包含
#ifndef Time_H
#define Time_H

// class definition
class Time {
private:
  unsigned int hour;// 0-23(24-hours clock format)
  unsigned int minute;// 0-59
  unsigned int second; // 0-59

public:
  Time ();
  void set_time(int h, int m, int s);
  void print_univwersal() const;
  void print_standard() const;
};

#endif

/**
 * Time xonstructor initialize wach data member to 0
 */
Time::Time()
  : hour(0), minute(0), second(0){
  }

void Time::set_time(int h, int m, int s) {
  // validate hour, minute and second
  if ((h >= 0 && h < 24) && (m >= 0 && m < 60) && (s >= 0 && s < 60)) {
    hour = h;
    minute = m;
    second = s;
  } else {
    throw invalid_argument(
      "hour, minute and/or second was out of range"
    );
  }
}

/**
 * print time unicersal-time format(HH:MM:SS)
 */
void Time::print_univwersal() const {
  std::cout << setfill('0') << setw(2) << hour << ":"
    << setw(2) << minute << ":"
    << setw(2) << second <<'\n';
}

void Time::print_standard() const {
  std::cout << ((hour == 0 || hour == 12) ? 12 : hour %12 )<< ":"
    << setw(2) << minute << ":"
    << setw(2) << second << (hour < 12 ? " AM" : " PM")<<'\n';
}
