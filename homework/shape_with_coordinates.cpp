// filenams: shape_with_coordinates.cpp
#include <iostream>
#include <cmath>

using namespace std;
#define PI 3.1415926

class Shape {
 public:
  // 形状的中心坐标
  double x;
  double y;
  virtual double area() = 0;
  virtual double perimeter () = 0;
  Shape(double x, double y):x(x), y(y){}
};

class Circle : public Shape{
 public:
  Circle (double x, double y, double redius):Shape(x,y), redius(redius){}
  double area(){
    return PI * pow(redius,2);
  }
  double perimeter(){
    return 2 *PI * redius;
  }

 private:
  double redius;
};

class Square : public Shape{
 public:
  Square (double x, double y, double vertex_x, double vertex_y)
    : Shape(x, y){
      edge = fabs(x-vertex_x) * 2;
    };

  double area(){
    return pow(edge, 2);
  }

  double perimeter(){
    return 4*edge;
  }
 private:
  double edge;
};

int main(int argc, char const *argv[]) {
  double x0, x, y, y0, r;

  cout << "Plese input the center of a circle cordinates x y,and the redius r" << endl;
  cin >> x0 >> y0 >> r;
  Circle c(x0, y0, r);
  cout << "The area of the circle is: "<< c.area() << endl;
  cout << "The perimeter of the cirle is: " << c.perimeter() << endl;

  cout << "Please input the center of a squarecordinates x,y"
    << "and one of the vertex squarecordinates x0 y0" << endl;
  cin >> x >> y >> x0 >> y0;
  Square s(x, y, x0, y0);
  cout << "The area of square of the square is: " << s.area() << endl;
  cout << "The perimeter of the circle is: "<< s.perimeter() << endl;
  return 0;
}
/*
  Plese input the center of a circle cordinates x y,and the redius r
  0 0 1
  The area of the circle is: 3.14159
  The perimeter of the cirle is: 6.28319
  Please input the center of a squarecordinates x,yand one of the vertex squarecordinates x0 y0
  0 0 2 2
  The area of square of the square is: 16
  The perimeter of the circle is: 16
 */
