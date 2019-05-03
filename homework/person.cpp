#include <iostream>
using namespace std;


class Person{
 protected:
  string name;
  int age;
  string sex;

 public:
  Person(string n, int a, string s):name(n), age(a), sex(s){}

  void Show() const{
  cout << "name:" << name << endl;	// 显示姓名
  cout << "age:" << age << endl;	// 显示年龄
  cout << "sex:" << sex << endl;	// 显示性别
  }
};

// 教师类
class Teacher: virtual public Person {
 protected:
  string title;						// 职称
 public:
  Teacher(string n, int a, string s, string t): Person(n, a, s),title(t){}
  void Show() const{
    Person::Show();					// 调用基类Person的成员函数Show()
    cout << "title:" << title << endl;	// 显示职称
    cout << endl;
  }
};

// Cadre 干部
class Cadre: virtual public Person{
 protected:
  string post;					// 职务
 public:
  Cadre(string nm, int ag, string sx, string pt): Person(nm, ag, sx),post(pt){}
  void Show() const{
    Person::Show();					// 调用基类Person的成员函数Show()
    cout << "post:" << post << endl;	// 显示职务
    cout << endl;
  }
};

// 教师兼干部类
class TeacherCadre: public Teacher, public Cadre{
 protected:
  double wages;						// 工资
 public:
  TeacherCadre(string nm, int ag, string sx, string tl, string pt, double wg)
  : Person(nm, ag, sx),
    Teacher(nm, ag, sx, tl),
    Cadre(nm, ag, sx, pt),
    wages(wg){}						// 复制工资
  void Show() const{
  Person::Show();					// 调用基类Person的成员函数Show()
    cout << "title:" << title << endl;	// 显示职称
    cout << "post:" << post << endl;	// 显示职务
    cout << "wages:" << wages << " RMB" << endl;					// 显示工资
    cout << endl;					// 换行
  }
};

int main(){
  Teacher objTeacher("Mr.Zhang", 48, "man", "professor");			// 定义对象
  Cadre objCadre("Mr.Li", 56, "man", "dean");				// 定义对象
  TeacherCadre objTeacherCadre("Mr.wang", 50, "woman", "professor", "dean", 6890);	// 定义对象

  objTeacher.Show();					// 显示相关信息
  objCadre.Show();						// 显示相关信息
  objTeacherCadre.Show();				// 显示相关信息

  return 0;                    			// 返回值0, 返回操作系统
}
