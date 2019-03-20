/**
 * 问题 D: 构造-析构函数
时间限制: 1 Sec  内存限制: 128 MB
提交: 19  解决: 16
[提交] [状态] [讨论版] [命题人:admin]
题目描述
#include <iostream>
using namespace std;
class A
{
//定义类的成员，使得结果输出正确
};
int main()
{
    A a(1),b(2);
cout<<"end of main"<<endl;
    return 0;
}


样例输出
1--->构造函数
2--->构造函数
end of main
2--->析构函数
1--->析构函数
 */

#include <iostream>
using namespace std;

class A
{
private:
  int n;
public:
  A(int a){
    n = a;
    std::cout << a << "--->构造函数"<< '\n';
  };

  ~A(){
    std::cout << n << "--->析构函数"<< '\n';
  }
};
int main()
{
    A a(1),b(2);
cout<<"end of main"<<endl;
    return 0;
}
// 1--->构造函数
// 2--->构造函数
// end of main
// 2--->析构函数
// 1--->析构函数
