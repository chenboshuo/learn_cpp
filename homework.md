# 所有作业, 实验, 练习题
## 3.9 不用using命令使用`string`

```
std::string
```
## 3.10 说明为什么类可以为成员提供`set`, `get`函数

可以通过这类函数修改类的属性

## 3.11 修改Gradebook类
-   [x] 包括第二个string数据成员,他表示授课教师的名字
-   [x] 提供一个可以改变教师姓名的函数,以及可以得到名字的get
-   [x] 修改构造函数,指定两个形参:一个针对课程名称, 另一个针对教师姓名.
-   [x] 修改成员函数displaymessage,使它首先输出欢迎信息和课程名称,然后输出"This course is presented by:" 跟老师姓名

[代码](https://github.com/chenboshuo/cpp_learning/commit/d6529d2ec3309333f44d6a4cf4e07111be7f8252#diff-52ec402c28719f938d3857a0a7f54c17)

## 3.12 Account 类
创建一个名为Account的类银行可使用它表示银行的账户.
-   [x] 这个类应该包含一个数据成员表示账户余额.
-   [x] 函数:接受余额并初始化数据成员(保证余额大于0,否则返回错误信息)
-   [x]  credit:将一笔金额添加到余额中
-   [x] debit:从这个类中取钱,并保证不能超出余额,若超出余额,指出"Debit amount exceed account balance"
-   [x] getBalance返回余额
-   [x] 测试程序,创建两个对象并测试函数

[代码](https://github.com/chenboshuo/cpp_learning/commit/076118b5f251ab11c5e8f2e66abd9ab23d5b18a7#diff-c09b9f03cfaf038e63d8cc54f37e4f23)

## 6.12 停车费问题
-   [x] 停车场3小时收费2美元，超过3小时，每增加一小时或不到一小时收取0.5$的附加费用。
-   [x] 24小时内最多收10$，假设没有车子一次停车超出24小时。
-   [x] 编写一个程序，计算显示三个客户各自停车费用
-   [x] 要求输入每个客户的停车时间。
-   [x] 程序应以整齐的表格形式打印结果，并计算昨天收费的总和。
-   [x] 使用calculateCharge来确定每个客户的停车费用。

-   [代码](https://github.com/chenboshuo/cpp_learning/blob/91108188ca8884dc0941007bbbb6c32719d7a7c3/homework/parking.cpp)

## 6.19 三角形斜边计算
-   [x] 定义一个函数hypotenuse，用于计算已知直角三角形的两条直角边长时计算斜边的长。
      该函数有两个double型参数，并返回double类型边长
-   [x] 计算

| 三角形 | 边1 | 边2  |
|:------ |:--- | ---- |
| 1      | 3.0 | 4.0  |
| 2      | 5.0 | 12.0 |
| 3      | 8.0 | 15.0 |

-   [代码](https://github.com/chenboshuo/cpp_learning/blob/1fb0283d762d8e8f44ff69dabfcd9fa69723d75c/homework/triangle.cpp)

## 6.27 找最小数
编写一个程序, 输入三个双精度浮点数,并且把他们传递给返回最小值的函数

-   [代码](https://github.com/chenboshuo/cpp_learning/blob/fbae9b7a86e47b6517bb1c935216f04598ae0ac9/homework/find_the_minium.cpp)
## 6.28 完数

如果一个整数的所有因子(包括一,但不包括他自己)之和等于自身,那么这个数就是一个完数. 例如6是完数,`6=1 + 2 + 3`.

-   [x] 编写一个程序isperfect,用于确定参数`number`是否是一个完数.
-   [x] 在程序中使用这个函数, 该程序确定1-1000 之间所有完数.
-   [x] 打印每个完数因子确定该数是完数
-   [ ] 测试大于1000的数,向计算机能力挑战

-   [代码](https://github.com/chenboshuo/cpp_learning/blob/0db0b1f9fb870f2f2893465ab920bc4d5b205089/homework/perfect_number.cpp)

## 6.34 猜数游戏
编写一个程序,可以玩猜数字游戏.程序在1-1000 之间的数随机选择被猜的数,然后显示
```
I can have a number between 1 and 1000.
Can you guess my number?
Plase type your first guess
```
玩家于是输入猜想的一个数,程序会做出如下响应
```
Excellent! You guessed the number!
Would you like to try again?  (y or n)
Too high. try again.
Too low. try again.
```
如果玩家猜测是不正确的, 程序应继续循环,直到玩家猜对为止.此过程需要一直提醒玩家是猜大了还是猜小了,从而让玩家尽快获得答案

-   [代码](https://github.com/chenboshuo/cpp_learning/blob/e8884c43e65c374408f2bcaefa02fd82a199e105/homework/guess_number.cpp)

## 6.35 猜数字游戏的修改
修改6.34 的程序
-   [x] 统计玩家猜数次数,如果次数没有超过10次,打印"Either you know the secret or you got lucky" 如果玩家10次猜中,打印"Ahah! You know the secret". 如果超过10次猜中,打印"you should be able to do better!"

-   [代码对比](https://github.com/chenboshuo/cpp_learning/commit/1935db553e4c58b8fa23681889923786e14c91fd)
-   [全部代码](https://github.com/chenboshuo/cpp_learning/blob/1935db553e4c58b8fa23681889923786e14c91fd/homework/guess_number.cpp)

## 6.38 汉诺塔问题(The Tower of Hanoi)

> A popular problem puzzle of the late nineteenth century invented by French mathematician Edouard Lucas, called the Tower of Hanoi, consists of three pegs mounted on a board together with the disks of different sizes. Initially these disks are placed on the first in order of size, with the largest on the bottom.The rules of puzzle allow disks to be moved one at a time from one peg to another as long as a disk is never placed on the top of size, with the largest on the bottom.

假设僧侣们把盘子从木桩1移动到木桩3,我们希望开发一个算法,显示僧侣从木桩到木桩的移动过程.

用递归处理,结果很简单.解决思路就是将移动n个盘子看成移动n-1个盘子的问题:

1.  把n-1个盘子从木桩1移动到木桩2,把木桩3作为临时存放点.
2.  把最后一个盘子(最大的)从木桩1移动到木桩3.
3.  把n-1个木桩2移到木桩3,把木桩1作为临时存放点.

当最后一次任务只有n=1个盘子移动时(基本情况),整个过程就结束了.这是只需要把盘子移过去就好了,请编写一个程序解决汉诺塔问题,利用一个具有四个参数的递归函数,四个参数如下:

1.  准备移动的盘子数
2.  最初放置这些盘子的木桩
3.  最后放置这些盘子的木桩
4.  作为临时存放点的木桩

程序应该打印这些盘子移动到目的目标的准确步骤.例如,把三个盘子从1移到3,应打印
```
1 -> 3
1 -> 2
3 -> 2
1 -> 3
2 -> 1
2 -> 3
1 -> 3
```

-   [代码](https://github.com/chenboshuo/cpp_learning/blob/7f8fa9b7415258edc7e1a4b4ab50e05b58b159ea/homework/The-Tower-of-Hanoi.cpp)

## 6.39 汉诺塔问题的迭代版本

虽然有时候实现起来比较困难并且不够清晰,但是用递归可以解决的问题可以用迭代来实现.
请尝试用迭代的方法解决6.38

思路:

设初始柱子为x,最终为y,临时为t

disks = 1

| 操作   | 操作后的情况 | 变量化   |
|:------ |:------------ | -------- |
| 1 -> 2 | 0 1          | x1 -> y1 |

disks = 2

| 操作   | 操作后的情况 | 变量化   | 赋值             |
|:------ |:------------ | -------- | ---------------- |
| 1 -> 3 | 2 0 1        | x2 -> t2 | x2 = x1, t2 = y1 |
|        |              |          |                  |
| 1 -> 2 | 0 2 1        | x2 -> y2 | y2 = y1          |
|        |              |          |                  |
| 3 -> 2 | 0 1/2 0      | t2 -> y2 |                  |

disks  = 3

| 操作   | 操作后的情况    | 变量化   | 赋值           |
|:------ |:--------------- | -------- | -------------- |
| 1 -> 2 | 2/3--1------0   | x3 -> y3 | x2 = 1, y2 = 3 |
| 1 -> 3 | 3----1------2   | x3 -> t3 |                |
| 2 -> 3 | 3----0------1/2 | y3 -> t3 |                |
|        |                 |          |                |
| 1 -> 2 | 0----3------1/2 | x3 -> y3 |                |
|        |                 |          |                |
| 3 -> 1 | 1----3------2   | t3 -> x3 | x2 = 3, y2 = 2 |
| 3 -> 2 | 1----2/3----0   | t3 -> y3 | \               |
| 1 -> 2 | 0----1/2/3--0   | x3 -> y3 |                |


## 9.7 增强的Time类
-   [x] 修改Time函数，使他包含一个tick成员函数。该函数存放在Time对象中的时间增加1秒。Time对象应该始终保持可靠状态。
-   [x] 编写一个程序，在循环中测试tick函数，每次循环过程中以标准格式打印时间，以显示tick是否正常

程序应该保证以下情况：
1. 递增到下一分钟
2. 递增到下一小时
3. 递增到下一小时（11:59:59 PM 到 12:00:00 AM)

-   [代码对比](https://github.com/chenboshuo/cpp_learning/commit/0dfdbce07017abafac564199c5b9710a789dd576)
-   [头文件完整代码](https://github.com/chenboshuo/cpp_learning/blob/0dfdbce07017abafac564199c5b9710a789dd576/the_content_of_class/Time.h) [主函数完整代码](https://github.com/chenboshuo/cpp_learning/blob/0dfdbce07017abafac564199c5b9710a789dd576/the_content_of_class/time.cpp)

## 实验四 函数重载与运算符重载
-   [跳转](./homework/test_4.md)
## 实验五 继承与派生继承与派生
-   [跳转](./homework/test_5.md)
