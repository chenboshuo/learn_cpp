// filename: time.cpp
#include "Time.h"
 int main(int argc, char const *argv[]) {
   Time t; // instantiate object t of calss time

   // output Time object t's initial values
   std::cout << "The initial universal time is ";
   t.print_univwersal();
   std::cout << "\nThe initial standard time is " ;
   t.print_standard();

   t.set_time(13, 27, 6); // change times

   // output Time object t's new values
   std::cout << "\n\nUniversal time after set_time is " ;
   t.print_univwersal();
   std::cout << "\nStandard after set_time is " ;
   t.print_standard();

   // attempt to set the time with invalid invalid values
   try{
     t.set_time(99, 99, 99); // all values out of range
   }
   catch(invalid_argument &e){
     std::cout << "Exception:" << e.what() << '\n';
   }

   // output t's values after specifying invalid values
   std::cout << "\n\nAfter attempting invalid settings:"
    << "\nUniversal time: ";
   t.print_univwersal();
   std::cout << "\nStandard time:" ;
   t.print_standard();

   return 0;
 }
 /*
 The initial universal time is 00:00:00

The initial standard time is 12:00:00 AM


Universal time after set_time is 13:27:06

Standard after set_time is 1:27:06 PM
Exception:hour, minute and/or second was out of range


After attempting invalid settings:
Universal time: 13:27:06

Standard time:1:27:06 PM
  */
