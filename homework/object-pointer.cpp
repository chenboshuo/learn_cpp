/**
 * 问题 C: 对象指针
时间限制: 1 Sec  内存限制: 128 MB
提交: 15  解决: 13
[提交] [状态] [讨论版] [命题人:admin]
题目描述
建立对象数组，内放5个学生数据（学号是字符串类型、成绩是整型），设立max函数，用指向对象的指针作函数参数，在max函数中找出5个学生中成绩最高者，并输出其学号和成绩。

输入
输入5个学生数据。

输出
输出5个学生中成绩最高者的学号和成绩。

样例输入
01 89
02 78
03 56
04 92
05 76

样例输出
04 92
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
