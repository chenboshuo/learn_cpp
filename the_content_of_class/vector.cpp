// filename: vetcor.cpp
// reference:http://www.cplusplus.com/reference/vector/vector/?kw=vector
// Standard Library vector class template
#include <iostream>
#include <vector>
using namespace std;

// prototype for function template print_vector
template<typename T> void print_vector(const std::vector<T> &integers2);

int main(int argc, char const *argv[]) {
  const size_t SIZE = 6;
  int values[SIZE] = { 1, 2, 3, 4, 5, 6 };  // initialize values
  std::vector<int> integers;                // create vector of ints

  cout << "The initial size of integers is: " << integers.size()
       << "\nThe initial capacity of integers is: " << integers.capacity()
       << endl;
  /** 成员函数size, capacity
   * size(除了forward_list 的其他容器都可用),返回了当前容器所存储的元素数\
   *
   * capacity(在 vector 和 deque 中可用)返回了 vector 在为容纳更多元素调整空间前
   * 可以存储的元素数
   * 参考: http://www.cplusplus.com/reference/vector/vector/capacity/
   */
  // The initial size of integers is: 0
  // The initial capacity of integers is: 0

  // function push_back is in vector, deque and list
  integers.push_back(2);
  integers.push_back(3);
  integers.push_back(4);
  /** 成员函数 push_back
   * 在末端插入元素, 如果元素已满, 则会增加容量.某些实现会使容量加倍
   *
   */

  cout << "\nThe size of integers is: " << integers.size()
       << "\nThe capacity of integers is: " << integers.capacity() << endl;
  // The size of integers is: 3
  // The capacity of integers is: 4

  integers.push_back(5);
  integers.push_back(6);
  cout << "\nThe size of integers is: " << integers.size()
       << "\nThe capacity of integers is: " << integers.capacity() << endl;
  // The size of integers is: 5
  // The capacity of integers is: 8

  cout << "\nOutput vector using iterator notation" << endl;
  print_vector(integers);
  //   Output vector using iterator notation
  // 2 3 4

  cout << "\nReversed contents of vector integers" << endl;
  // display vector in reverse order using const_reverse_iterator
  for (auto reverse_iterator = integers.crbegin();
       reverse_iterator != integers.crend(); ++reverse_iterator) {
    cout << *reverse_iterator << " ";
  }
  cout << endl;
  /**
   * crbegin(),crend() 这两个函数返回 const_reverse_iterator,
   * 分别代表遍历容器开始和结束的地方.
   */
  //   Reversed contents of vector integers
  // 4 3 2
  return 0;
}

// function template for outputting vector elements
template<typename T> void print_vector(const vector<T> &integers2) {
  // display vector elements using const_iterator
  for (auto const_iterator = integers2.cbegin();
       const_iterator != integers2.cend(); ++const_iterator) {
    cout << *const_iterator << " ";
  }
  cout << endl;
}

// The initial size of integers is: 0
// The initial capacity of integers is: 0
//
// The size of integers is: 3
// The capacity of integers is: 4
//
// Output vector using iterator notation
// 2 3 4
//
// Reversed contents of vector integers
// 4 3 2
