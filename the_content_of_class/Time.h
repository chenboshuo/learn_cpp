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
  Time &set_time(int h, int m, int s);
  Time &set_hour(int h);
  Time &set_minute(int m);
  Time &set_second(int s);
  unsigned int &bad_set_hour(int); // dangous reference return

  // get functions (the time & )
  unsigned int get_hour() const;
  unsigned int get_minute() const;
  unsigned int get_second() const;

  void print_universal() const;
  void print_standard() const;
  void tick(int s=1);// increase by s second
};

#endif

/**
 * Time xonstructor initialize wach data member to 0
 */
Time::Time(int hour, int minute, int second){
    set_time(hour, minute, second);
  }

Time &Time::set_time(int h, int m, int s) {
  set_hour(h); // set private field hour
  set_minute(m);
  set_second(s);
  return *this; // enables cascading
}

/**
 * set hour value
 */
Time &Time::set_hour(int h) {
  if (h >= 0 && h < 24) {
    hour = h;
  } else {
    throw invalid_argument("hour must be 0-23");
  }
  return *this;
}

Time &Time::set_minute(int m){
  if (m >= 0 && m < 60) {
    minute = m;
  } else {
    throw invalid_argument("minute must be 0-59");
  }
  return *this;
}

Time &Time::set_second(int s){
  if (s >= 0 && s < 60) {
    second = s;
  } else {
    throw invalid_argument("second must be 0-23");
  }
  return *this;
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
  std::cout << setfill('0') << setw(2)
    << ((hour == 0 || hour == 12) ? 12 : hour %12 )<< ":"
    << setw(2) << minute << ":"
    << setw(2) << second << (hour < 12 ? " AM" : " PM");
}

/**
 * increase by s second
 * @param s second
 */
void Time::tick(int s) {
  second += s;
  while(second >= 60) {
    minute ++;
    second -= 60;
  }
  while(minute >= 60){
    hour ++;
    minute -= 60;
  }
  while (hour >= 24) {
    hour -= 24;
  }
}

// poor practice : returning a reference to a private data number
/*  test function:
  Time t;
  // initialize hourRef with the reference returned by bad_set_hour
  unsigned int &hourRef = t.bad_set_hour(20); // 20 is a valid hour
  cout << "Valid hour before modification: " << hourRef << endl;
  hourRef = 30;
  cout << "\nInvalid hour after modification: " << t.get_hour() << endl;
  // Dangerous : Function call that returns
  // a reference can be used as an Ivalue
  t.bad_set_hour(12) = 74;
  cout << "\nPOOR PROGRAMING PRACTICE!!!!!"
    << "\nt.bad_set_hour(12) as an  Ivalue, invalid hour: "
    << t.get_hour()
    << endl;
  output
  alid hour before modification: 20
Invalid hour after modification: 30
POOR PROGRAMING PRACTICE!!!!!
t.bad_set_hour(12) as an  Ivalue, invalid hour: 74
*/
unsigned int &Time::bad_set_hour(int hh){
  if (hh >= 0 && hh < 24) {
    hour = hh;
  }
  return hour;// dangous return
}
