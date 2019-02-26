/** Gradebook.cpp
 * Define class GradeBook with a member function displaymessage
 * create a GradeBook object,and call its displayMessage function
 */
#include <iostream>
#include <string>
using namespace std;

// GradeBook class definition
class GradeBook {
public:
  // construstor initialize courseName with string supplied as argument
  explicit GradeBook(string name, string teacher_name)
  : courseName(name), teacher_name(teacher_name){// member initializer to initialize courseName
      // empty body
  }


  // function that sets the course name
  void set_course_name(string name ) {
    courseName = name;
  }

  // function that gets the course name
  string get_course_name() const{
    return courseName;
  }

  // funcxtion that displays a welcome message to the GradeBook user
  // function that displays a welcome message to the GradeBook user
  void display_message(string courseName) const {
    cout << "Welcome to the Grade Book for\n" << courseName <<'\n';
  }
  /**
   * sets the teacher's name
   * @param name
   */
  void set_teacher_name(string name) {
    teacher_name = name;
  }

  string get_teacher_name(){
    return teacher_name;
  }
private:
  string courseName; // course name for this GradeBook
  string teacher_name;
};

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
