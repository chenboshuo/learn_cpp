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
  explicit Time (int hour =0, int minute=0, int second=0);// default constructor

  // set funxtions
  void set_time(int h, int m, int s);
  void set_hour(int h);
  void set_minute(int m);
  void set_second(int s);

  // get functions
  unsigned int get_hour() const;
  unsigned int get_minute() const;
  unsigned int get_second() const;

  void print_universal() const;
  void print_standard() const;
};

#endif

/**
 * Time xonstructor initialize wach data member to 0
 */
Time::Time(int hour, int minute, int second){
    set_time(hour, minute, second);
  }

void Time::set_time(int h, int m, int s) {
  set_hour(h); // set private field hour
  set_minute(m);
  set_second(s);
}

/**
 * set hour value
 */
void Time::set_hour(int h) {
  if (h >= 0 && h < 24) {
    hour = h;
  } else {
    throw invalid_argument("hour must be 0-23");
  }
}

void Time::set_minute(int m){
  if (m >= 0 && m < 60) {
    minute = m;
  } else {
    throw invalid_argument("minute must be 0-59");
  }
}

void Time::set_second(int s){
  if (s >= 0 && s < 60) {
    second = s;
  } else {
    throw invalid_argument("second must be 0-23");
  }
}

unsigned int Time::get_hour() const{
  return hour ;
}
unsigned int Time::get_minute() const{
  return minute;
}
unsigned int Time::get_second() const{
  return second;
}
/**
 * print time unicersal-time format(HH:MM:SS)
 */
void Time::print_universal() const {
  std::cout << setfill('0') << setw(2) << hour << ":"
    << setw(2) << minute << ":"
    << setw(2) << second;
}

void Time::print_standard() const {
  std::cout << ((hour == 0 || hour == 12) ? 12 : hour %12 )<< ":"
    << setw(2) << minute << ":"
    << setw(2) << second << (hour < 12 ? " AM" : " PM");
}
