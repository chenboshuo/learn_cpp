#include <iostream>

using namespace std;
class rational {
  friend inline long compare(rational a, rational b);

 public:
  //构造函数
  rational(int num = 0, int denom = 1);
  //重载比较操作符
  int operator<(rational r) const;
  int operator<=(rational r) const;
  int operator==(rational r) const;
  int operator!=(rational r) const;

 private:
  //定义一个有理数num为分母，den为分子
  long num, den;
};

inline long compare(rational a, rational b) {
  return (a.num * b.den - b.num * a.den);
}

// 构造函数
rational::rational(int num, int denom) : num(num), den(denom) {}

int rational::operator<(rational r) const { return (compare(*this, r) < 0); }

int rational::operator<=(rational r) const { return (compare(*this, r) <= 0); }

int rational::operator==(rational r) const { return (compare(*this, r) == 0); }

int rational::operator!=(rational r) const { return (compare(*this, r) != 0); }

int main(int argc, char const *argv[]) {
  rational one_third(1, 3);
  rational quarter(1, 4);
  rational half(1, 2);
  rational two_quarters(2, 4);

  cout << "1/3 < 1/4 ? " << (one_third < quarter) << endl;
  cout << "1/2 == 2/4 ? " << (half == two_quarters) << endl;
  cout << "1/2 != 2/4 ? " << (half != two_quarters) << endl;
  cout << "1/2 <= 1/3 ? " << (half <= one_third) << endl;
  return 0;
}
/*
1/3 < 1/4 ? 0
1/2 == 2/4 ? 1
1/2 != 2/4 ? 0
1/2 <= 1/3 ? 0
 */
