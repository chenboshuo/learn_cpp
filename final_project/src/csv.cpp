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

  cout << "This is the room information:\n\n";
  Csv room_csv("data/room.csv");
  room_csv.read_csv();
  return 0;
}
