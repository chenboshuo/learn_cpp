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
  // array of students grades
  const array<int, GradeBook::students> grades =
    {87, 68, 94, 100, 83, 78, 85, 91, 76, 87};
  std::string courseName = "CS101 C++ programing";
  GradeBook myGradeBook( courseName, "yourself",grades);

  myGradeBook.display_message(); // display welcome messages
  myGradeBook.process_grades();

}
/* output
The grade are:

Student 1: 87
Student 2: 68
Student 3: 94
Student 4:100
Student 5: 83
Student 6: 78
Student 7: 85
Student 8: 91
Student 9: 76
Student10: 87

Class averge is 84.90
Lowest grades is 68
Highist grades is 100

Grade distribution:
 0-9 :
10-19:
20-29:
30-39:
40-49:
50-59:
60-69: *
70-79: **
80-89: ****
90-99: **
  100: *
*/
