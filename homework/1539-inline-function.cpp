/**
 * 问题 F: 内联函数
时间限制: 1 Sec  内存限制: 128 MB
提交: 31  解决: 25
[提交] [状态] [讨论版] [命题人:admin]
题目描述
#include<iostream>
using namespace std;

//不允许改动程序其它地方。
//在此处添加内联函数，使得程序按要求正常输出。

int main()
{
    cout<<max(3,4)<<endl;
    cout<<max(6,5)<<endl;
    return 0;
}

Output
4
6
 */
#include <iostream>
using namespace std;

//不允许改动程序其它地方。
//在此处添加内联函数，使得程序按要求正常输出。
inline int max(int a, int b) { return a > b ? a : b; }
int main() {
  cout << max(3, 4) << endl;
  cout << max(6, 5) << endl;
  return 0;
}
