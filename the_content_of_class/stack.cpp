// filename: stack.cpp
// slack class template test proglam
#include <iostream>

#include "stack.h"
using namespace std;

int main(int argc, char const *argv[]) {
  Stack<double> double_stack;          // create a Stack of double
  const size_t double_slace_size = 5;  // slack
  double double_value = 1.1;           // first value to push

  cout << "Pushing elements onto double_stack" << endl;

  // push 5 doubles onto double_stack
  for (size_t i = 0; i < double_slace_size; ++i) {
    double_stack.push(double_value);
    cout << double_value << " ";
    double_value += 1.1;
  }

  cout << "\n\nPoping elements from double_stack" << endl;

  // pop elements from double_stack
  while (!double_stack.is_empty()) {
    cout << double_stack.top() << " ";  // dispaly the top element
    double_stack.pop();                 // remove the top element
  }
  return 0;
}
/*
Pushing elements onto double_stack
1.1 2.2 3.3 4.4 5.5

Poping elements from double_stack
5.5 4.4 3.3 2.2 1.1
 */
