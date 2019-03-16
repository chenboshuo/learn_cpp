/**
 * A popular problem puzzle of the late nineteenth centery invented by
 * French mathemician Edouard Lucas, called the Tower of Hanoi,
 * consists of three pegs mounted on a board together
 * with the disks of different sizes. Initially these disks
 * are placed on the first in order of size, with the largest on the bottom.
 * The rules of puzzle allow disks to be moved one at a time from one peg to
 * another as long as a disk is never placed on the top of size,
 * with the largest on the bottom.
 *
 * 假设僧侣们把盘子从木桩1移动到木桩3,
 * 我们希望开发一个算法,显示僧侣从木桩到木桩的移动过程.
 * 用递归处理,结果很简单.解决思路就是将移动n个盘子看成移动n-1个盘子的问题:
 *
 * 1. 把n-1个盘子从木桩1移动到木桩2,把木桩3作为临时存放点.
 * 2. 把最后一个盘子(最大的)从木桩1移动到木桩3.
 * 3. 把n-1个木桩2移到木桩3,把木桩1作为临时存放点.
 * 当最后一次任务只有n=1个盘子移动时(基本情况),整个过程就结束了.
 * 这是只需要把盘子移过去就好了,
 * 请编写一个程序解决汉诺塔问题,利用一个具有四个参数的递归函数,四个参数如下:
 * 1. 准备移动的盘子数
 * 2. 最初放置这些盘子的木桩
 * 3. 最后放置这些盘子的木桩
 * 4. 作为临时存放点的木桩
 *
 * 程序应该打印这些盘子移动到目的目标的准确步骤.例如,把三个盘子从1移到3,应打印
 * ```
 * 1 -> 3
 * 1 -> 2
 * 3 -> 2
 * 1 -> 3
 * 2 -> 1
 * 2 -> 3
 * 1 -> 3
 */

 #include <iostream>
 using namespace std;

/**
 * 移动一次盘子
 * @param disks 准备移动的盘子数
 * @param peg1  最初放置这些盘子的木桩
 * @param peg2  最后放置这些盘子的木桩
 * @param peg_  作为临时存放点的木桩
 */
void move(int disks, int peg1, int peg2, int peg_) {
  if (disks == 1) {// 当盘子只剩一个时,直接移动到目标
    std::cout << peg1 << "->" << peg2 << '\n';
    return;
  }
  move(disks-1, peg1, peg_, peg2);// 先把disks-1移动到缓冲区
  std::cout << peg1 << "->" << peg2 << '\n';// 把最大的盘子移动到目标
  move(disks-1, peg_, peg2, peg1);// 把disks-1也移动到目标
}
int main(int argc, char const *argv[]) {
  move(3,1,3,2);
  return 0;
}
