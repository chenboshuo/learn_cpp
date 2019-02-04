#include <iostream>

#include "Sales_item.h"
int main(int argc, char const *argv[]) {
  Sales_item book;
  // read ISBN,number of copies sold,and sales princee
  std::cin >> book;
  // werit ISBN,number of cpoies sold,total revenue, and average princee
  std::cout << book << '\n';
  return 0;
}
// input
// 123 5 10
// 123 5 50 10
