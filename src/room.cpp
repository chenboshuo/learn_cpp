// filename: room.cpp
// a test for room.h
#include <iostream>
#include <fstream>

#include "room.h"


int main(int argc, char const *argv[]) {
  Room room_1("101", "single room");
  room_1.show();
  room_1.check_in();
  room_1.check_out();
  // room_1.record();
  /* output
    room's room_number: 101
    type: single room
    The room is empty
    The guests succeddfully checked in the room101
    The gusest successfully checked out
   */

  cout << "\n" << endl;

  Room room_2("102", "statand room", true);
  room_2.show();
  room_2.check_in();
  room_2.check_out();
  room_2.check_out();
  // room_2.record();
  /* room's number: 102
    type: statand room
    The room is full
    The room is full, you can't chick into this room
    Done
    The room is empty, you can't do this
   */

  // 测试文件写入
  ofstream out("temp.txt",ios::app);
  out << room_2;
  return 0;
}
/*
room's room_number: 101
type: single room
The room is empty
The guests succeddfully checked in the room 101
The gusest successfully checked out


room's room_number: 102
type: statand room
The room is full
The room is full, you can't chick into this room
The gusest successfully checked out
The room is empty, you can't do this
 */
