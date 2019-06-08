#include <iostream>

#include "Sales_item.h"
int main(int argc, char const *argv[]) {
  Sales_item item_1, item_2;
  // read ISBN,number of copies sold,and sales princee
  std::cin >> item_1 >> item_2;
  if (item_1.isbn() == item_2.isbn()) {
    // werit ISBN,number of cpoies sold,total revenue, and average princee
    std::cout << item_1 + item_2 << '\n';
    return 0;  // indicate success
  } else {
    std::cerr << "Data must refer to same ISBN" << '\n';
    return -1;  // indicate failure
  }
}
// input
// 0-201 3 20.00
// 0-201 2 25.00
// output
// 0-201 5 110 22

// input
// 12x 3 10.00
// 11x 5 25.00
// output
// Data must refer to same ISBN
