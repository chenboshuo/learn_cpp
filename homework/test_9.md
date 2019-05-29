# 实验九 模板

## 9.1 先阅读下列程序，写出执行结果。然后输入程序，调试程序，比较结果的正确性。
```cpp
#include <iostream>					// 预处理命令
using namespace std;					// 使用标准命名空间std

template <class ElemType>
ElemType f(ElemType x){
  ElemType y;							// 临时变量
  y = x * (ElemType)5.8;
  return y;
}

int main(){
  cout << f(5) << endl;				// 输出f(5)
  cout << f(5.0) << endl;			// 输出f(5.0)
  return 0;                    		// 返回值0, 返回操作系统
}
```

输出预测
```plaintext
25
29
```
预测结果正确

## 9.2 先阅读下列程序，写出执行结果。然后输入程序，调试程序，比较结果的正确性。
```cpp
#include <iostream>					// 预处理命令
using namespace std;					// 使用标准命名空间std
void ShowMax(int a, int b){				// 求两个整型数的最大值
  int max = (a > b) ? a : b;			// a与b的最大值
  cout << "调用int, maxValue = " << max << endl;
}

void ShowMax(double a, double b ){		// 求两个双精度型数的最大值
  int max = (a > b) ? a : b;			// a与b的最大值
  cout << "调用double, maxValue = " << max << endl;
}

template <class ElemType1, class ElemType2>
void ShowMax(ElemType1 a, ElemType2 b){
  ElemType1 max = (a > (ElemType1)b) ? a : (ElemType1)b;		// a与b的最大值
  cout << "调用函数模板, maxValue = " << max << endl;
}

int main(){							// 主函数main(void)
  ShowMax(16, 518);				// 显示最大值
  ShowMax(16.0, 518.0);			// 显示最大值
  ShowMax(16.0, 518);				// 显示最大值
  return 0;                    		// 返回值0, 返回操作系统
}
```

结果预测
```plaintext
调用函数模板, maxValue = 518
调用double, maxValue = 518
调用double, maxValue = 518
```
错了😂😂
应该是
```plaintext
调用int, maxValue = 518
调用double, maxValue = 518
调用函数模板, maxValue = 518
```

## 9.3 程序填空。请完成下面模板类的程序，使程序能正常运行。
```cpp
#include <iostream>						// 预处理命令
using namespace std;						// 使用标准命名空间std

class A{
 private:
  int a;								// 数据成员

 public:
  A(int x): a(x){ }						// 构造函数
  virtual void Show() const{
    cout << a;
  }	// 显示a之值
};

template <class ElemType>
class B: public A{
 private:
  ElemType b;							// 数据成员
 public:
  B(int x, ElemType y): A(x), b(y){ }		// 构造函数
  void Show() const{
    A::Show();						// 调用A的Show()
    cout << " " << b << endl;			// 显示b之值
  }
};

int main()								
{
  B<  /*[1]*/  > obj(8, "is my happy digit!");	// 定义对象
  obj.Show();							// 显示相关信息
  return 0;								// 返回值0, 返回操作系统
}

```

预测
```cpp
B<char*> obj(8, "is my happy digit!");
```
可以运行😁但是有个警告
```cpp
B<string> obj(8, "is my happy digit!");
```
最好是这样
## 9.4 改正下面程序中的错误，使其能正常运行。
```cpp
#include <iostream>					// 预处理命令						
using namespace std;					// 使用标准命名空间std				

template <class ElemType>											
ElemType Max(ElemType a, ElemType b){	// 返回最大值					
  return (a > b) ? a : b;
}			

int main(){   
  cout << Max(16, 518) << endl;		// 显示最大值						
  cout << Max(16.8, 518) << endl;	// 显示最大值						
  return 0;				// 返回值0, 返回操作系统					
}				

```

```cpp
  cout << Max(16.8, 518) << endl;	// 显示最大值
```
改为
```cpp
  cout << Max(16.8, 518.0) << endl;	// 显示最大值
```
因为模板不会进行类型转换

## 9.5 编写一个使用数组类模板Array对数组进行排序、求最大值和求元素和的程序，并采用相关数据进行测试。

-   [学校的代码](https://github.com/chenboshuo/cpp_learning/commit/454c4e07d192703de20389dd8917085b36adbcef)

## 9.6 对数组进行排序、求最大值和求元素和的函数采用静态成员函数的方式封装成数组算法类模板ArrayAlg，并采用相关数据进行测试。

-   [代码](https://github.com/chenboshuo/cpp_learning/commit/6d729ab7db54ab150ea54139bc8f235fef949e34)

## 9.7 对数组进行排序、求最大值和求元素和的算法都编写为函数模板，采用相关数据进行测试。

-   [代码](https://github.com/chenboshuo/cpp_learning/commit/22930d0b288fb761777c089815ef7d05b8315c86)
