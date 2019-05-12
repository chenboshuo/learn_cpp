# 六 虚函数与多态性（一）

## 6.1 先阅读下列程序，写出执行结果。然后输入程序，调试程序，比较结果的正确性。

``` cpp
#include <iostream>					// 预处理命令
using namespace std;					// 使用标准命名空间std

// 基类
class Base{
public:
virtual void f() {
  cout << "调用Base的f()" << endl;
}		// 虚函数
};

// 派生类
class Derived: public Base{
public:
void f() {
  cout << "调用Derived的f()" << endl;
}			// 虚函数
};

int main(){
Derived obj;						// 定义派生类对象
Base * p = &obj;					// 基类指针
p->f();							// 调用函数f()

return 0;                     		// 返回值0, 返回操作系统
}

```
我的答案
```plaintext
调用Derived的f()
```

## 6.2 先阅读下列程序，写出执行结果。然后输入程序，调试程序，比较结果的正确性。
``` cpp
#include <iostream>					// 预处理命令
using namespace std;					// 使用标准命名空间std
// 基类
class Base{
 public:
  virtual void Show() const{
    cout << "调用Base Show()" << endl;
  }	// 虚函数
};

// 派生类
class Derived: public Base{
 public:
  void Show() const{
    cout << "调用Derived Show()" << endl;
  }		// 虚函数
};

// 基类引用
void Refers(const Base &obj){			
  obj.Show();  
} 					// 调用函数Show()

int main(){
  Base obj1;							// 定义对象
  Derived obj2;						// 定义对象
  Refers(obj1);						// 调用函数Refers()
  Refers(obj2);						// 调用函数Refers()

  return 0;                    			// 返回值0, 返回操作系统
}

```
预测输出结果

```plaintext
调用Base Show()
调用Derived Show()
```

## 6.3 程序填空。请完成程序，使程序具有如下的输出：

```plaintext
168
158,158
158
```

```cpp
#include <iostream>					// 预处理命令
using namespace std;					// 使用标准命名空间std
// 基类
class Base{
 private:
  int m;							// 数据成员
 public:
  Base(int a): m(a){ }				// 构造函数
  virtual void Show() const {
    cout << m << endl;
  }		// 虚函数
};
// 派生类
class Derived: public Base{
 private:
  int n;							// 数据成员

 public:
  Derived(int a, int b): Base(a), n(a){ }				// 构造函数
  void Show() const{				// 虚函数
    cout << n << ",";				// 显示n及","
    Base::Show();				// 调用基类的Show()
  }
};

int main(){  
  Base obj1(168);					// 定义基类对象
  Derived obj2(158, 98);				// 定义派生类对象
  Base * p;							// 定义基类指针
  p = &obj1;						// 指向obj1
  p->Show();						// 调用Show()
  p = &obj2;						// 指向obj2
  p->Show();						// 调用Show()
  p->  [1]  ;						// 调用基类的Show()

  return 0;                    		// 返回值0, 返回操作系统
}
```

```plaintext
Base::show()
```

## 6.4 改正下面程序中的错误，使其能正常运行。

```cpp
#include <iostream>		// 预处理命令									
using namespace std;		// 使用标准命名空间std							

// 基类															
class A	{																
 public:	// 公有函数:														
	void ShowA() const{
    cout << "基类A" << endl;
  }
};																

// 派生类															
class B: public A	{																
 public:															
  // 公有函数:														
  void ShowB() const{
  cout << "派生类B" << endl;
  }
};																

int main(){   // 主函数main(void)							

	B obj;				// 定义派生类对象								
	A * p = &obj;			// 定义基类指针指向派生类对象					
	p->ShowB();			// 调用ShowB()								

	system("PAUSE");		// 调用库函数system( )，输出系统提示信息			
	return 0;				// 返回值0, 返回操作系统					
}																

```

```cpp
p->ShowB();			// 调用ShowB()
```
改为
```cpp
p->ShowA();
```

答案是这么改的
```cpp
virtual void Show() const{ cout << "基类A" << endl; }						 

void Show() const{ cout << "派生类B" << endl; }									 
p->Show();					// 调用Show()									
```

# 6.5 编写程序，
-   [x] 定义抽象基类Shape(形状)，
-   [x] 由它派生出2个派生类：Circle(圆形) 和Rectangle(矩形)，
-   [x] 用函数Show()分别显示各种图形的相关信息，
-   [x] 最后还要显示所有图形的总面积。

-   [学校的答案](https://github.com/chenboshuo/cpp_learning/commit/7cfbad2d802d6ce8589c39238208464f86a127fa)

## 6.6 编写程序，
-   [x] 定义抽象基类Shape(形状)，
-   [x] 由它派生出3个派生类: Circle(圆形)、Rectangle(矩形)和Square (正方形)
-   [x] 用函数函数ShowArea()分别显示各种图形的面积，
-   [x] 最后还要显示所有图形的总面积。
-   [x] 要求用基类指针数组，使它的每一个元素指向一一个派生类对象。

-   [相关修改](https://github.com/chenboshuo/cpp_learning/commit/c8d66103bf5c79eb1d7601c66ddb4712405bc0cd)

- [一个索引超范围了](https://github.com/chenboshuo/cpp_learning/commit/2941b799aaa3070954b1e941d009db5ebd8f8ff2)
