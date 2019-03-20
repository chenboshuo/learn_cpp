/**
 * 问题 B: 对象数组
时间限制: 1 Sec  内存限制: 128 MB
提交: 19  解决: 15
[提交] [状态] [讨论版] [命题人:admin]
题目描述
利用类对象数组完成N个学生数据（学号是字符串类型、成绩是整型）的输入、输出。

输入
输入有N+1行：
第一行的整数N表示学生数目；
以下N行是N个学生的数据，每行中第一个是表示学号的字符串，第二个是表示学生成绩的整数。

输出
输出N个学生数据。每个学生的数据占一行。

样例输入
5
01 89
02 78
03 56
04 92
05 76

样例输出
01 89
02 78
03 56
04 92
05 76
 */
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
  string number;
  int score;

public:
  Student (string n, int s){
    number = n;
    score = s;
  };

  void showScore() {
    std::cout << number << " " << score << '\n';
  }
  // virtual ~Student ();
};

int main(int argc, char const *argv[]) {
  int count;
  std::cin >> count;
  while (count--) {
    string number;
    int score;
    std::cin >> number >> score;
    Student a_student(number,score);
    a_student.showScore();
  }
  return 0;
}
