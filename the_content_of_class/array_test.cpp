// filename: array_test.cpp
// Array class test program
#include "Array.h"
#include <iostream>
#include <stdexcept>
using namespace std;

int main(int argc, char const *argv[]) {
  Array integers_1(7);
  Array integers_2;  // 10-element Array by default

  // print integers_1 sizes and contents
  cout << "Size of Array integer_1 is " << integers_1.get_size()
       << "\nArray after initialization:\n"
       << integers_1;
  // Size of Array integer_1 is 7
  // Array after initialization:
  //            0           0           0
  //            0           0           0

  // print integers_2 sizes and contents
  cout << "Size of Array integer_2 is " << integers_2.get_size()
       << "\nArray after initialization:\n"
       << integers_2;
  // Size of Array integer_1 is 7
  // Array after initialization:
  //            0           0           0
  //            0           0           0
  // Size of Array integer_2 is 10
  // Array after initialization:
  //            0           0           0           0
  //            0           0           0           0
  //            0           0

  // input and print integers_1 and integers_2
  cout << "\nEnter 17 integers" << endl;
  cin >> integers_1 >> integers_2;
  cout << "\nAfter input, the arrays contain:\n"
       << "integers_1:\n"
       << integers_1 << "integers_2:\n"
       << integers_2;
  // Enter 17 integers
  // 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7
  //
  // After input, the arrays contain:
  // integers_1:
  //            1           2           3           4
  //            5           6           7
  // integers_2:
  //            8           9           0           1
  //            2           3           4           5
  //            6           7

  // use overloaded inequality (!=) operator
  cout << "\nEvaluating: integers_2 != integers_1" << endl;
  if (integers_2 != integers_1) {
    cout << "integers_2 and integers_1 are not equal" << endl;
  }
  // Evaluating: integers_2 != integers_1
  // integers_2 and integers_1 are not equal

  // create Array integers_3 using integers_1 as an initizalizer
  // print sizes and contents
  Array integers_3(integers_1);
  cout << "\nSize of array integers_3 is" << integers_3.get_size()
       << "\nArray after initlization:\n"
       << integers_3 << endl;
  // Size of array integers_3 is7
  // Array after initlization:
  //            1           2           3           4
  //            5           6           7

  // using overladed assignment operator
  cout << "\nAssigning integers_2 to integers_1" << endl;
  integers_1 = integers_2;
  cout << "integers_1:\n"
       << integers_1 << "integers_2:\n"
       << integers_2 << endl;
  // Assigning integers_2 to integers_1
  // integers_1:
  //            8           9           0           1
  //            2           3           4           5
  //            6           7
  // integers_2:
  //            8           9           0           1
  //            2           3           4           5
  //            6           7

  // use overloaded equality (==) opertor
  cout << "\nEvaluting: integers_1  == integers_2" << endl;
  if (integers_1 == integers_2) {
    cout << "integers_1 and integers_2 are equal" << endl;
  }
  // Evaluting: integers_1  == integers_2
  // integers_1 and integers_2 are equal

  // use overloaded subscript operator to create rvalue
  cout << "\nintegers_1[5] is " << integers_1[5] << endl;
  // integers_1[5] is 3

  // use overloaded subscript operator to create lvalue
  cout << "\n\nAssigning 1000 to integers_1[5]" << endl;
  integers_1[5] = 1000;
  cout << "integers_1[5]" << integers_1[5] << endl;
  // Assigning 1000 to integers_1[5]
  // integers_1[5]1000

  // attempt to use out-of-range subscript
  try {
    cout << "\nAttempt to assign 1000 to integers_1[15]" << endl;
    integers_1[15] = 1000;
  } catch (out_of_range &ex) {
    cout << "An expection occurred: " << ex.what() << endl;
  }
  //   Attempt to assign 1000 to integers_1[15]
  // An expection occurred: Subscript out of range
  return 0;
}

// output
/*
Size of Array integer_1 is 7
Array after initialization:
           0           0           0           0
           0           0           0
Size of Array integer_2 is 10
Array after initialization:
           0           0           0           0
           0           0           0           0
           0           0

Enter 17 integers
1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7

After input, the arrays contain:
integers_1:
           1           2           3           4
           5           6           7
integers_2:
           8           9           0           1
           2           3           4           5
           6           7

Evaluating: integers_2 != integers_1
integers_2 and integers_1 are not equal

Size of array integers_3 is7
Array after initlization:
           1           2           3           4
           5           6           7


Assigning integers_2 to integers_1
integers_1:
           8           9           0           1
           2           3           4           5
           6           7
integers_2:
           8           9           0           1
           2           3           4           5
           6           7


Evaluting: integers_1  == integers_2
integers_1 and integers_2 are equal

integers_1[5] is 3


Assigning 1000 to integers_1[5]
integers_1[5]1000

Attempt to assign 1000 to integers_1[15]
An expection occurred: Subscript out of range

 */
