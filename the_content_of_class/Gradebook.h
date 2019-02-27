// filename: Gradebook.h
// GradeBook calss definition in a sparate file from main.
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
