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

  void display_message() const;
  // function that displays a welcome message to the GradeBook user

  void set_teacher_name(std::string name);//sets the teacher's name

  void determine_class_average() const; // averages user-entered grades

  std::string get_teacher_name();

private:
  std::string courseName; // course name for this GradeBook
  std::string teacher_name;
};

// construstor initialize courseName with std::string supplied as argument
GradeBook::GradeBook(std::string name, std::string teacher_name)
: teacher_name(teacher_name){// member initializer to initialize courseName
  set_course_name(name);
}

// function that sets the course name
// ensure that the course name has most 25 characters
void GradeBook::set_course_name(std::string name ) {

  if (name.size() <= 25) {// if name has 25 or fewer characters
    courseName = name;// store the course name in the object
  }else {
    // set course name to the first 25 characters of parameter name
    courseName = name.substr(0,25); // start at 0,length of 25

    std::cerr << "name:" << '\n' << name << "\nexceeds maxium length(25)\n"
      << "Limiting courseName to the first 25 characters.\n\n";

  }
}

// function that gets the course name
std::string GradeBook::get_course_name() const {
  return courseName;
}

// function that displays a welcome message to the GradeBook user
void GradeBook::display_message() const {
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

/**
 * determine class average based on 10 grades entered by user
 */
void GradeBook::determine_class_average() const{
  // initialization phase
  int total = 0;// sum of grades entered by user
  unsigned int gradeCounter = 1;// number of grade to be by entered next

  // processing phase
  while (gradeCounter <= 10) {
    std::cout << "Enter grade: "; // prompt for input
    int grade = 0;// grade value entered by user
    std::cin >> grade;// input next grade
    total += grade;// add grade to tatal
    gradeCounter++;// increment counter by 1
  }

  // termination phase
  int average = total / 10; // ok to mix declaration and calculation

  // display total and average of grades
  std::cout << "\nTotal of all 100 grade is "<< total << '\n';
  std::cout << "Class average is " << average << '\n';
}
