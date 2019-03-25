// filename: Gradebook.h
// GradeBook calss definition in a sparate file from main.
#include <iostream>
#include <string>
#include <iomanip> // setprecision()
using namespace std;

// GradeBook class definition
class GradeBook {
public:
  explicit GradeBook(std::string name, std::string teacher_name);
  // construstor initialize courseName with std::string supplied as argument


  void set_course_name(std::string name ); // function that sets the course name
  std::string get_course_name() const; // function that gets the course name
  void set_teacher_name(std::string name);//sets the teacher's name
  std::string get_teacher_name();

  void display_message() const;
  // function that displays a welcome message to the GradeBook user

  void determine_class_average() const; // averages user-entered grades


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
  std::cout << "Welcome to the Grade Book for\n" << courseName << "\n\n";
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
  unsigned int gradeCounter = -1;// number of grade to be by entered next
  // and get rid of invalid data

  // processing phase
  // prompt for input and read grade from user
  int grade = 0;// grade value entered by user
  // loop until sentinel value read from user
  do {
    total += grade;// add grade to tatal
    gradeCounter++;// increment counter by 1
    // prompt for input and read next grade from user
    std::cout << "Enter grade or -1 to quit: ";
    std::cin >> grade; // input grade value or sentinel(守卫) value
  }while (grade != -1);


  // termination phase
  if (gradeCounter != 0) {// if user entered at least one grade
    // calculate average of all grades entered
    /**
     * static_cast<double> 生成了临时的浮点数
     * 像这样利用强制类型转换运算符进行的转换成为显式转换(explict conversion)
     * 存储在total中的值仍为整数
     */
    double average = static_cast<double>(total) / gradeCounter; // ok to mix declaration and calculation

    // display total and average of grades
    std::cout << "\nTotal of all " << gradeCounter <<" grades is "
      << total << '\n';
    std::cout << setprecision(2) << fixed;
    std::cout << "Class average is " << average << '\n';
  }else{
    std::cout << "No grades were entered" << '\n';
  }
}
