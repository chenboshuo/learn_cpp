// filename: shape.cpp
#include <iostream>						// 预处理命令
using namespace std;						// 使用标准命名空间std
const double PI = 3.1415926;				// 常量PI

//  形状类
class Shape{
 public:
  virtual void show_area() const = 0;				// 纯虚函数
  static double sum;						// 静态数据成员
};

//  形状类之圆形类
class Circle: public Shape{
 private:
  double radius;						// 半径
 public:
  Circle(double r): radius(r){				// 构造函数
    sum += PI * radius * radius;
  }
  void show_area() const{						// 显示圆形相关信息
  cout << "Roundness: " << endl;
  cout << "\tRadius: " << radius << endl;	// 显示半径
  cout << "\n\tArea:" << PI * radius * radius << endl;		// 显示面积
  }
};

// 形状类之矩形类
class Rectangle: public Shape{
 private:
  double height;						// 高
  double width;						// 宽
 public:
  Rectangle(double h, double w): height(h), width(w){			// 构造函数
    sum += height * width;
  }
  void show_area() const{								// 显示矩形相关信息
  cout << "Rectangle: " << endl;
  cout << "\theight:" << height << endl;			// 显示高
  cout << "\twidth:" << width << endl;			// 显示宽
  cout << "\n\tArea:" << height * width << endl;	// 显示面积
  }
};

class Square: public Shape{
 private:
  double length;					// 边长
 public:
  Square(double l): length(l){			// 构造函数
    sum += length * length;
  }
  void show_area() const{								// 显示矩形相关信息
  cout << "Rectangle: " << endl;
  cout << "\tlength:" << length << endl;			// 显示高
  cout << "\n\tArea:" << length * length << endl;	// 显示面积
  }
};

double Shape::sum = 0;					// 为静态数据成员赋初值

int main(){
  char flag = 'Y';					// 判断是否继续录入的标志, 初始化为'Y'
  Shape *p[3];							// 基类的指针数组            //
  while (toupper(flag) == 'Y'){
    cout << "Please input:\n\t1 stands for Roundness\n";
    cout << "\t2 stands for Rectangle" << endl;
    cout << "\t3 stands for Square" << endl;
    int select;		 				// 临时变量
    cin >> select;					// 输入选择

  switch (select){
    case 1:							// 圆形
      double r;					// 半径
      cout << "Please input radius:";
      cin >> r;					// 输入半径
      p[0] = new Circle(r);			// 生成圆对象
      p[0]->show_area();					// 显示相关信息
      break;
    case 2:							// 矩形
      double h, w;					// 高宽
      cout << "Please input height: ";
      cin >> h;					// 输入高
      cout << "Please input width: ";
      cin >> w;					// 输入宽
      p[1] = new Rectangle(h, w);		// 生成矩形对象
      p[1] -> show_area();					// 显示相关信息
      break;
    case 3:
      double l;
      cout << "Please input the length: " << endl;
      cin >> l;
      p[2] = new Square(l);
      p[2] -> show_area();
      break;
    default:							// 其它情况, 表示选择有误
      cout << "Error"<< endl;
    break;
  }

  cout << endl << "Do you want continue? (Y/N)";
  cin >> flag;
  }
  cout << "total Area:" << Shape::sum << endl;

system("PAUSE");            			// 调用库函数system( ),
return 0;                    			// 返回值0, 返回操作系统
}
/*
Please input:
        1 stands for Roundness
        2 stands for Rectangle
1
Please input radius:1
Roundness:
        Radius: 1

        Area:3.14159

Do you want continue? (Y/N)y
Please input:
        1 stands for Roundness
        2 stands for Rectangle
2
please input height: 3
please input width: 5
Rectangle:
        height:3
        width:5

        Area:15

Do you want continue? (Y/N)y
Please input:
        1 stands for Roundness
        2 stands for Rectangle
        3 stands for Square
3
Please input the length:
6
Rectangle:
        length:6

        Area:36
Do you want continue? (Y/N)n
total Area:54.1416
 */
