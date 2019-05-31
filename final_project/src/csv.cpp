// filename: csv.cpp
#include <iostream>
#include <string>
#include <fstream>

#include "csv.h"
#include "Date.h"
#include "Guest.h"

using namespace std;

int main(int argc, char const *argv[]) {
  Csv guest_csv("data/guest.csv");
  cout << "This is the guest information:\n\n";
  guest_csv.read_csv();
  guest_csv.show();

  // 测试写入文件
  Date today(1,2,2018);
  Guest a_woman("108", today, "a", "girl");
  guest_csv.to_csv(a_woman);

  cout << "This is the room information:\n\n";
  Csv room_csv("data/room.csv");
  room_csv.read_csv();
  room_csv.show();

  Room a("1024", "single room");
  room_csv.to_csv(a);
  room_csv.show();
  return 0;
}
