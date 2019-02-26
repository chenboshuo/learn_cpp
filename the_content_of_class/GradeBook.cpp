/** Gradebook.cpp
 * Define class GradeBook with a member function displaymessage
 * create a GradeBook object,and call its displayMessage function
 */
#include <iostream>
using namespace std;

// GradeBook class definition
class Gradebook {
public:
  // funcxtion that displays a welcome message to the GradeBook user
  void display_message() {
    cout << "Welcome to the Grade Book" << '\n';
  }
};

// funstion main begins program execution
int main(int argc, char const *argv[]) {
  Gradebook myGradeBook;// create a GradeBook object named myGradeBook
  myGradeBook.display_message(); // call object's displayMessage function
  return 0;
}
// output
// Welcome to the Grade Book
