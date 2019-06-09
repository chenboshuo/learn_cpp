/*
请使用Dev C++打开考生文件夹D:\JSJWZH\CbtesExam\VC_B001\下的proj3.cpp。
补充编制C++程序proj3.cpp，
其功能是读取文本文件in.
dat中全部内容，
将文本存放到doc类的对象myDoc中。
然后将myDoc中的字符序列反转，并输出到文件out.dat中。
文件in.dat长度不大于1000字节。
要求：
补充编制的内容写在/∥**********333**********与/∥********666*********两行之间。实现将myDoc中的字符序列反转，并将反转后的序列在文件中输出。不得修改程序的其他部分。
注意：程序最后已经将结果输出到文件out.dat中。输出函数writeToFile已经给出并且调用。
 */
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

class doc {
 private:
  char *str;   //文本字符串首地址
  int length;  //文本字符个数
 public:
  //构造函数，读取文件内容，用于初始化新对象。filename是文件名字符串首地址。
  doc(const char *filename);
  void reverse();  //将字符序列反转
  ~doc();
  void writeToFile(const char *filename);
};

doc::doc(const char *filename) {
  ifstream myFile(filename);
  int len = 1001, tmp;
  str = new char[len];
  length = 0;
  while ((tmp = myFile.get()) != EOF) { str[length++] = tmp; }
  str[length] = '\0';
  myFile.close();
}

//*************333***********
void doc::reverse() {
  for (char *i = str, *j = str + length - 1; i < j; ++i, --j) {
    char _;
    _ = *i, *i = *j, *j = _;
  }
}
//**********666*********

doc::~doc() { delete[] str; }

void doc::writeToFile(const char *filename) {
  ofstream outFile(filename);
  outFile << str;
  outFile.close();
}

int main() {
  // doc myDoc(".\\in.dat");
  doc myDoc("data/in_3");
  myDoc.reverse();
  // myDoc.writeToFile(".\\out.dat");
  myDoc.writeToFile("data/out_3");
}
