// initializing an array
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[]) {
  int n[10];// n is an array of 10 integers

  // initialize elements of array n to 0
  for (size_t i = 0; i < 10; i++) {
    n[i] = 0;
  }

  cout << "Elements" << setw(13) << "value"<<'\n';
  /*
   * setw(int n)
   * 预设宽度,规定其后内容所占宽度
   * setfill(char c)在预设宽度如果存在没用完的宽度,用c填充
   * 
   */
  // output each element's value
  for (size_t j = 0; j < 10; j++) {
    std::cout << setw(7) << j << setw(13) << n[j] << '\n';
  }
  return 0;
}
/*
Elements        value
      0            0
      1            0
      2            0
      3            0
      4            0
      5            0
      6            0
      7            0
      8            0
      9            0
 */
