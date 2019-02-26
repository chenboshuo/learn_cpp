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
  // function that sets the course name
  void set_course_name(string name ) {
    courseName = name;
  }

  // function that gets the course name
  string get_course_name() const{
    return courseName;
  }

  // funcxtion that displays a welcome message to the GradeBook user
  void display_message(string courseName) const {
    cout << "Welcome to the Grade Book for\n" << courseName <<'\n';
  }

private:
  string courseName; // course name for this GradeBook
};

// funstion main begins program execution
int main(int argc, char const *argv[]) {
  string nameOfCourse;
  Gradebook myGradeBook;// create a GradeBook object named myGradeBook

  // display initial value of CourseName
  std::cout << "Initial course name is:" << myGradeBook.get_course_name() << '\n';

  // prompt for and input course name
  cout << "Place enter the course name " << '\n';
  getline(cin, nameOfCourse);// read a course name with blanks
  cout << '\n';

  // call myGrade's displayMessage function
  // and pass nameOfCourse as an argument
  myGradeBook.display_message(nameOfCourse); // call object's displayMessage function
  return 0;
}
/*
input
cpp

output
Initial course name is:
// 说明私有对象不可访问
Welcome to the Grade Book for
cpp
*/
