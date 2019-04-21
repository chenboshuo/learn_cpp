#include <iostream>							// 预处理命令
using namespace std;							// 使用标准命名空间std

// 复数类
class Complex
{
 private:
  double realPart;							// 实部
  double imagePart;							// 虚部

 public:
  Complex(double real = 0, double image = 0): realPart(real), imagePart(image){ }	   double GetRealPart() const{ return realPart; }
  double GetImagePart() const{ return imagePart; }

  // 重载加法运算符
  Complex operator+(const Complex &a) const{
    Complex b;									// 定义复数对象
    b.realPart = this->realPart + a.realPart;		// 和的实部
    b.imagePart = this->imagePart + a.imagePart;	// 和的虚部
    return   b  ;								// 返回和
  }
};

int main()
{
  Complex a(1, 2), b(2, 6), c;		// 定义复数对象

  c = a + b;							// 复数加法运算
  cout << "a=" << a.GetRealPart() << "+" << a.GetImagePart() << "i" << endl;
  cout << "b=" << b.GetRealPart() << "+" << b.GetImagePart() << "i" << endl;
  cout << "c=" << c.GetRealPart() << "+" << c.GetImagePart() << "i" << endl;

  return 0;                    	// 返回值0, 返回操作系统
}
/*
a=1+2i
b=2+6i
c=3+8i
 */
