// filename: Gradebook.h
// GradeBook calss definition in a sparate file from main.
#include <iostream>
#include <string>
#include <iomanip> // setprecision()
#include <array>
using namespace std;

// GradeBook class definition
class GradeBook {
public:
  // constant -- number of student who took the test
  static const size_t students = 10;
  /*用`stastic`声明限定外部变量与函数,
  可以将其后声明的对象的作用域限定为被编译源文件的剩余部分.
  通过`static`限定外部对象,可以达到隐藏外部对象的目的
  */

  GradeBook(std::string &name,
    std::string teacher_name,
    const std::array<int, students> &grades_array);
    // construstor initialize courseName with std::string supplied as argument


  void set_course_name(std::string name ); // function that sets the course name
  std::string get_course_name() const; // function that gets the course name
  void set_teacher_name(std::string name);//sets the teacher's name
  std::string get_teacher_name();

  void display_message() const;
  // function that displays a welcome message to the GradeBook user

  void determine_class_average() const; // averages user-entered grades

  void input_grades();// input arbitrary report based on user input
  void display_grade_report()const;// display report based on user inputvoid

  void process_grades()const;// perform operations on the grade data
  int get_minium()const; // find the minium on the test
  int get_maxium()const; // find the maxium on the test
  double get_average() const;// determine the average grade for the test
  void output_bar_chart() const; // output bar chart of grade distribution
  void output_grades()const; // output the contests of the grade array
private:
  std::string courseName; // course name for this GradeBook
  std::string teacher_name;
  std::array<int, students> grades; // array of student grades
  unsigned int aCount;// count of A grades
  unsigned int bCount;// count of B grades
  unsigned int cCount;// count of C grades
  unsigned int dCount;// count of D grades
  unsigned int fCount;// count of F grades
};

// construstor initialize courseName with std::string supplied as argument
GradeBook::GradeBook(std::string &name,
  std::string teacher_name,
  const std::array<int, students> &grades_array)
: teacher_name(teacher_name),
  aCount(0), // initialize count of A grades to 0
  bCount(0), // initialize count of B grades to 0
  cCount(0), // initialize count of C grades to 0
  dCount(0), // initialize count of D grades to 0
  fCount(0),  // initialize count of F grades to 0
  grades(grades_array)
{// member initializer to initialize courseName
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
    std::cout << std::setprecision(2) << std::fixed;
    std::cout << "Class average is " << average << '\n';
  }else{
    std::cout << "No grades were entered" << '\n';
  }
}
/**
 * input arbitary number of grades from user; update grade counter
 */


void GradeBook::input_grades(){
  int grade;// grade intered by user

  std::cout << "Enter the letter geades" << '\n'
     << "Enter the EOF character to hte end input" << '\n';

  // loop until user types end-of-file key sequence
  while ((grade = std::cin.get()) != EOF) {
    // determine which grade was entered
    switch (grade) {
      case 'A':// grade was upcase 'A'
      case 'a':// or lower case a
        aCount++;// increasement aCount
        break;
      case 'B': case 'b': bCount++; break;
      case 'C': case 'c': cCount++; break;
      case 'D': case 'd': dCount++; break;
      case 'F': case 'f': fCount++; break;
      case '\n':case'\t':case' ':break;
      default:// catch all other characters
        std::cout << "Incorrect letter grade entered"
          << "Enter a new grade" <<'\n';break;
    }
  }
}

/**
 * display a report based on the grades entered by user
 */
void GradeBook::display_grade_report()const{
  // output summary of results
  std::cout << "\n\nNumbers of students who received each letter grade:"
  << "\nA: " << aCount << "\nB: " << bCount
  << "\nC: " << cCount << "\nD: " << dCount
  << "\nF: " << fCount << '\n';
}

/**
 * perform various operations on the data
 */
void GradeBook::process_grades()const{
  // output grades array
  output_grades();

  // call funstion get_average to calculate the averge grade
  std::cout << setprecision(2) << fixed;
  std::cout << "\nClass averge is "<< get_average() << '\n';

  // call funstions get_minium and get_maxium
  std::cout << "Lowest grades is "<< get_minium()
    << "\nHighist grades is "<< get_maxium()<< '\n';

  // call function output_bar_chart to print grades distribution chart
  output_bar_chart();
}

/**
 * find minium grade
 * @return lower grgade
 */
int GradeBook::get_minium()const{
  int lower_grgade = 100;

  // loop through grades array
  for(int grade: grades){
    // if current grade lower than lowcase, assign it to lower_grgade
    if (grade < lower_grgade) {
      lower_grgade = grade;
    }
  }
  return lower_grgade;
}

/**
 * find maxium grade
 * @return highest grgade
 */
int GradeBook::get_maxium()const{
  int high_grgade = 0;

  // loop through grades array
  for(int grade: grades){
    // if current grade lower than lowcase, assign it to lower_grgade
    if (grade > high_grgade) {
      high_grgade = grade;
    }
  }

  return high_grgade;
}

/**
 * determine average grade for test
 * @return average of grades
 */
double GradeBook::get_average() const{
  int total = 0;

  // sum grades in array
  for(int grade: grades){
    total += grade;
  }

  return static_cast<double>(total) / grades.size();
}


/**
 * output bar chart displaying grade distribution
 */
void GradeBook::output_bar_chart() const {
  std::cout << "\nGrade distribution: " << '\n';

  // stores frequency of grades in each range of 10 grades
  const size_t frequency_size = 11;
  array<unsigned int, frequency_size>frequency = {}; //init to 0s

  // for each grade, increasement the appropriate frequency
  for(int grade: grades){
    ++frequency[grade / 10];
  }

  // for each grade frequency, print bar in chart
  for (size_t count = 0; count < frequency_size; count++) {
    // output bar labels
    if (0 == count) {
      std::cout << " 0-9 : ";
    } else if (10 == count) {
      std::cout << "  100: ";
    } else {
      std::cout << count * 10 << "-" << count*10+9 << ": ";
    }

    for (unsigned int stars = 0; stars < frequency[count]; stars++) {
      std::cout << "*";
    }
    std::cout << '\n';
  }
}

void GradeBook::output_grades() const {
  std::cout << "The grade are: \n" << '\n';

  // output each student's grade
  for (size_t student = 0; student < grades.size(); student++) {
    std::cout << "Student"<< setw(2) << student + 1 << ":"
      <<setw(3) << grades[student] << '\n';
  }
}
