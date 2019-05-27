#include <iostream>					// 预处理命令
using namespace std;					// 使用标准命名空间std

// 数组类模板
template <class ElemType>
class Array{
 private:
	ElemType *elem;					// 数组元素存储空间
	int size;							// 数组元素个数
 public:
	Array(int a[], int sz): elem(a), size(sz){ }
	ElemType Max();					// 返回数组元素的最大值
	ElemType Sum();					// 返回数组元素之和
	void Sort();						// 排序
	void Show();						// 显示数组所有元素
};

// 数组类模板的实现部分
template <class ElemType>
ElemType Array<ElemType>::Max(){		// 返回数组元素的最大值
	ElemType max = elem[0];			// 假设elem[0]最小
	for (int i = 1; i < size; i++){			// 依次比较求最新的最小值
		if (max < elem[i]) max = elem[i];
	}
	return max;						// 返回最大值
}

template <class ElemType>
ElemType Array<ElemType>::Sum()	{	// 返回数组元素之和
	ElemType sum = 0;				// 用sum累加求和
	for (int i = 0; i < size; i++){ sum += elem[i]; }			// 依次累加求和

	return sum;						// 返回最大值
}

template <class ElemType>
void Array<ElemType>::Sort(){			// 排序... 应该是个选择排序
	for (int i = 0; i < size - 1; i++){
		int k = i;						// 假设elem[i]最小
		for (int j = i + 1; j < size; j++) // 查找 elem[i],elem[i+1],...,elem[size-1] 中的最小值下标k
			if (elem[k] > elem[j]) k = j;
		if (k != i){
			// 交换elem[j]和elem[k]
			int tem;					// 临时变量
			tem = elem[i]; elem[i] = elem[k]; elem[k] = tem; 	// 循环赋值
		}
	}
}

template <class ElemType>
void Array<ElemType>::Show(){			// 显示数组所有元素
	for (int i = 0; i < size; i++)			// 依次显示各元素的值
	cout << elem[i] << "  ";
	cout << endl;						// 换行
}

int main()
{
	int a[] = {6, 2, 1, 4, 5, 3};			// 定义数组a
	Array<int> obj(a, 6);					// 定义数组对象

	cout << "The value of the array:";
	obj.Show();							// 显示各元素的值
	cout << "The max of array is: " << obj.Max() << endl;
	cout << "The sum of array is: " << obj.Sum() << endl;
	obj.Sort();							// 排序
	cout << "After sort the array is: ";
	obj.Show();							// 显示各元素的值
	return 0;                    		// 返回值0, 返回操作系统
}
