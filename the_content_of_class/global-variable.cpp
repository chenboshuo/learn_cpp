/**
 * 使用全局变量
 */
#include <iostream>

int x = 1;

int main(int argc, char const *argv[]) {
  int x = 5;
  std::cout << "the local variable" << '\n';
  std::cout << x << '\n';

  std::cout << "the global variable" << '\n';
  std::cout << ::x << '\n';
  return 0;
}
/**
 * the local variable
 * 5
 * the global variable
 * 1
 */
