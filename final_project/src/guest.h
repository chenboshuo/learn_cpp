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
         Date chick_in_date,
         string name,
         string gender = "man")
   : id_card(id_card),
   name(name){
    chick_in_date = chick_in_date ;
    if(gender == "famale" || "woman" || "girl"){
      gender = 1;
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

  void record() {
    cout << id_card << "," << chick_in_date << ","
      << name << "," << (gender ? "woman": "man") << endl;
  }

 private:
  string id_card;
  Date chick_in_date;
  string name;
  bool gender = 0;  // 默认为男性
};

#endif
