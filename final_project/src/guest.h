// filename : guest.h
#include <iostream>
#include <algorithm>
#include "date.h"

using namespace std;
#ifndef GUEST_H
#define GUEST_H

class Guest {
 public:
  /**
   * 构造函数
   * @param id_card       身份证
   * @param chick_in_date 入住时间
   * @param name          名称
   * @param gender        性别(男性为0, 女性为1)
   */
  Guest (string id_card,
         Date &chick_in_date,
         string name,
         string gender = "man")
   : id_card(id_card),
   name(name){
    this->chick_in_date = chick_in_date;
    if(gender == "female" || "woman" || "girl"){
      this->gender = 1;
    }
  };

  /**
   * 显示成员信息
   */
  void show() {
    cout << (gender ? "Her" : "His") << " name is: "
         << name << "\nID_card: " << id_card
         << "\ncheck in date: " << chick_in_date << endl;
  }

  void check_in() {
    cout << "Guset room check in" << endl;
  }

  void check_out() {
    cout << "Guest room check out" << endl;
  }

  friend ofstream &operator<<(ofstream & out, Guest &a) {
    out << a.id_card << "," << a.chick_in_date << ","
      << a.name << "," << (a.gender ? "woman": "man") << endl;
    return out;
  }

  string get_id_card(){
    return id_card;
  }
  string get_check_in_date(){
    return chick_in_date.get_date();
  }
  string get_name(){
    return name;
  }
  string get_gender(){
    return (gender ? "female" : "male");
  }
 private:
  string id_card;
  Date chick_in_date;
  string name;
  bool gender = 0;  // 默认为男性
};

#endif
