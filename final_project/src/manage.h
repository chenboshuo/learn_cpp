// fileneme: manage.h
#include <iostream>

// #include "date.h"
#include "room.h"
#include "csv.h"

using namespace std;
#ifndef MANAGE_H
#define MANAGE_H
/**
 * 实现管理操作
 */
class Manage {
 public:
  Manage(){}
  /**
   * 将房间a写入csv
   * @param a 要写入的房间
   */
  void new_room(Room a) {
    Csv room_csv("data/room.csv");
    room_csv.to_csv(a);
  }

  void show_room() {
    Csv room_csv("data/room.csv");
    room_csv.read_csv();
    room_csv.show();
  }

  void show_guest() {
    Csv guest_csv("data/guest.csv");
    guest_csv.read_csv();
    guest_csv.show();
  }

  void new_guest(Guest a) {
    Csv guest_csv("data/guest.csv");
    guest_csv.to_csv(a);
  }

  void show_empty_room() {
    Csv room_csv("data/room.csv");
    room_csv.read_csv();
    room_csv.find_empty_room();
  }

  void find_room(string number_str) {
    Csv room_csv("data/room.csv");
    room_csv.read_csv();
    room_csv.find_room(number_str);
  }
 private:

};
#endif
