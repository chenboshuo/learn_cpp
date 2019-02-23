#include <iostream>
/* program for illstration only:It is bad style for a function
 * to use a global variable and also defined a local variable with the same name
 */
int reused = 42; // reused has global scope
int main(int argc, char const *argv[]) {
  int unique = 0; // unique has a block scope


  std::cout << "output#1:" << reused << " " << unique << '\n';
  // uses global reused
  // output#1:42 0

  int reused = 0;
  std::cout << "output#2:" << reused << " " << unique << '\n';
  // use local reused
  // output#2:0 0

  std::cout << "output#3:" << ::reused << " " << unique << '\n';
  // explicitly requests the global reused
  // output#3:42 0
  return 0;
}
