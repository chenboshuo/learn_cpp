// filename: time.cpp
#include "Time.h"
int main(int argc, char const *argv[]) {
  Time wake_up(6, 45, 0);// non-const object
  const Time noon(12, 0, 0);// const object
                          // onject      member function
  wake_up.set_hour(18);   // non-const  non-const
  noon.set_hour(12);      // const      non-const ---- error
  wake_up.get_hour();     // non-const  const
  noon.get_minute();      // const      const
  noon.print_universal(); // const      const
  noon.print_standard();  // const      non-const ---- error
}
 /*
time.cpp: In function 'int main(int, const char**)':
time.cpp:8:19: error: passing 'const Time' as 'this' argument discards qualifiers [-fpermissive]
   noon.set_hour(12);      // const      const
                   ^
In file included from time.cpp:2:
Time.h:56:6: note:   in call to 'void Time::set_hour(int)'
 void Time::set_hour(int h) {
      ^~~~

toggle line 8, line 12 comments,Build success
 */
