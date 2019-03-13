/**
 * 问题 E: 函数重载
时间限制: 1 Sec  内存限制: 128 MB
提交: 27  解决: 15
[提交] [状态] [讨论版] [命题人:admin]
题目描述
#include<iostream>
using namespace std;
//不允许改动程序其它地方。
//在此处添加重载函数，使得程序按要求正常输出。


int main()
{
cout<<max(4,5)<<endl;
cout<<max(45.23,2.3)<<endl;
    return 0;
}



样例输出
int compare 5
double compare 45.23
 */
#include<iostream>
using namespace std;
//不允许改动程序其它地方。
//在此处添加重载函数，使得程序按要求正常输出。
int max(int a,int b){
  if (a > b) {
    return a;
  } else {
    return b;
  }
}

double max(double a,double b){
  if (a > b) {
    return a;
  } else {
    return b;
  }
}


int main()
{
cout<<"int compare "<<max(4,5)<<endl;
cout<<"double compare "<<max(45.23,2.3)<<endl;
    return 0;
}
