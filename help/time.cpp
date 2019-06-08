// time.h
#include <iomanip>
#include <iostream>
#include <stdexcept>
using namespace std;

#ifndef TIME_H

#  define TIME_H

class Time {
 public:
  explicit Time(int = 0, int = 0, int = 0);
  void setTime(int, int, int);
  void setHour(int);
  void setMinute(int);
  void setSecond(int);

  unsigned int getHour() const;
  unsigned int getMinute() const;
  unsigned int getSecond() const;

  void printStandard() const;
  void tick(int, int, int) const;

 private:
  unsigned int hour;
  unsigned int minute;
  unsigned int second;
};
#endif

// include "Time.h"

Time::Time(int hour, int minute, int second) {
  setTime(hour, minute, second);
  // tick(hour, minute, second);
}

void Time::setTime(int h, int m, int s) {
  setHour(h);
  setMinute(m);
  setSecond(s);
}

void Time::setHour(int h) {
  if (h >= 0 && h < 24)
    hour = h;
  else
    throw std::invalid_argument("hour must be 0-23");
}

void Time::setMinute(int m) {
  if (m >= 0 && m <= 59)  // 这里之前的范围没有包括59
    minute = m;
  else
    throw std::invalid_argument("minute must be 0-59");
}

void Time::setSecond(int s) {
  if (s >= 0 && s <= 59)  // 这里之前的范围没有包括59
    second = s;
  else
    throw std::invalid_argument("second must be 0-59");
}

unsigned int Time::getHour() const { return hour; }

unsigned int Time::getMinute() const { return minute; }

unsigned int Time::getSecond() const { return second; }

void Time::printStandard() const {
  cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12) << ":"
       << setfill('0') << setw(2) << getMinute() << ":" << setw(2)
       << getSecond();
}

void Time::tick(int h, int m, int s) const {
  if (s != 59)
    s += 1;
  else {
    s = 0;
    if (m != 59)
      m += 1;
    else {
      m = 0;
      h += 1;
    }
  }
}

using namespace std;

int main() {
  Time t(12, 54, 59);
  t.printStandard();
  cout << "\n";
  try {
    Time t2(99, 99, 99);
  } catch (invalid_argument &e) { cerr << e.what(); }
}
/*
12:54:59
our must be 0-23
*/
