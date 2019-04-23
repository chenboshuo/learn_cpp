# 实验四 函数重载与运算符重载

## 4.1.先阅读下列程序，写出执行结果。然后输入程序，调试程序，比较结果的正确性。
```cpp
#include <iostream>					// 预处理命令
using namespace std;					// 使用标准命名空间std

// 数组类
class Array
{
 private:
   int* elem;						// 数组元素存储空间
   int size;							// 数组元素个数

 public:
   Array(int a[], int sz): elem(a), size(sz){ }			// 构造函数
   int GetSize(){ return size; }						// 返回数组元素个数
   int &operator[](int pos){ return elem[pos - 1]; }		// 重载下标运算符[]
};

int main()							
{
  int a[] = {1, 2, 3, 4, 5};			// 定义数组a
  Array obj(a, 5);						// 定义数组对象

  obj[1] = 8;								// 为数组元素赋值
  for (int i = 1; i <= obj.GetSize(); i++)	// 依次输出数组各元素之值
    cout << obj[i] << "  ";				// 输出第i个元素
  cout << endl;							// 换行

   return 0;                    		// 返回值0, 返回操作系统
}
```

输出
```plaintext
8 2 3 4 5
```

## 4.2.面程序主要实现描述复数的类Complex的加法运算符+重载，试完成程序

```cpp
#include <iostream>							// 预处理命令
using namespace std;							// 使用标准命名空间std

// 复数类
class Complex
{
 private:
  double realPart;							// 实部
  double imagePart;							// 虚部

 public:
  Complex(double real = 0, double image = 0): realPart(real), imagePart(image){ }	   double GetRealPart() const{ return realPart; }
  double GetImagePart() const{ return imagePart; }

  // 重载加法运算符+
  [1]   operator+(const Complex &a) const{
    Complex b;									// 定义复数对象
    b.realPart = this->realPart + a.realPart;		// 和的实部
    b.imagePart = this->imagePart + a.imagePart;	// 和的虚部
    return   [2]  ;								// 返回和
  }
};

int main()						
{
  Complex a(1, 2), b(2, 6), c;		// 定义复数对象

  c = a + b;							// 复数加法运算
  cout << "a=" << a.GetRealPart() << "+" << a.GetImagePart() << "i" << endl;
  cout << "b=" << b.GetRealPart() << "+" << b.GetImagePart() << "i" << endl;
  cout << "c=" << c.GetRealPart() << "+" << c.GetImagePart() << "i" << endl;

  return 0;                    	// 返回值0, 返回操作系统
}
```
`[1]`  Complex
`[2]` b

-   [code](https://github.com/chenboshuo/cpp_learning/commit/61e5e99b4eb7e955e81547afe46bcf66f1a7e46b)

## 4.3 下面程序实现了复数类Complex的常用运算符重载，试理解程序。
```cpp
#include <iostream>
class Complex{
	friend Complex operator+( double d, const Complex &c );
	friend Complex operator-( double d, const Complex &c );
	double m_fReal, m_fImag;
 public:
	Complex( const double &r = 0, const double &i = 0)
  : m_fReal( r ), m_fImag( i ){}
	Complex( const Complex &c ): m_fReal( c.m_fReal ), m_fImag( c.m_fImag )	{}

	double GetReal() const{
		return m_fReal;
	}
	double GetImag() const{
		return m_fImag;
	}
  //赋值
	Complex& operator=( const Complex &c ){
		if( this == &c )
		{
			return * this;
		}
		m_fReal = c.m_fReal;
		m_fImag = c.m_fImag;
		return * this;
	}
	Complex operator+( const Complex &c ) const //Complex + Complex
	{	return Complex( m_fReal+c.m_fReal, m_fImag+c.m_fImag );	}
	Complex operator-( const Complex &c ) const //Complex - Complex
	{	return Complex( m_fReal-c.m_fReal, m_fImag-c.m_fImag );	}
	Complex operator+( double d ) const //Complex - double
	{	return Complex( m_fReal+d, m_fImag );	}
	Complex operator-( double d ) const //Complex - double
	{	return Complex( m_fReal-d, m_fImag );	}
	Complex operator-() const //-Complex
	{	return Complex( -m_fReal, -m_fImag );	}
	Complex& operator++() //++Complex
	{		++m_fReal;		++m_fImag;	return * this; 	}
	const Complex operator++(int) //Complex++
	{
		Complex oldValue = * this;
		++( * this);
		return oldValue;
	}
	Complex& operator--() //--Complex
	{	--m_fReal;   		--m_fImag;   		return * this;   	}
	const Complex operator--(int) //Complex++
	{
		Complex oldValue = * this;
		--( * this);
		return oldValue;
	}
};
//为了实现交换律，将复数与整数和加减放到类定义外
Complex operator+( double d, const Complex &c )
{   return Complex( d + c.m_fReal, c.m_fImag );  }

Complex operator-( double d, const Complex &c )
{   return Complex( d - c.m_fReal, -c.m_fImag ); }

using namespace std;

int main()
{
	Complex c1( 3.3, 4.4 );
	Complex c2( 5.5, 2.2 );
	Complex c3;
	c3 = c1 + c2;
	cout << "C3 = " << c3.GetReal() << "+i" << c3.GetImag() << endl;
	c3 = c1 - c2;
	cout << "C3 = " << c3.GetReal() << "+i" << c3.GetImag() << endl;
	c3 = c1 + c2;
	cout << "C3 = " << c3.GetReal() << "+i" << c3.GetImag() << endl;
	c3 = c1 + 1.1;
	cout << "C3 = " << c3.GetReal() << "+i" << c3.GetImag() << endl;
	c3 = c1 - 1.1;
	cout << "C3 = " << c3.GetReal() << "+i" << c3.GetImag() << endl;
	c3 = 9.9 + c1;
	cout << "C3 = " << c3.GetReal() << "+i" << c3.GetImag() << endl;
	c3 = 9.9 - c1;
	cout << "C3 = " << c3.GetReal() << "+i" << c3.GetImag() << endl;
	 ( c3 = c1 ) = c2;
	cout << "C3 = " << c3.GetReal() << "+i" << c3.GetImag() << endl;
	++c1;
	cout << "C1 = " << c1.GetReal() << "+i" << c1.GetImag() << endl;
	--c1;
	cout << "C1 = " << c1.GetReal() << "+i" << c1.GetImag() << endl;
	c1++;
	cout << "C1 = " << c1.GetReal() << "+i" << c1.GetImag() << endl;
	c1--;
	cout << "C1 = " << c1.GetReal() << "+i" << c1.GetImag() << endl;
	++c1 = c2;
	cout << "C1 = " << c1.GetReal() << "+i" << c1.GetImag() << endl;
	c2 = -c2;
	cout << "C2 = " << c2.GetReal() << "+i" << c2.GetImag() << endl;
	return 0;
}

```

运行结果
```plaintext
C3 = 8.8+i6.6
C3 = -2.2+i2.2
C3 = 8.8+i6.6
C3 = 4.4+i4.4
C3 = 2.2+i4.4
C3 = 13.2+i4.4
C3 = 6.6+i-4.4
C3 = 5.5+i2.2
C1 = 4.3+i5.4
C1 = 3.3+i4.4
C1 = 4.3+i5.4
C1 = 3.3+i4.4
C1 = 5.5+i2.2
C2 = -5.5+i-2.2
```

## 4.4 分析下面程序，掌握重载运算符（）的方法及作用。

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Great_A_Less_B  //函数对象，在STL中使用非常广泛
{
	int m_nA;
	int m_nB;
public:
	Great_A_Less_B( int x, int y ) : m_nA( x ), m_nB( y ){}
	bool operator()( int c ) const //重载操作符()，判断c是否大于m_nA且小于m_nB
	{   return ( (c>m_nA) && (c<m_nB) );  }
};

class DivByA  //函数对象，在STL中使用非常广泛
{
	int m_nA;
public:
	DivByA( int x ) : m_nA( x ){}
	bool operator()( int c ) const //重载操作符()，判断c是否可以被m_nA整除
	{
		return ( c%m_nA == 0 );
	}
};
int main()
{
	Great_A_Less_B obj1(4,9);
	DivByA obj2(2);
	int a[] = {1,3,6,4,7,8,9,10,23,5};
	//打印a中大于4且小于9的数
	for( int i = 0; i < sizeof(a)/sizeof(int); ++i )
//sizeof(a)/sizeof(int)为数组a中的元素个数
	{
		if( obj1( a[i] ) == true ) //判断a[i]是否大于4且小于9
		{  cout << a[i] << '\t'; }
	}
	cout << endl;

//打印a中被2整除的数
	for(int i = 0; i < sizeof(a)/sizeof(int); ++i )
//sizeof(a)/sizeof(int)为数组a中的元素个数
	{
		if( obj2( a[i] ) == true ) //判断a[i]被2整除
		{
			cout << a[i] << '\t';
		}
	}
	cout << endl;
	//下面代码可以不看
	cout << "//--------------------------------------------" << endl;
	vector<int> s; //STL中的vector容器，线形表，自动增长
	vector<int>::iterator it; //迭代器
	for(int i = 0; i < 10; ++i )
	{  		s.push_back( rand()%10 );   	}
	for( it = s.begin(); it != s.end(); ++it )  //打印s中的内容
	{     cout << * it << '\t';  	}
	cout << endl;
	int c1 = count_if( s.begin(), s.end(), obj1 ); //统计s中大于4且小于9的数个数
	cout << c1 << endl;
	int c2 = count_if( s.begin(), s.end(), obj2 ); //统计s中被2整除的数个数
	cout << c2 << endl;
	return 0;
}
```

运行结果
```plaintext
6       7       8       5
6       4       8       10
//--------------------------------------------
1       7       4       0       9       4       8       8       2       4
3
7
```

## 4.5 改正下面程序中的错误，使其能正常运行。

-   [原题](https://github.com/chenboshuo/cpp_learning/blob/5add3a21dbf7f5f55dfae1ed918f0507f2ced929/homework/debug_integer.cpp)
-   [修改](https://github.com/chenboshuo/cpp_learning/commit/6905a907f5411171f6163d891b615e8cebc647e9)

## 4.6 6.定义一个有理数类，重载比较运算符<、<=、==、!=，试完成该程序。
-   [题目](https://github.com/chenboshuo/cpp_learning/blob/db6b2bcf5f9be1b00c65b7e014ed68d5bf44f6a0/homework/rational.cpp)
-   [代码](https://github.com/chenboshuo/cpp_learning/commit/d4a880ffe072d73aa4d4822e7bdb3f5c6765991e)

## 4.7设计一个日期类Date,，要求：
-   [x] 包含年(year)、月(month)和日(day)私有数据成员。
-   [x] 包含构造函数，重载关于一日期加上天数的加法运算符+、重载关于一日期减去天数的减加运算符-、重载输出运算符<<与输入运算符>>等。

代码基于[10.8 重载Date的运算符](https://github.com/chenboshuo/cpp_learning/commit/f2607785ca633323cfb7e85460eb126bb8d41be8)

[结果](https://github.com/chenboshuo/cpp_learning/commit/cb79467141189eb189d2172c447d4d27c2384c12)

## 4.8 设计一个时间类Time，要求：
-   [] 包含时(hour)、分(minute)和秒(second)私有数据成员。
-   [] 包含构造函数，重载关于一时间加上另一时间的加法运算符+、重载关于一时间减去另一时间的减加运算符-、重载输出运算符<<与输入运算符>>等。
