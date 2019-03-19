#include <iostream>

void fiddle(int &a){// fiddle : 瞎搞
  a += 100;
  std::cout << "the value of a in function is: "<< a << '\n';//105
}
int main(int argc, char const *argv[]) {
  int a = 5;
  std::cout << "the initial value of a is" << a << '\n';//5
  fiddle(a);
  std::cout << "the value of a after the function is: "<< a << '\n';// 105
  return 0;
}
