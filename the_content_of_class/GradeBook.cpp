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
  myGradeBook.input_grades();// read grades based on user
  myGradeBook.display_grade_report();// display report based on grades

}
/* output
Finished in 4 ms
Welcome to the Grade Book for
CS101 C++ programing

Enter the letter geades
Enter the EOF character to hte end input
Incorrect letter grade enteredEnter a new grade


Numbers of students who received each letter grade:
A: 3
B: 2
C: 3
D: 2
F: 1
*/
