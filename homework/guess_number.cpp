/**
 * 6.34 猜数游戏
 * 编写一个程序,可以玩猜数字游戏.
 * 程序在1-1000 之间的数随机选择被猜的数,然后显示
 * I can have a number between 1 and 1000.
 * Can you guess my number?
 * Plase type your first guess
 * 玩家于是输入猜想的一个数,程序会做出如下响应
 * Excellent! You guessed the number!
 * Would you like to try again?  (y or n)
 * Too high. try again.
 * Too low. try again.
 * 如果玩家猜测是不正确的, 程序应继续循环,直到玩家猜对为止.
 * 此过程需要一直提醒玩家是猜大了还是猜小了,从而让玩家尽快获得答案
 *
 * 6.35 猜数字游戏的修改
 * 修改6.34 的程序
 * 统计玩家猜数次数,
 * 如果次数没有超过10次,打印"Either you know the secret or you got lucky"
 * 如果玩家10次猜中,打印"Ahah! You know the secret".
 * 如果超过10次猜中,打印"you should be able to do better!"
 */
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

/**
 * 生成1-x的随机数
 * @param  x 范围
 * @return   随机数
 */
inline int random(int x) {
  srand((unsigned)time(NULL));
  return rand() % x;
}

int main(int argc, char const *argv[]) {
  while (1) {
    int target = random(1000);
    int guess = 1001;  // 为了防止生成随机数直接与该变量相等
    int guess_times;   //存储猜的次数

    std::cout << "I can have a number between 1 and 1000.\n"
              << "Can you guess my number?\n"
              << "Plase type your first guess\n"
              << '\n';

    for (guess_times = 1; target != guess; guess_times++) {
      std::cin >> guess;
      if (guess > target) { std::cout << "\n\tToo high. try again" << '\n'; }
      if (guess < target) { std::cout << "\n\tToo low. try again" << '\n'; }
    }

    // 输出提示语,判断游戏等级
    std::cout << "Excellent! You guessed the number!\n" << '\n';
    if (guess_times < 10) {
      std::cout << "Either you know the secret or you got lucky" << '\n';
    } else if (guess_times == 10) {
      std::cout << "Ahah! You know the secret" << '\n';
    } else {
      std::cout << "you should be able to do better!" << '\n';
    }

    // 让玩家决定是否继续
    std::cout << "\nWould you like to try again?  (y or n) " << '\n';
    // 判断结束
    char sign = 0;
    std::cin >> sign;
    if (sign == 'n') { break; }
    std::cout << "\n----------------------------------------" << '\n';
  }
  return 0;
}

/**
 * outcome
 * I can have a number between 1 and 1000.
Can you guess my number?
Plase type your first guess

500

        Too high. try again
250

        Too high. try again
125

        Too low. try again
180

        Too low. try again
220

        Too low. try again
235

        Too low. try again
241

        Too high. try again
238
Excellent! You guessed the number!

Either you know the secret or you got lucky

Would you like to try again?  (y or n)
n
 */
