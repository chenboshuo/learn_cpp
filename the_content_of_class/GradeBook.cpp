/** Gradebook.cpp
 * Define class GradeBook with a member function displaymessage
 * create a GradeBook object,and call its displayMessage function
 */
#include <iostream>
#include <string>
#include "Gradebook.h"
using namespace std;



// funstion main begins program execution
int main(int argc, char const *argv[]) {
  // creat GradeBook object myGradeBook and
  // pass course name to constructor
  GradeBook myGradeBook("CS101 C++ programing", "yourself");

  myGradeBook.display_message(); // display welcome messages
  myGradeBook.determine_class_average();// find average of 10 grades

}
/* output
Welcome to the Grade Book for
CS101 C++ programing

Enter grade or -1 to quit: 97
Enter grade or -1 to quit: 88
Enter grade or -1 to quit: 72
Enter grade or -1 to quit: -1

Total of all 3 grades is 257
Class average is 85.67
*/
