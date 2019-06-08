// filename: three-dim-shape.cpp
#include <iostream>

using namespace std;
#define PI 3.1415926  // comment
class ThreeDimShape {
 public:
  virtual void show_volum() = 0;
  virtual void show_suprtfical_area() = 0;
};

class Ball : public ThreeDimShape {
 public:
  Ball(double redius) : redius(redius){};
  void show_volum() {
    cout << "The volum of the ball is: "
         << (PI * redius * redius * redius * 4.0) / 3.0 << endl;
  }

  void show_suprtfical_area() {
    cout << "The suprtifical area of the ball is: " << 4 * PI * redius * redius
         << endl;
  }

 private:
  double redius;
};

class Cylinder : public ThreeDimShape {
 public:
  Cylinder(double redius, double height) : redius(redius), height(height){};

  void show_volum() {
    cout << "The volum of the Cylinder is: " << PI * redius * redius * height
         << endl;
  }
  void show_suprtfical_area() {
    cout << "The suprtfical area is: " << 2 * PI * redius * redius * height
         << endl;
  }

 private:
  double redius;
  double height;
};

int main(int argc, char const *argv[]) {
  double redius;
  double height;

  cout << "Please input the redius of a ball: ";
  std::cin >> redius;
  Ball a(redius);
  a.show_volum();
  a.show_suprtfical_area();

  cout << "Please input the redius of a Cylinder: ";
  std::cin >> redius;
  cout << "Please input the height of a Cylinder: ";
  std::cin >> height;

  Cylinder b(redius, height);
  b.show_volum();
  b.show_suprtfical_area();
  return 0;
}
/*
  Please input the redius of a ball: 3
  The volum of the ball is: 113.097
  The suprtifical area of the ball is: 113.097
  Please input the redius of a Cylinder: 1
  Please input the height of a Cylinder: 1
  The volum of the Cylinder is: 3.14159
  The suprtfical area is: 6.28319
 */
