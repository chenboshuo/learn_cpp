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
  // create two GradeBook objects
  GradeBook gradeBook1("Introduction to C++ Programing", "a");
  GradeBook gradeBook2("Data strustures in C++", "b");

  // display initial value of courseName for each GradeBook
  cout << "gradeBook1 created for course: " << gradeBook1.get_course_name()
    << "\n" << "This course is presented by: " << gradeBook1.get_teacher_name()
    << "\ngradeBook2 created for course: "<< gradeBook2.get_course_name()
    << "\n" << "This course is presented by: " << gradeBook2.get_teacher_name()
    << '\n' ;

}
/* output
gradeBook1 created for course: Introduction to C++ Programing
This course is presented by: a
gradeBook2 created for course: Data strustures in C++
This course is presented by: b
*/
