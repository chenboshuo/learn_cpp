# 虚函数与多态性（二）

## 7.1 上机分析下面程序，掌握抽象类、纯虚函数以及动态绑定

```cpp
// shape.h文件 定义抽象基类Shape
#ifndef SHAPE_H
#define SHAPE_H
class Shape {
 public:
	virtual double Area() const {
		return 0.0;
	}
	// 纯虚函数，在派生类中重载
	virtual void PrintShapeName() const = 0;
	virtual void Print() const = 0;
};
#endif

// point.h文件 定义类 Point
#ifndef POINT_H
#define POINT_H
#include <iostream>
#include "shape.h"
using namespace std;
class Point : public Shape{
  int x, y;       //点的x和y坐标
 public:
	Point( int = 0, int = 0 );      // 构造函数
	void SetPoint( int a, int b );   // 设置坐标

  // 取x坐标
	int GetX() const{
    return x ;
  }

  // 取y坐标
	int GetY() const{
    return y;
  }
	virtual void PrintShapeName() const{
    cout << "Point: "; 	
  }
	virtual void Print() const;	//输出点的坐标
};
#endif

// Point.cpp文件  Point类的成员函数定义
#include <iostream>
#include "point.h"
using namespace std;
Point::Point( int a, int b ) : x( a ), y( b ){}

void Point::SetPoint(int a, int b ){  
  x = a; y = b;
}

void Point::Print() const{  
  cout << '[' << x << ", " << y << ']';  
}

// circle.h定义类 Circle
#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include "point.h"
using namespace std;

class Circle : public Point{    
  double radius;
 public:
  Circle(int x = 0, int y = 0, double r = 0.0);
  void SetRadius( double r );   //设置半径
  double GetRadius() const;   //取半径
  virtual double Area() const;  //计算面积a
  virtual void Print() const;    //输出圆心坐标和半径
  virtual void PrintShapeName() const{   
    cout << "Circle: "; 	
  }
};
#endif

// circle.cpp文件  circle类的成员函数定义
#include "circle.h"
Circle::Circle(int a,int b,double r): Point(a,b), radius(r){}

void Circle::SetRadius( double r ){   
  radius = ( r >= 0 ? r : 0 );  
}

double Circle::GetRadius() const{    	
  return radius;
}

double Circle::Area() const{  
  return 3.14159 * radius * radius;
}

void Circle::Print() const{    	
  cout << "Center = ";
	Point::Print();
	cout << "; Radius = " << radius << endl;
}

//main.cpp文件 演示图形类
#include <iostream>
#include "shape.h"
#include "point.h"
#include "circle.h"
using namespace std;
void virtualViaPointer( const Shape * );
void virtualViaReference( const Shape & );

int main(){
  //创建point、circle对象
  Point point(30,50);
  Circle circle(120,80,10.0);

  //输出point、circle、rectangle对象信息
  point.PrintShapeName();
  point.Print();
  cout << endl;
  circle.PrintShapeName();
  circle.Print();

  //定义基类对象指针
  Shape * arrayOfShapes[2];
  arrayOfShapes[0] = &point;
  arrayOfShapes[1] = &circle;

  //通过基类对象指针访问派生类对象
  cout << "Virtual function calls made off " << "base-class pointers\n";
  for (int i = 0; i < 2; i++ ){
    virtualViaPointer( arrayOfShapes[i] );  	
  }

  cout << "Virtual function calls made off " << "base-class references\n";

  for ( int j = 0; j < 2; j++ ){   virtualViaReference( *arrayOfShapes[j] );
  }

  return 0;
}

//通过基类对象指针访问虚函数实现动态绑定
void virtualViaPointer( const Shape *baseClassPtr ){    	
  baseClassPtr->PrintShapeName();
  baseClassPtr->Print();
  cout << "Area = " << baseClassPtr->Area() << endl;
}
//通过基类对象引用访问虚函数实现动态绑定
void virtualViaReference(const Shape &baseClassRef){    
  baseClassRef.PrintShapeName();
  baseClassRef.Print();
  cout << "Area = " << baseClassRef.Area() << endl;
}

```

## 7.2 练习动态绑定
-   [ ] 定义一个类Base，该类含有虚函数display，
-   [ ] 然后定义它的两个派生类FirstB和SceondB，
-   [ ] 这两个派生类均含有公有成员函数display，
-   [ ] 再主程序中定义指向基类Base的指针变量ptr，
-   [ ] 并分别定义Base、FirstB和SceondB的对象，
-   [ ] 让ptr分别指向这三个对象的地址，
-   [ ] 然后执行这些对象的display函数，观察结果。

## 7.3 上机完成下面实验
-   [ ] 声明一个Shape（形状）基类，它有两个派生类：
Circle（圆）和Square（正方形），要求利用多态性的概念，
分别以虚函数的形式完成对圆和正方形的周长及面积的计算。

-   [ ] 要求：Shape类的数据成员包括中心点的坐标，Circle类和Square类初始值分别给出：
-   [ ] 圆的圆心和半径；正方形的中心和一个顶点。

## 7.4 上机完成下面实验
-   [ ] 声明ThreeDimShape类（三维图形），它有两个派生类：Ball（球体）和Cylinder（圆柱体），
-   [ ] 要求利用多态性的概念，分别以虚函数的形式完成对球体和圆柱体的体积及表面积的计算。
-   [ ] 要求：ThreeDimShape类无数据成员，只给出两个纯虚函数；
-   [ ] Ball类的初始值给出球体球心和球体半径；
-   [ ] Cylinder类初始值给出圆柱体底面圆的圆心、半径和圆柱体高。

## 7.5 设计一个计算图形面积的类库
类库顶层是一个抽象类，并且提供三个纯虚函数；显示数据成员、返回面积和返回体积。

```cpp
Class Shape
{
	virtual void showData()=0;
	virtual double reArea()=0;
	virtual double reVolume()=0;
};
```

-   [ ] 第二层由Shape类派生TwoDimShape（二维图形）和ThreeShape（三维图形），它们增加了有关的数据成员，但没有成员函数的实现。
-   [ ] 第三层派生具体的图形类。TwoDimShape类派生Circle（圆）、Elipse（椭圆）、Rectangle（矩形）和Triangle（三角形）等类。ThreeShape类派生Ball（球体）、Cylinder（圆柱体）、RectangularParallelepiped（长方体）等类。
-   [ ] 在主函数测试中使用多态方式调用不同对象的求值函数。

## 7.7 完成一个类，用来描述时间段，
包括小时和分钟，
重载各种运算符，
完成时间段的加减以及赋值。

## 7.8 用运算符重载的方法重写实验三中第6个实验中的分数类。
-   [ ] 代码

## 7.10 上机分析下面程序，理解最基本的异常处理机制
```cpp
include <iostream>
using namespace std;
void trigger(int code){
	try	{
		if (code==0){
			throw code;
		}
		if (code==1){
			throw 'x';
		}
		if (code==2){
			throw 3.14;
		}
	}
	catch(int i){
		cout<<"Catch integer  "<<i<<endl;
	}
	catch(...){
		cout<<"Catch default"<<endl;
	}
	return;
}
int main()
{
	trigger(0);
	trigger(1);
	trigger(2);
	return 0;
}
```
