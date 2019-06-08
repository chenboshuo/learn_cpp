/**
 * 定义一个函数hypotenuse，用于计算已知直角三角形的两条直角边长时计算斜边的长。
 * 该函数有个double型参数，并返回double类型边长
 * 计算
 * | 三角形 | 边1 | 边2  |
 * |:------ |:--- | ---- |
 * | 1      | 3.0 | 4.0  |
 * | 2      | 5.0 | 12.0 |
 * | 3      | 8.0 | 15.0 |
 */
#include <cmath>
#include <iostream>

class RightTriangle {
 private:
  double side_a = 0;  // 直角边
  double side_b = 0;  // 直角边
  double side_c = 0;  // 斜边

 public:
  /**
   * 设定三条边
   * @param a 直角边
   * @param b 直角边
   */
  void setSides(double a, double b) {
    side_a = a;
    side_b = b;
    side_c = sqrt(a * a + b * b);
  }

  double get_hypotenuse() {
    if (!side_c) {
      std::cerr << "Please set the legs" << '\n';
      return -1;
    }
    return side_c;
  }
};

int main(int argc, char const *argv[]) {
  RightTriangle right_triangle_1, right_triangle_2, right_triangle_3;
  right_triangle_1.setSides(3, 4);
  right_triangle_2.setSides(5, 12);
  right_triangle_3.setSides(8, 15);

  std::cout << "the right trianngle with legs of 3,4 is: "
            << right_triangle_1.get_hypotenuse() << '\n';
  std::cout << "the right trianngle with legs of 5,12 is: "
            << right_triangle_2.get_hypotenuse() << '\n';
  std::cout << "the right trianngle with legs of 8,15 is: "
            << right_triangle_3.get_hypotenuse() << '\n';

  return 0;
}
