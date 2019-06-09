/*
请使用Dev C++打开考生文件夹D:\JSJWZH\CbtesExam\VC_B001\下的proj3.cpp。
补充编制C++程序proj3.cpp，
其功能是从文本文件in.dat中卖取全部整数，
将整数序列存放到intArray类的对象中，
然后建立另一对象myArray，将对象内容赋值给myArray。
最后由函数writeToFile选择序列中的部分数据输出到文件out.dat中。
文件out.dat中每行一个结果。类intArray重载了“=”运算符。
文件in.dat中的整数个数不超过300
 */
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

class intArray {
 private:
  int *array;
  int length;

 public:
  intArray(const char *filename);
  intArray();
  intArray &operator=(const intArray &src);
  ~intArray();
  void writeToFile(const char *filename);
};

intArray::intArray() {
  length = 10;
  array = new int[length];
}

intArray::intArray(const char *filename) {
  ifstream myFile(filename);
  array = new int[300];
  length = 0;
  while (myFile >> array[length++])
    ;
  length--;
  myFile.close();
}

//*************333***********
intArray &intArray::operator=(const intArray &src) {
  for (int i = 0; i < length; ++i) { array[i] = src.array[i]; }
  return *this;
}

//**********666*********

intArray::~intArray() { delete[] array; }

void intArray::writeToFile(const char *filename) {
  int step = 0;
  ofstream outFile(filename);
  for (int i = 0; i < length; i = i + step) {
    outFile << array[i] << endl;
    step++;
  }
  outFile.close();
}

int main() {
  // intArray *arrayP = new intArray(".\\in.dat");
  intArray *arrayP = new intArray("data/in_2");
  intArray myArray;
  myArray = *arrayP;
  delete arrayP;
  // myArray.writeToFile(".\\out.dat");
  myArray.writeToFile("data/out_2");
}
