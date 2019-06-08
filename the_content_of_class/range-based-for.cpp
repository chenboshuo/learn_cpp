// range-based-for.cpp
#include <array>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  array<int, 3> a = { 2, 8, 4 };
  for (int i : a) { std::cout << i << '\n'; }
  return 0;
}
// Finished in 4 ms
// 2
// 8
// 4
