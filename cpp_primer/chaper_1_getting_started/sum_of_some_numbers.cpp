#include "iostream"
int main(int argc, char const *argv[]) {
  int sum = 0, value = 0;
  // read until end-of-file,calculating a running total of all values read
  while (std::cin >> value) sum += value;
  std::cout << "Sum  is " << sum << std::endl;
  return 0;
}
