// filename: date.cpp
// #include "Date.h"
#include "Employee.h"

using namespace std;


int main(int argc, char const *argv[]) {
  // no objects exist; use class name and binary score resolution
  // operator to access static member function get_count
  cout << "Number of employees before instantiation of any objects is "
    << Employee:: get_count() << endl;


  // the following scope creates and destroys
  // Employee objects before main terminates
  {
    Employee e1("Susan", "Baker");
    Employee e2("Robert", "Jones");

    // two objects exist; call static member function get_count again
    // using the class name and the scope resolution operator
    cout << "Number of employees after objects are instantiated is "
      << Employee::get_count();

    cout << "\n\nEmployee 1: "
      << e1.get_first_name() << " " << e1.get_last_name()
      << "\nEmployee 2: "
      << e2.get_first_name() << " " << e2.get_last_name() << "\n\n";
  }

  // no objects exist, so call static member function get_count again
  // using the class name and the scope resolution operator
  cout << "\nNumber of employees after objects are deleted is "
    << Employee::get_count() << endl;
}
/**
 * 9.14 satic 类成员
类的static成员通过类访问，只在类的作用域起作用
基本类型的static成员默认为0.
类的private， public 的 static 数据成员通过类的public成员函数或类的友元函数，
没有任何类对象存在时，static依然存在。
没有类对象时，访问类public static 的成员可以通过 数据成员名加上二元作用域分辨符（：：）
没有类对象时，访问类private 或 protected 的static成员时，应提供public static成员函数
并通过 数据成员名加上二元作用域分辨符（：：）


output

Number of employees before instantiation of any objects is 0
Employee object constructor: Susan Baker
Employee object constructor: Robert Jones
Number of employees after objects are instantiated is 2

Employee 1: Susan Baker
Employee 2: Robert Jones

Employ object destructor: Jones, Robert
Employ object destructor: Baker, Susan

Number of employees after objects are deleted is 0
静态对象要在声明一次,别问我怎么知道的
 */
