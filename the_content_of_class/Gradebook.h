// filename: Gradebook.h
// GradeBook calss definition in a sparate file from main.
#include <iostream>
#include <string>


// GradeBook class definition
class GradeBook {
public:
  explicit GradeBook(std::string name, std::string teacher_name);
  // construstor initialize courseName with std::string supplied as argument
  void set_course_name(std::string name ); // function that sets the course name
  std::string get_course_name() const; // function that gets the course name
  void display_message(std::string courseName) const;
  // function that displays a welcome message to the GradeBook user
  void set_teacher_name(std::string name);//sets the teacher's name
  std::string get_teacher_name();

private:
  std::string courseName; // course name for this GradeBook
  std::string teacher_name;
};

// construstor initialize courseName with std::string supplied as argument
GradeBook::GradeBook(std::string name, std::string teacher_name)
: courseName(name), teacher_name(teacher_name){// member initializer to initialize courseName
  // empty body
}

// function that sets the course name
void GradeBook::set_course_name(std::string name ) {
  courseName = name;
}

// function that gets the course name
std::string GradeBook::get_course_name() const {
  return courseName;
}

// function that displays a welcome message to the GradeBook user
void GradeBook::display_message(std::string courseName) const {
  std::cout << "Welcome to the Grade Book for\n" << courseName <<'\n';
}

/**
* sets the teacher's name
* @param name
*/
void GradeBook::set_teacher_name(std::string name) {
  teacher_name = name;
}

std::string GradeBook::get_teacher_name(){
  return teacher_name;
}
