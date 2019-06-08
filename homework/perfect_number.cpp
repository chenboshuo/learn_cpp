/**
 * 6.28 完数
 * 如果一个整数的所有因子(包括一,但不包括他自己)之和等于自身,
 * 那么这个数就是一个完数. 例如6是完数,`6=1 + 2 + 3`.
 * 编写一个程序isperfect,用于确定参数`number`是否是一个完数.
 * 在程序中使用这个函数, 该程序确定1-1000 之间所有完数.
 * 打印每个完数因子确定该数是完数
 * 测试大于1000的数,向计算机能力挑战
 */
#include <iostream>

/**
 * 确定这个数是不是完数
 * @param  a        数
 * @param  divisors 存储因子的数组
 * @return          1代表是完数
 */
int isperfect(int a, int *divisors) {
  int sum = 0;
  int j = 0;
  for (int i = 1; i < a; i++) {
    if (a % i == 0) {
      sum += i;
      divisors[j++] = i;
    }
  }
  if (a == sum) {
    return 1;
  } else {
    return 0;
  }
}
int main(int argc, char const *argv[]) {
  // 在程序中使用这个函数, 该程序确定1-1000 之间所有完数.
  for (int i = 1; i < 1001; i++) {
    int divisors[i] = { 0 };
    if (isperfect(i, divisors)) {
      std::cout << i << " is perfect number. and its divisors is: "
                << "\n\n";
      for (int j = 0; divisors[j]; j++) { std::cout << divisors[j] << ' '; }
      std::cout << "\n--------------------------------------\n";
    }
  }
  return 0;
}
