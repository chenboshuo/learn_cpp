/**
 * 6.27 找最小数
 * 编写一个程序, 输入三个双精度浮点数,并且把他们传递给返回最小值的函数
 */
#include <iostream>
double min(double a, double b){
  return a > b ? b:a;
}

int main(int argc, char const *argv[]) {
  double a,b,c;
  std::cout << "Enter the first number:" << '\n';
  std::cin >> a;

  std::cout << "Enter the second number:" << '\n';
  std::cin >> b;

  std::cout << "Enter the third number:" << '\n';
  std::cin >> c;

  std::cout << "\nThe minium of "<< a << ", " << b << ", " << c << " is:\n"
    << min(a,min(b,c)) << '\n';
  return 0;
}
