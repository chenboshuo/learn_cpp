// filename: Gradebook.h
// GradeBook calss definition in a sparate file from main.
#include <iostream>
#include <string>


// GradeBook class definition
class GradeBook {
public:
  // construstor initialize courseName with std::string supplied as argument
  explicit GradeBook(std::string name, std::string teacher_name)
  : courseName(name), teacher_name(teacher_name){// member initializer to initialize courseName
      // empty body
  }


  // function that sets the course name
  void set_course_name(std::string name ) {
    courseName = name;
  }

  // function that gets the course name
  std::string get_course_name() const{
    return courseName;
  }

  // funcxtion that displays a welcome message to the GradeBook user
  // function that displays a welcome message to the GradeBook user
  void display_message(std::string courseName) const {
    std::cout << "Welcome to the Grade Book for\n" << courseName <<'\n';
  }
  /**
   * sets the teacher's name
   * @param name
   */
  void set_teacher_name(std::string name) {
    teacher_name = name;
  }

  std::string get_teacher_name(){
    return teacher_name;
  }
private:
  std::string courseName; // course name for this GradeBook
  std::string teacher_name;
};
