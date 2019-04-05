#include<iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int ival = 1024;
  int *pi = &ival;
  int **ppi = &pi;

  cout << "The value of ival\n"
    << "direct value:\n" << ival << '\n'
    << "indirect value:\n" << *pi << '\n'
    << "double in direct value\n" << **ppi
    <<endl;
  return 0;
}
/**
 *  output
The value of ival
direct value:
1024
indirect value:
1024
double in direct value
1024
 */
