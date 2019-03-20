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
  Student (string n="", int s=-1){
    number = n;
    score = s;
  };

  void showScore() {
    std::cout << number << " " << score << '\n';
  }

  int getScore(){
    return score;
  }
  // virtual ~Student ();
};

// int max(Student* a, int len){
//   int _ = a->getScore();
//   for (int i = 1; i < len; i++) {
//     _ = (_ > (a+i)->getScore())  ? _ : (a+i)->getScore();
//   }
//   return _;
// }
// 这个函数仅用于找出最大数,无法返回学号

Student find_max(Student* a, int len){
  Student _ = *a;
  for (int i = 1; i < len; i++) {
    if (a[i].getScore() > _.getScore()) {
      _ = a[i];
    }
  }
  return _;
}

int main(int argc, char const *argv[]) {
  int count = 5;
  // std::cin >> count;
  Student a_test[5];

  for (int i = 0; i < count; i++) {
    string number;
    int score;
    std::cin >> number >> score;
    a_test[i] = Student(number, score);
  }
  find_max(a_test, count).showScore();
  return 0;
}
