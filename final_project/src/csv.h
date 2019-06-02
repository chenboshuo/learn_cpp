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
      str_array.push_back(line_array);
    }
    csv_file.close();
  }

  /**
   * 绘制CSV表
   */
  void show(){
    // 绘制表格(第一行框架)
    cout << "\t+";
    for(size_t h = 0; h < str_array[0].size(); ++h){
      for(size_t k = 0; k < 19; ++k){
        cout << "-";
      }
      cout << "+";
    }
    cout << "\n";
    // 表格主主体数据
    for(size_t i = 0; i < str_array.size(); ++i){
      cout << "\t|";
      for(size_t j = 0; j < str_array[i].size(); ++j){
        cout << setw(19) << str_array [i][j] << "|";
      }
      cout << "\n\t+" ;
      for(size_t h = 0; h < str_array[i].size(); ++h){
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
   * 写入(针对room.csv)
   */
  void to_csv(Room a) {
    ofstream outfile(name, ios::app);
    vector<string> line_array = {a.get_room_number(), a.get_room_type(),
                                 a.get_status()};
    outfile << a.get_room_number() << "," << a.get_room_type() << ","
      << a.get_status() << endl;
    outfile.close();
    str_array.push_back(line_array);
  }

  void to_csv(Guest a) {
    ofstream outfile(name, ios::app);
    vector<string> line_array = {a.get_id_card(), a.get_check_in_date(),
                                 a.get_name(), a.get_gender()};
    outfile << a.get_id_card() << "," << a.get_check_in_date() << ","
      << a.get_name() << "," << a.get_gender() << endl;
    outfile.close();
    str_array.push_back(line_array);
  }

  /**
   * 寻找空房间(不太简洁的暴力)
   */
  void find_empty_room() {
    // 绘制表格(第一行框架)
    cout << "\t+";
    for(size_t h = 0; h < str_array[0].size(); ++h){
      for(size_t k = 0; k < 19; ++k){
        cout << "-";
      }
      cout << "+";
    }
    cout << "\n";
    // 表格主主体数据
    for(size_t i = 0; i < str_array.size(); ++i){
      if(str_array [i][2] == "empty"){
        cout << "\t|";
        for(size_t j = 0; j < str_array[i].size(); ++j){
          cout << setw(19) << str_array [i][j] << "|";
        }
        cout << "\n\t+" ;
        for(size_t h = 0; h < str_array[i].size(); ++h){
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
   */
  void find_room(string number_str){
    bool find = false;
    // 绘制表格(第一行框架)
    cout << "\t+";
    for(size_t h = 0; h < str_array[0].size(); ++h){
      for(size_t k = 0; k < 19; ++k){
        cout << "-";
      }
      cout << "+";
    }
    cout << "\n";
    // 表格主主体数据
    for(size_t i = 0; i < str_array.size(); ++i){
      if(str_array [i][0] == number_str){
        find = true;
        cout << "\t|";
        for(size_t j = 0; j < str_array[i].size(); ++j){
          cout << setw(19) << str_array [i][j] << "|";
        }
        cout << "\n\t+" ;
        for(size_t h = 0; h < str_array[i].size(); ++h){
          for(size_t k = 0; k < 19; ++k){
            cout << "-";
          }
          cout << "+";
        }
        cout << "\n";
      }
    }
    if (!find) {
      cout << "\t|                the room number not found                  |"
        << endl;
      // 绘制表格(第一行框架)
    cout << "\t+";
    for(size_t h = 0; h < str_array[0].size(); ++h){
      for(size_t k = 0; k < 19; ++k){
        cout << "-";
      }
      cout << "+";
    }
    cout << "\n";
    }
  }
 private:
  string name;
  string line_str;
  vector<vector<string>> str_array;
};
#endif
