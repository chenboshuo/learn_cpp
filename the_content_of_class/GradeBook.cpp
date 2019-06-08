/** Gradebook.cpp
 * GradeBook object using a two-dimensional array of grades
 */
#include "Gradebook.h"
#include <array>
using namespace std;

// funstion main begins program execution
int main(int argc, char const *argv[]) {
  // two-dimensional array of students grades
  array<array<int, GradeBook::tests>, GradeBook::students> grades = {
    87, 96, 70, 68, 87, 90, 94, 100, 90,  100, 81, 82, 83, 65, 86,
    78, 87, 65, 85, 75, 83, 91, 94,  100, 76,  76, 84, 87, 93, 73
  };
  std::string courseName = "CS101 C++ programing";
  GradeBook myGradeBook(courseName, "yourself", grades);

  myGradeBook.display_message();  // display welcome messages
  myGradeBook.process_grades();
}
/* output
Welcome to the Grade Book for
CS101 C++ programing


The grades are:

            Test 1 Test 2 Test 3 Average
Student 1      87      96      70    84.33
Student 2      68      87      90    81.67
Student 3      94     100      90    94.67
Student 4     100      81      82    87.67
Student 5      83      65      86    78.00
Student 6      78      87      65    76.67
Student 7      85      75      83    81.00
Student 8      91      94     100    95.00
Student 9      76      76      84    78.67
Student10      87      93      73    84.33
Lowest in the gradebook is 65
Highist in the gradebook is 100

Overall grade distribution:
 0-9 :
10-19:
20-29:
30-39:
40-49:
50-59:
60-69: ***
70-79: ******
80-89: ***********
90-99: *******
  100: ***
*/
