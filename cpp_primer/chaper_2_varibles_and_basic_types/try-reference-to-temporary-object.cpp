#include<iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  double dval = 3.14;
  const int &ri = dval;
  /**
   * Here `ri` referes to an int. Operations on `ri` will be integer operations
   * , but `dval` is a float-point number, not an integer.
   * To ensure that the object to which `ri` is bound is an `int`,
   * the compiler transforms this code into something like
   * const int temp = dval; // create a temporary const int from the double
   * const int &ri = temp; // bind ri to that temporary
   * In this case, `ri` is bound to a **temporary** object.
   * A temporary object is an unnamed object
   * created by the compiler when it needs a place
   * to store a result from evaluatong an expression.
   * C++ programmers often use the word temporary
   * as an abbreviation for temporary object.
   */
  cout << "ri:"<< ri << endl;
  cout << "dval:" << dval << endl;
  dval = 4.55;
  cout << "Afer change dval's value" << endl;
  cout << "ri:"<< ri << endl;
  cout << "dval:" << dval << endl;
  return 0;
}
/**
 * output
ri:3
dval:3.14
Afer change dval's value
ri:3
dval:4.55
 */
