#include <iostream>

#include "Sales_item.h"
int main(int argc, char const *argv[]) {
  Sales_item total;  // varible to hold data from the nest transaction
  // rad the first transaction and ensure that here are data to process
  if (std::cin >> total) {
    Sales_item trans;  // varible to hold the running sum
    // read and process the remain transactions
    while (std::cin >> trans) {
      // if we're still processing the same book
      if (total.isbn() == trans.isbn()) {
        total += trans;  // update the running total
        /* code */
      } else {
        // print the result of privious book
        std::cout << total << '\n';
        total = trans;  // total now refers to the next book
      }
    }
    std::cout << total << '\n';  // print the last transaction
  } else {
    // no input! warn the user
    std::cerr << "No data?!" << '\n';
    return -1;  // indicate failure
  }
  return 0;
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
// 12x 3 30 10
// input
// 11x 1 10
// output
// 11x 6 135 22.5

// input

// input
// ^Z
// output
// No data?!
