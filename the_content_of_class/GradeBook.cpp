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
Enter grade: 67
Enter grade: 78
Enter grade: 89
Enter grade: 67
Enter grade: 87
Enter grade: 98
Enter grade: 93
Enter grade: 85
Enter grade: 82
Enter grade: 100

Total of all 100 grade is 846
Class average is 84
*/
