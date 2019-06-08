// filename:shapes.cpp
#define PI 3.1415926  // comment
#include <iostream>

#include <cmath>
using namespace std;
class Shape {
 public:
  virtual void show_data() = 0;
  virtual double area() = 0;
  virtual double volume() = 0;
};

class TwoDimShape : virtual public Shape {
 public:
  TwoDimShape(double center_x, double center_y)
      : center_x(center_x), center_y(center_y) {}
  double center_x;
  double center_y;
};

class ThreeShape : virtual public Shape {
 public:
  ThreeShape(double center_x, double center_y, double center_z)
      : center_x(center_x), center_y(center_y), center_z(center_z) {}
  double center_x;
  double center_y;
  double center_z;
};

// 圆
class Circle : public TwoDimShape {
 public:
  Circle(double center_x, double center_y, double redius)
      : TwoDimShape(center_x, center_y), redius(redius){};

  void show_data() {
    cout << "The coordinate of the center of the circle is: "
         << "(" << center_x << ", " << center_y << ")"
         << "\nThe redius of it is: " << redius << endl;
    cout << "The area is: " << area() << endl;
  }

  double area() { return PI * redius * redius; }

  double volume() { return 0; }

 private:
  double redius;
};

// 椭圆
class Elipse : public TwoDimShape {
 public:
  Elipse(double center_x, double center_y, double a, double b)
      : TwoDimShape(center_x, center_y), a(a), b(b){};

  void show_data() {
    cout << "The coordinate of the center of the ellipse is: "
         << "(" << center_x << ", " << center_y << ")"
         << "\nThe semimajor axis length of the ellipse: " << a << ", " << b
         << endl;
    cout << "The area is: " << area() << endl;
  }

  double area() { return PI * a * b; }

  double volume() { return 0; }

 private:
  double a, b;
};

// 矩形
class Rectangle : public TwoDimShape {
 public:
  Rectangle(double center_x, double center_y, double a, double b)
      : TwoDimShape(center_x, center_y), a(a), b(b){};

  void show_data() {
    cout << "The coordinate of the center of the rectangle is: "
         << "(" << center_x << ", " << center_y << ")"
         << "\nThe side of length is: " << a << ", " << b << endl;
    cout << "The area is: " << area() << endl;
  }

  double area() { return a * b; }

  double volume() { return 0; }

 private:
  double a, b;
};

// 三角形
class Triangle : public TwoDimShape {
 public:
  Triangle(double center_x, double center_y, double a, double b, double c)
      : TwoDimShape(center_x, center_y), a(a), b(b), c(c){};

  void show_data() {
    cout << "The coordinate of the center of the triangle is: "
         << "(" << center_x << ", " << center_y << ")"
         << "\nThe side of length is: " << a << ", " << b << ", " << c << endl;
    cout << "The area is: " << area() << endl;
  }

  double area() {  // 海伦公式
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
  }

  double volume() { return 0; }

 private:
  double a, b, c;
};

// 球
class Ball : public ThreeShape {
 public:
  Ball(double center_x, double center_y, double center_z, double redius)
      : ThreeShape(center_x, center_y, center_z), redius(redius){};

  void show_data() {
    cout << "The coordinate of the center of the Ball is: "
         << "(" << center_x << ", " << center_y << ", " << center_z << ")"
         << "\nThe redius of it is: " << redius << endl;
    cout << "The area is: " << area() << endl;
    cout << "The volume is: " << volume() << endl;
  }

  double area() { return 4 * PI * redius * redius; }

  double volume() { return 4.0 / 3.0 * PI * pow(redius, 3); }

 private:
  double redius;
};

// 圆柱体
class Cylinder : public ThreeShape {
 public:
  Cylinder(double center_x, double center_y, double center_z, double redius,
           double height)
      : ThreeShape(center_x, center_y, center_z),
        redius(redius),
        height(height){};

  void show_data() {
    cout << "The coordinate of the center of the Ball is: "
         << "(" << center_x << ", " << center_y << ", " << center_z << ")"
         << "\nThe redius of it is: " << redius
         << "\nThe height of it is: " << height << endl;
    cout << "The area is: " << area() << endl;
    cout << "The volume is: " << volume() << endl;
  }

  double area() { return 2 * PI * redius * height; }

  double volume() { return PI * redius * redius * height; }

 private:
  double redius, height;
};

// 长方体
class RectangularParallelepiped : public ThreeShape {
 public:
  RectangularParallelepiped(double center_x, double center_y, double center_z,
                            double a, double b, double c)
      : ThreeShape(center_x, center_y, center_z), a(a), b(b), c(c){};

  void show_data() {
    cout << "The coordinate of the center of the Ball is: "
         << "(" << center_x << ", " << center_y << ", " << center_z << ")"
         << "The edge length of a cuboid is: " << a << ", " << b << ", " << c
         << ", ";
    cout << "\nThe area is: " << area() << endl;
    cout << "The volume is: " << volume() << endl;
  }

  double area() { return 2 * (a * b + a * c + b * c); }

  double volume() { return a * b * c; }

 private:
  double a, b, c;
};

int main(int argc, char const *argv[]) {
  // test Circle
  cout << "Test a circle a(0,0) with redius 1" << endl;
  Circle a(0, 0, 1);
  a.show_data();
  /* output
    Test a circle a(0,0) with redius 1
    The coordinate of the center of the circle is: (0, 0)The redius of it is: 1
    The area is: 3.14159
   */

  // test elipse
  cout << "\n\n";
  cout << "Test an elipse a(1,1) with semimsjor axis length 1,2" << endl;
  Elipse a1(1, 1, 1, 2);
  a1.show_data();
  /* output
    Test an lipse a(1,1) with semimsjor axis length 1,2
    The coordinate of the center of the ellipse is: (1, 1)
    The semimajor axis length of the ellipse: 1, 2
    The area is: 6.28319
   */

  // test Rectangle
  cout << "\n\n";
  cout << "Test a Rectangle a(1,1) with side lengh of 1,2" << endl;
  Rectangle b(1, 1, 1, 2);
  b.show_data();
  /* outut
    Test a Rectangle a(1,1) with side lengh of 1,2
    The coordinate of the center of the reacangle is: (1, 1)
    The side of length is1, 2
    The area is: 2
   */

  // test Triangle
  cout << "\n\n";
  cout << "Test a Triangleangle a(1,1) with side lengh of 3,4,5" << endl;
  Triangle c(1, 1, 3, 4, 5);
  c.show_data();
  /* output
    Test a Triangleangle a(1,1) with side lengh of 3,4,5
    The coordinate of the center of the triangle is: (1, 1)
    The side of length is: 3, 4, 5
    The area is: 6
   */

  // test a ball
  cout << "\n\n";
  cout << "Test a Ball a(1,1,0) with redius 1" << endl;
  Ball d(1, 1, 0, 1);
  d.show_data();
  /* output
  Test a Ball a(1,1,0) with redius 1
  The coordinate of the center of the Ball is: (1, 1, 0)
  The redius of it is: 1
  The area is: 12.5664
  The volume is: 4.18879
   */

  // test a Cylinder
  cout << "\n\n";
  cout << "Test a Cylinder a(1,1,0) with redius 1 and height 10" << endl;
  Cylinder e(1, 1, 0, 1, 10);
  e.show_data();
  /* output
          Test a Cylinder a(1,1,0) with redius 1 and height 10
          The coordinate of the center of the Ball is: (1, 1, 0)
          The redius of it is: 1
          The height of it is: 10
          The area is: 62.8319
          The volume is: 31.4159
   */

  // test a RectangularParallelepiped
  cout << "\n\n";
  cout << "Test a Cylinder a(1,1,0) with edge 5, 6, 7" << endl;
  RectangularParallelepiped f(1, 1, 0, 5, 6, 7);
  f.show_data();
  /* output
          Test a Cylinder a(1,1,0) with edge 5, 6, 7
          The coordinate of the center of the Ball is: (1, 1, 0)The edge length
     of a cuboid is: 5, 6, 7, The area is: 214 The volume is: 210
   */

  return 0;
}
/* output
        Test an elipse a(1,1) with semimsjor axis length 1,2
        The coordinate of the center of the ellipse is: (1, 1)
        The semimajor axis length of the ellipse: 1, 2
        The area is: 6.28319


        Test a Rectangle a(1,1) with side lengh of 1,2
        The coordinate of the center of the rectangle is: (1, 1)
        The side of length is: 1, 2
        The area is: 2


        Test a Triangleangle a(1,1) with side lengh of 3,4,5
        The coordinate of the center of the triangle is: (1, 1)
        The side of length is: 3, 4, 5
        The area is: 6


        Test a Ball a(1,1,0) with redius 1
        The coordinate of the center of the Ball is: (1, 1, 0)
        The redius of it is: 1
        The area is: 12.5664
        The volume is: 4.18879


        Test a Cylinder a(1,1,0) with redius 1 and height 10
        The coordinate of the center of the Ball is: (1, 1, 0)
        The redius of it is: 1
        The height of it is: 10
        The area is: 62.8319
        The volume is: 31.4159


        Test a Cylinder a(1,1,0) with edge 5, 6, 7
        The coordinate of the center of the Ball is: (1, 1, 0)The edge length of
   a cuboid is: 5, 6, 7, The area is: 214 The volume is: 210
 */
