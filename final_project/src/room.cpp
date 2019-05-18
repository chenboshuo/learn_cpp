// filename: room.cpp
// a test for room.h
#include "room.h"

#include <iostream>

int main(int argc, char const *argv[]) {
  Room room_1("101", "single room");
  room_1.show();
  room_1.check_in();
  room_1.check_out();
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
  /* room's number: 102
    type: statand room
    The room is full
    The room is full, you can't chick into this room
    Done
    The room is empty, you can't do this
   */

  return 0;
}
/*
room's room_number: 101
type: single room
The room is empty
The guests succeddfully checked in the room101
The gusest successfully checked out


room's number: 102
type: statand room
The room is full
The room is full, you can't chick into this room
Done
The room is empty, you can't do this
 */
