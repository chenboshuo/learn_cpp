// filename: csv.cpp
#include <iostream>
#include <string>
#include <fstream>

#include "csv.h"
#include "date.h"
#include "guest.h"

using namespace std;

int main(int argc, char const *argv[]) {
  Csv guest_csv("data/guest.csv");
  cout << "This is the guest information:\n\n";
  guest_csv.read_csv();
  guest_csv.show();

  // 测试写入文件
  Date today(1,2,2018);
  Guest a_woman("108", today, "admin", "girl");
  guest_csv.to_csv(a_woman);
  guest_csv.show();

  cout << "This is the room information:\n\n";
  Csv room_csv("data/room.csv");
  room_csv.read_csv();
  room_csv.show();

  cout << "\n\nAdd a single room:" << endl;
  Room a("1026", "single room");
  room_csv.to_csv(a);
  room_csv.show();
  cout << "\n\n find:" << endl;
  room_csv.find_empty_room();
  cout << room_csv.find_room("1024") << endl;
  cout << room_csv.find_room("-1") << endl; // 测试找不到

  // 测试退房
  cout << room_csv.check_out("107");

  // 测试入住
  cout << room_csv.check_in("107") << endl;
  // cout << room_csv.check_out("110");
  return 0;
}
