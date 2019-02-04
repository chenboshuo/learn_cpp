#include <iostream>

#include "Sales_item.h"
int main(int argc, char const *argv[]) {
  Sales_item item_1, item_2;
  // read ISBN,number of copies sold,and sales princee
  std::cin >> item_1 >> item_2;
  // werit ISBN,number of cpoies sold,total revenue, and average princee
  std::cout << item_1 + item_2 << '\n';
  return 0;
}
// input
// 0-201 3 20.00
// 0-201 2 25.00
// output
// 0-201 5 110 22
