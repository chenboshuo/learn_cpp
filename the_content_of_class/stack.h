// filename: stack.h
#ifndef STACK_H
#define STACK_H
#include <deque>
/**
 * deque 对象是标准库stack的默认表示
 * vector 和 deque 都可以存储stack对象
 * vector 支持快速的在他后端进行插入和删除
 * deque 对象可以支持快速的在前端或后端进行插入和删除
 *
 */

template <typename T>
class Stack {
 public:
  // return the top element of the stack (返回栈顶的元素的引用)
  T& top(){
    return stack.front();
  }

  // push an element onto the Stack (在栈顶放置一个新元素)
  void push(const T &push_value) {
    stack.push_front(push_value);
  }

  // pop an element from the stack (删除栈顶元素)
  void pop() {
    stack.pop_front();
  }

  // determine whether stack is empty
  bool is_empty() const{
    return stack.empty();
  }

  // return size of stack
  size_t size() const{
    return stack.size();
  }

 private:
  std::deque<T>stack;  // internal representation of the Stack
};



#endif
