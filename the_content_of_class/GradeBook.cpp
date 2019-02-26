/** Gradebook.cpp
 * Define class GradeBook with a member function displaymessage
 * create a GradeBook object,and call its displayMessage function
 */
#include <iostream>
#include <string>
using namespace std;

// GradeBook class definition
class Gradebook {
public:
  // funcxtion that displays a welcome message to the GradeBook user
  void display_message(string courseName) const {
    cout << "Welcome to the Grade Book for\n" << courseName <<'\n';
  }
};

// funstion main begins program execution
int main(int argc, char const *argv[]) {
  string nameOfCourse;
  Gradebook myGradeBook;// create a GradeBook object named myGradeBook

  // prompt for and input course name
  cout << "Place enter the course name " << '\n';
  getline(cin, nameOfCourse);// read a course name with blanks
  cout << '\n';

  // call myGrade's displayMessage function
  // and pass nameOfCourse as an argument
  myGradeBook.display_message(nameOfCourse); // call object's displayMessage function
  return 0;
}
// input
// cpp
// output
// Welcome to the Grade Book for
// cpp
