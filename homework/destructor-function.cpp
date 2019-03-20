/**
 * 问题 E: 析构函数
时间限制: 1 Sec  内存限制: 128 MB
提交: 20  解决: 16
[提交] [状态] [讨论版] [命题人:admin]
题目描述
#include <iostream>
using namespace std;
class A
{
public:
A()
{
cout<<"构造函数"<<endl;
}
//增加代码

};
int main()
{
    A a;
    A *p = new A();
    //添加一行代码
cout<<"end of main"<<endl;
    return 0;
}

样例输出
构造函数
构造函数
析构函数
end of main
析构函数
 */

#include <iostream>
using namespace std;
class A
{
public:
A()
{
  cout<<"构造函数"<<endl;
}
~A(){
  cout<<"析构函数"<<endl;
}
//增加代码

};
int main()
{
    A a;
    A *p = new A();

    delete p;//添加一行代码

cout<<"end of main"<<endl;
    return 0;
}
