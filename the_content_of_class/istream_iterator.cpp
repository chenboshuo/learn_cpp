// filename: istream_iterator.cpp
// Demonstrating input and output with iterators
#include <iostream>
#include <iterator>
using namespace std;

int main(int argc, char const *argv[]) {
  cout << "Enter two integers: " << endl;

  // create istream_iterator for reading int value from cin
  istream_iterator<int> input_int(cin);

  int number1 = *input_int;  // read int from standard input
  ++input_int;               // move iterator to next input value
  int number2 = *input_int;  // read int from standard input

  // create ostream_iterator for waiting int values to cout
  ostream_iterator<int> output_int(cout);

  cout << "the number is: " << endl;
  *output_int = number1 + number2;
  cout << endl;

  return 0;
}
// Enter two integers:
// 1 3
// the number is:
// 4
