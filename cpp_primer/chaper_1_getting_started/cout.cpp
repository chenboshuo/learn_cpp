#include "iostream"
int main(int argc, char const *argv[]) {
  // currval is the number we're counting;We'll read new values into val
  int currval = 0, val = 0;
  // read first number and ensure that we have data to process
  if (std::cin >> currval) {
    int cnt = 1;  // store the count for the current value we're processing
    while (std::cin >> val) {  // read the ramain numbers
      if (val == currval) {    // if the values are the same
        ++cnt;                 // add 1 to cnt
      } else {  // Otherwise,print the count for the previous value
        std::cout << currval << " occurs " << cnt << " times " << std::endl;
        currval = val;
        cnt = 1;
      }
    }  // while loop ends here
    // remember to print the count for the last value in the file
    std::cout << currval << " occurs " << cnt << " times " << std::endl;
  }  // outermost is statement here
  return 0;
}
// Input
// 42 42 42 42 42 55 55 62 100 100 100^Z
// Output
// 42 occurs 5 times
// 55 occurs 2 times
// 62 occurs 1 times
// 100 occurs 3 times
