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
    flag = 0;
  }

  /**
   * 绘制CSV表
   */
  void show(){
    if (flag) { // 检测标志,看是否改变csv
      read_csv(); // 由于文件改变, 需要重新读取
    }
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
    outfile << a;
    outfile.close();
    outfile.close();
    flag = 1;
  }

  void to_csv(Guest a) {
    ofstream outfile;
    outfile.open(name, ios::app);
    outfile << a;
    outfile.close();
    flag = 1;
  }
 private:
  string name;
  string line_str;
  vector<vector<string>> str_array;
  bool flag = 0;
};
#endif
