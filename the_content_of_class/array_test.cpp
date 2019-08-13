// filename: array_test.cpp
// Array class test program
#include "Array.h"
#include <iostream>
#include <stdexcept>
using namespace std;

void outputArray(const Array &array_to_output);

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

  // explict 构造函数与转换运算符
  /**
   * 除了拷贝构造函数,
   * 任何单参数且不被声明为explict的构造函数可以被编译器用来进行隐式转换.
   * 构造函数中的实参会被转换为函数中定义的类对象.
   * 程序员不必使用强制类型转换运算符进行转换, 它是自动进行的.
   * 但是, 在某些情况下, 隐式转换是不受欢迎的, 或者说这种转换很容易导致错误
   */
  cout << endl;
  outputArray(integers_1);
  outputArray(3);
  return 0;
}
void outputArray(const Array &array_to_output) {
  cout << "The array received has " << array_to_output.get_size()
       << " elements. The contents are:\n"
       << array_to_output << endl;
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
/**
 * Array.h 有explict的时候报错
 * array_test.cpp: In function 'int main(int, const char**)':
 * array_test.cpp:129:15: error: invalid initialization of reference of type
 * 'const Array&' from expression of type 'int' outputArray(3);
 *                ^
 * array_test.cpp:8:6: note: in passing argument 1 of 'void outputArray(const
 * Array&)' void outputArray(const Array &array_to_output);
 *       ^~~~~~~~~~~
 *
 * 去掉之后输出结果
 * The array received has 10 elements. The contents are:
 *            8           9           0           1
 *            2        1000           4           5
 *            6           7
 *
 * The array received has 3 elements. The contents are:
 *            0           0           0
 */
