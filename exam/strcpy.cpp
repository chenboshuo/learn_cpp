/*
凡用过C语言标准库函数strcpy（char*s1，char*s2）的程序员都知道使用该函数时有一个安全隐患，即当指针s1所指向的空间不能容纳字符串s2的内容时，将发生内存错误。类String的Strcpy成员函数能进行简单的动态内存管理，其内存管理策略为：
1）若已有空间能容纳下新字符串，则直接进行字符串拷贝；
2）若已有空间不够时，它将重新申请一块内存空间（能容纳下新字符串），并将新字符串内容拷贝到新申请的空间中，释放原字符串空间。
请使用Dev
C++打开考生文件夹D:\JSJWZH\CbtesExam\VC_A001\下的proj2.cpp。其中定义了类string和用于测试该类的主函数main，并且成员函数Strcpy的部分实现代码也已在该文件中给出，请在标有注释"/T0D0："的行中添加适当的代码，将这个函数补充完整，以实现其功能。
注意：只需在指定位置编写适当代码，不要改动程序中的其他内容，也不能删除或移动"//**********found**********”。
 */
#include <string.h>
#include <iostream>
using namespace std;

class String {
 private:
  int size;   // 缓冲区大小
  char *buf;  // 缓冲区
 public:
  String(int bufsize);
  void Strcpy(char *s);  // 将字符串s复制到buf中
  void Print() const;
  ~String() {
    if (buf != NULL) delete buf;
  }
};

String::String(int bufsize) {
  size = bufsize;
  buf = new char[size];
  *buf = '\0';
}

void String::Strcpy(char *s) {
  char *p, *q;
  int len = strlen(s);
  if (len + 1 > size) {
    size = len + 1;
    p = q = new char[size];
    //**********found**********
    // while (________)
    while (*q++ = *s++)  // 这里不要加括号,否则错
      ;  // TODO: 添加代码将字符串s拷贝到字符指针q中

    delete[] buf;
    buf = p;
  } else {
    //**********found**********
    // for (p = buf; ________, s++)
    for (p = buf; *p = *s; p++, s++)
      ;  // TODO: 添加代码将字符串s拷贝到buf中
  }
}

void String::Print() const { cout << size << '\t' << buf << endl; }

int main() {
  char s[100];
  String str(32);
  cin.getline(s, 99);
  str.Strcpy(s);
  str.Print();
  return 0;
}
