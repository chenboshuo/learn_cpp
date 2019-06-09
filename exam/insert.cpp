/*
请使用Dev C++打开考生文件夹D:JSJWZH\CbtesExam\VC_A001\下的proj2.cpp。
其中定义了模板函数insert（T dataset[]，int&size，Titem）和主函数main。
模板函数insert用来将一个数据item插入到一个已排好序（升序）的数据集dataset中，
其中类型T可以为int，double，char等数据类型，
size为当前数据集中元素的个数，当插入操作完成后，size值将更新。
模板函数insert的部分实现代码已在文件proj2.cpp中给出，
请在标有注释"//TOD0："的行中添加适当的代码，将这个模板函数补充完整，以实现其功能。
注意：只需在指定位置编写适当代码，不要改动程序中的其他内容，
也不能删除或移动"//*********found**********”。
*/
#include <iostream>
using namespace std;

//请在该部分插入insert函数模板的实现
template<typename T> void insert(T setdata[], int &size, T item) {
  for (int i = 0; i < size; i++)
    //**********found**********
    // if (____________) {
    if (setdata[i] > item) {
      // TODO: 添加代码，判断查找元素的插入位置

      for (int j = i; j < size; j++)
        //**********found**********
        //  ________;
        setdata[size - j + i] = setdata[size - j + i - 1];
      // TODO: 添加一条语句，将插入位置后的所有元素往后移动一个位置
      // 提示：移动元素应从最后一个元素开始移动
      setdata[i] = item;
      // 插入该元素
      size++;
      return;
    }
  //**********found**********
  // ________;
  setdata[size] = item;
  // TODO: 添加一条语句，将元素加到最后一个位置上
  size++;
  return;
}
int main() {
  int idata[10] = { 22, 35, 56, 128 }, iitem, isize = 4, dsize = 4, i;
  double ddata[10] = { 25.1, 33.5, 48.9, 75.3 }, ditem;
  cout << "Please input one integer number for inserting:";
  cin >> iitem;
  insert(idata, isize, iitem);
  for (i = 0; i < isize; i++) cout << idata[i] << ' ';
  cout << endl;
  cout << "Please input one double number for inserting:";
  cin >> ditem;
  insert(ddata, dsize, ditem);
  for (i = 0; i < dsize; i++) cout << ddata[i] << ' ';
  cout << endl;
  return 0;
}
