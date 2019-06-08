#include <iostream>

int main() {
  char *p = "Hello World!";
  std::cout << p << '\n';  // 字符串的指针cout自动打印对应值
  std::cout << (void *)p << '\n';  // 转换类型之后可以打印地址
}
/*
Finished in 4 ms
Hello World!
0x471040
*/
