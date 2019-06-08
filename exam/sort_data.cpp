/*
已知数据文件IN.DAT中存有200个四位数的数据，
每个数据间用空格分隔，
并已调用成员读函数getdata（）把这些数据存入数据成员A[]中，
请考生编写成员函数funSort（）实现
从数据成员A[]的头开始，
依次每20个数的平均值组成一个新数，
这样可以获得10个新数并存入数据成员B[]中，
接着把数据成员B[]中的数按从小到大的顺序重新存入数据成员B[]中。
最后调用成员输出函数putdata（）把数据成员B[]中的结果输出到文件0UT.DAT中。
请使用Dev C++打开考生文件夹
D:JSJWZH\CbtesExam\VC_B001\下的proj3.cpp。
类Sample已经给定考生不得修改，
考生仅在函数funSort中编写若干的程序行。
请勿改动数据文件IN.DAT中的任何数据、类Samp1e结构、
主函数main（）、成员读函数getdata（）和成员写函数putdata（）的内容。
 */
#include <fstream>
#include <iostream>
using namespace std;
#define Max 200
class Sample {
  int A[Max];
  double B[10];

 public:
  Sample() {
    for (int i = 0; i < 10; i++) B[i] = 0;
  }
  int getNumberA(Sample s, int k) { return s.A[k]; }
  double getNumberB(Sample s, int k) { return s.B[k]; }
  void getdata(Sample &s);  // 读数据函数
  void funSort(Sample &s);  // 要求考生编写的函数
  void putdata(Sample &s);  // 写结果函数
};
void Sample::funSort(Sample &s) {
  for (int i = 0; i < Max; ++i) { B[i / 20] += A[i] * 1.0 / 20; }
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 9 - i; ++j) {
      if (B[j] > B[j + 1]) {
        double _;
        _ = B[j], B[j] = B[j + 1];
        B[j + 1] = _;
      }
    }
  }
}
int main() {
  int i;
  Sample s;
  s.getdata(s);
  // cout << "读取的数据如下:" << endl;
  cout << "Data:" << endl;
  for (int i = 0; i < Max; i++) {
    cout << s.getNumberA(s, i) << " ";
    if ((i + 1) % 10 == 0) cout << endl;
  }
  cout << endl;
  s.funSort(s);
  s.putdata(s);
  // cout << "输出结果:" << endl;
  cout << "outcome:" << endl;
  for (i = 0; i < 10; i++) cout << s.getNumberB(s, i) << " ";
  cout << endl;
}
//***********以下请考生不要修改************
void Sample::getdata(Sample &s)  // 从数据文件中读取数据
{
  fstream fp;
  // fp.open(".\\in.dat", ios::in);
  fp.open("data/in_1", ios::in);
  for (int i = 0; i < Max; i++) fp >> s.A[i];
  fp.close();
}
void Sample::putdata(Sample &s)  // 写结果文件
{
  fstream fp;
  // fp.open(".\\out.dat", ios::out);
  fp.open("data/out_1", ios::out);
  for (int i = 0; i < 10; i++) fp << s.B[i] << endl;
  fp.close();
}
