// filename: student.cpp
#include <iostream>
#include <string>

using namespace std;

class Student {
  static int math_total_score, english_total_score;  // 数学总成绩, 英语总成绩
  static int count; // 人数
 public:
  Student (string nm, int nu, int math, int english)
    :name(nm), num(nu),math_score(math), english_score(english){
      ++count;
      math_total_score += math;
      english_total_score += english;
    };

  void show_base() {
    cout << "name: " << name
      << "\nnumber: "<< num << "\nreport:\n"
      << "\nmath: " << math_score << "\nEnglish: " << english_score << endl;
  }
  void show_static() {
    cout << "\n\nTotal students is: " << count
      << "\nmath total score: " << math_total_score
      << "\nEnglish total score: " << english_total_score<< endl;
  }
 private:
  string name;
  int num; // 学号
  int math_score, english_score; // 数学, 英语成绩
};

int Student::count = 0;
int Student::math_total_score = 0;
int Student::english_total_score = 0;

int main(int argc, char const *argv[]) {
  Student a("a", 1, 99, 98), b("b", 2, 59, 61);
  a.show_base();
  b.show_base();
  a.show_static();
  b.show_static();
  return 0;
}
/*
  name: a
  number: 1
  report:

  math: 99
  English: 98
  name: b
  number: 2
  report:

  math: 59
  English: 61


  Total students is: 2
  math total score: 158
  English total score: 159


  Total students is: 2
  math total score: 158
  English total score: 159
 */
