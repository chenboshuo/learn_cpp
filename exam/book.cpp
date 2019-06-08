/** 请使用Dev
Ct+打开考生文件夹D:JSJWZH\CbtesExam\VC_A001\下的proj2.cpp。
假设图书馆的图书包含书名、编号和作者属性，
读者包含姓名和借书证属性，每位读者最多可借5本书，
编写程序列出某读者的借书情况。
设计了一个类object，
从它派生出图书类book和读者类reader，
在reader类中有一个rentbook（）成员函数用于借阅图书。
部分程序代码已在文件proj2.cpp中给出，
请在横线处上适当的代码并把横线删除，使程序能实现其功能。
程序运行后的结果如下：

读者：王华（1234）所借图书：
1：C语言（100）
2：数据结构（110）注意：只需在指定位置编写适当代码，不要改动程序中的其他内容，也不能删除或移动"/**********found**********”。
 */
#include <iostream>
using namespace std;
#include <string.h>
class object {
  char name[20];
  int no;

 public:
  object() {}
  object(const char na[], int n) {
    strcpy(name, na);
    no = n;
  }
  void show() { cout << name << "(" << no << ")"; }
};

class book : public object {
  char author[10];

 public:
  book() {}
  //**********found**********
  //  reader(const char na[], int n):_____________{top = 0; }
  /* 类的继承, 子类利用父类的构造函数完成参数传递 */
  book(const char na[], int n, const char auth[]) : object(na, n) {
    strcpy(author, auth);
  }
  void showbook() {
    show();
    cout << "  作者:" << author;
  }
};
class reader : public object {
  book rent[5];
  int top;

 public:
  //**********found**********
  //  _____________ ;
  reader(const char na[], int n) : object(na, n) { top = 0; }
  void rentbook(book &b) {
    //**********found**********
    //  _____________ ;
    b.show();
    top++;
  }
  void showreader() {
    cout << "读者:";
    show();
    cout << endl << "所借图书:" << endl;
    for (int i = 0; i < top; i++) {
      cout << " " << i + 1 << ":";
      //**********found**********
      //  _____________ ;
      rent[i].show();
      cout << endl;
    }
  }
};
int main() {
  book b1("C语言", 100, "谭浩强"), b2("数据结构", 110, "严蔚敏");
  reader r1("王华", 1234);
  r1.rentbook(b1);
  r1.rentbook(b2);
  r1.showreader();
}
