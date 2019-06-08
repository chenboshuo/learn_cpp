/**
 * #include<iostream>
using namespace std;
//不允许改动程序其它地方。
//定义相关函数，实现三个整数相加，合理设置参数默认值，使得程序按要求正常输出。
int main()
{
    cout<<add(1,4)<<endl;
    cout<<add(3)<<endl;
    cout<<add(1,2,3)<<endl;
    return 0;
}

output
10
10
6
 */

#include <iostream>
using namespace std;
//不允许改动程序其它地方。
//定义相关函数，实现三个整数相加，合理设置参数默认值，使得程序按要求正常输出。
int add(int a, int b = 2, int c = 5) { return a + b + c; }
int main() {
  cout << add(1, 4) << endl;
  cout << add(3) << endl;
  cout << add(1, 2, 3) << endl;
  return 0;
}
