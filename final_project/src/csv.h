// filename: csv.h 与csv有关的函数库
#ifndef CSV_H
#define CSV_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

#include "room.h"
#include "guest.h"
#include "date.h"

using namespace std;

class Csv {
 public:
  Csv (string name):name(name){
  }

  /**
   * 读取并储存CSV
   */
  void read_csv() {
    ifstream csv_file(name, ios::in);
    while(getline(csv_file, line_str)){
      stringstream ss(line_str);
      string str;
      vector<string> line_array;
      while (getline(ss, str, ',')) {
        line_array.push_back(str);
      }
      information.push_back(line_array);
    }
    csv_file.close();
  }

  /**
   * 绘制CSV表
   */
  void show(){
    // 绘制表格(第一行框架)
    cout << "\t+";
    for(size_t h = 0; h < information[0].size(); ++h){
      for(size_t k = 0; k < 19; ++k){
        cout << "-";
      }
      cout << "+";
    }
    cout << "\n";
    // 表格主主体数据
    for(size_t i = 0; i < information.size(); ++i){
      cout << "\t|";
      for(size_t j = 0; j < information[i].size(); ++j){
        cout << setw(19) << information [i][j] << "|";
      }
      cout << "\n\t+" ;
      for(size_t h = 0; h < information[i].size(); ++h){
        for(size_t k = 0; k < 19; ++k){
          cout << "-";
        }
        cout << "+";
      }
      cout << "\n";
    }
    cout << "\n";
  }

  /**
   * 在后面写入新的房间
   * @param a 房间的属性
   */
  void to_csv(Room a) {
    ofstream outfile(name, ios::app);
    vector<string> line_array = {a.get_room_number(), a.get_room_type(),
                                 a.get_status()};
    outfile << a.get_room_number() << "," << a.get_room_type() << ","
      << a.get_status() << endl;
    outfile.close();
    information.push_back(line_array);
  }

  void to_csv(Guest a) {
    ofstream outfile(name, ios::app);
    vector<string> line_array = {a.get_id_card(), a.get_check_in_date(),
                                 a.get_name(), a.get_gender()};
    outfile << a.get_id_card() << "," << a.get_check_in_date() << ","
      << a.get_name() << "," << a.get_gender() << endl;
    outfile.close();
    information.push_back(line_array);
  }

  /**
   * 重写csv文件
   */
  void to_csv(void) {
    ofstream outfile(name, ios::out);
    for(size_t i = 0; i < information.size(); ++i){
      size_t j;
      for(j = 0; j < information[i].size()-1; ++j){
        outfile << information[i][j] << ",";
      }
      outfile << information[i][j] << endl;
    }
    outfile.close();
  }
  /**
   * 寻找空房间(不太简洁的暴力)
   */
  void find_empty_room() {
    // 绘制表格(第一行框架)
    cout << "\t+";
    for(size_t h = 0; h < information[0].size(); ++h){
      for(size_t k = 0; k < 19; ++k){
        cout << "-";
      }
      cout << "+";
    }
    cout << "\n";
    // 表格主主体数据
    for(size_t i = 0; i < information.size(); ++i){
      if(information [i][2] == "empty"){
        cout << "\t|";
        for(size_t j = 0; j < information[i].size(); ++j){
          cout << setw(19) << information [i][j] << "|";
        }
        cout << "\n\t+" ;
        for(size_t h = 0; h < information[i].size(); ++h){
          for(size_t k = 0; k < 19; ++k){
            cout << "-";
          }
          cout << "+";
        }
        cout << "\n";
      }
    }
    cout << "\n";
  }

  /**
   * 根据房间号寻找代码
   * @param number_str 房间号
   * @return 成功为索引值, 不成功为-1
   */
  int find_room(string number_str){
    // 绘制表格(第一行框架)
    cout << "\t+";
    for(size_t h = 0; h < information[0].size(); ++h){
      for(size_t k = 0; k < 19; ++k){
        cout << "-";
      }
      cout << "+";
    }
    cout << "\n";
    // 表格主主体数据
    for(size_t i = 0; i < information.size(); ++i){
      if(information [i][0] == number_str){
        cout << "\t|";
        for(size_t j = 0; j < information[i].size(); ++j){
          cout << setw(19) << information [i][j] << "|";
        }
        cout << "\n\t+" ;
        for(size_t h = 0; h < information[i].size(); ++h){
          for(size_t k = 0; k < 19; ++k){
            cout << "-";
          }
          cout << "+";
        }
        cout << "\n";
        return i;
      }
    }

    cout << "\t|                the room number not found                  |"
      << endl;
      // 绘制表格(第一行框架)
    cout << "\t+";
    for(size_t h = 0; h < information[0].size(); ++h){
      for(size_t k = 0; k < 19; ++k){
        cout << "-";
      }
      cout << "+";
    }
    cout << "\n";
    return -1;
  }

  /**
   * 模拟退房
   * 将字符串full 改为 empty
   * @param number_str 房间号
   * @return 成功为1, 不成功为0
   */
  int check_out(string number_str) {
    cout << "\tThis is the information of "<< number_str << endl;
    int index = find_room(number_str);
    if (index < 0 || information[index][2] == "empty") {
      string n;
      cout << "\tplease confirm room number\n\t and enter the correct room number:"
      << "(or you can enter \"q\" to quit)" << endl;
      std::cin >> n;
      if (n == "q") {
        return 0;
      }
      check_out(n);
      return 0;
    }
    cout << "\tcheck in succssful" << endl;
    information[index][2] = "empty";
    to_csv();
    return 1;
  }

  /**
   * 模拟入住
   * 将字符串 empty 改为 full
   * @param number_str 房间号
   * @return 成功为1, 不成功为0
   */
  int check_in(string number_str) {
    cout << "\tThis is the information of "<< number_str << endl;
    int index = find_room(number_str);
    if (index < 0 || information[index][2] == "full") {
      string n;
      cout << "\tplease confirm room number\n\t and enter the correct room number:"
      << "(or you can enter \"q\" to quit)" << endl;
      std::cin >> n;
      if (n == "q") {
        return 0;
      }
      check_out(n);
      return 0;
    }
    cout << "\tcheck out succssful" << endl;
    information[index][2] = "full";
    to_csv();
    return 1;
  }
 private:
  string name;
  string line_str;
  vector<vector<string>> information;
};
#endif
