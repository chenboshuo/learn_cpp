// initializing an array in a declation
#include <iomanip>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int n[10] = { 32, 27, 64, 18, 95, 14, 90, 70, 60, 37 };

  cout << "Elements" << setw(13) << "value" << '\n';
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
      0           32
      1           27
      2           64
      3           18
      4           95
      5           14
      6           90
      7           70
      8           60
      9           37
 */
