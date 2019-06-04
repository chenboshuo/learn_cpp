// filename: manage.cpp
#include <iostream>
#include <string>
#include <cstring>

#include "date.h"
#include "room.h"
#include "manage.h"
using namespace std;

int main(int argc, char const *argv[]) {
  Manage m;
  Date today;
  if (argc == 1) {
    while (true) {
      int flag;
      cout << "+---------------------------------------------+"
      << "\n|          Hotel Management Dystem            |"
      << "\n+---------------------------------------------+"
      << "\n|\t1: Show all room                      |"
      << "\n|\t2: Show all guest                     |"
      << "\n|\t3: Find empty room                    |"
      << "\n|\t4: Check in                           |"
      << "\n|\t5: Check out                          |"
      << "\n|\t6: Find the room by room number       |"
      << "\n|\t7: Add a new room                     |"
      << "\n|\tYou can press other button to exit    |"
      << "\n+---------------------------------------------+"<< endl;
      cin >> flag;
      system("cls");
      if (flag==1) {
        m.show_room();
      }else if(flag==2){
        m.show_guest();
      }else if(flag==3){
        m.show_empty_room();
      }else if(flag==4){
        string id_card,name, gender,room_number;
        m.show_empty_room();
        cout << "Plese input the guest's information:\nID_card: ";
        cin >> id_card;
        cout << "Name: ";
        std::cin >> name;
        cout << "Gender: " ;
        std::cin >> gender;
        cout << "Room number: ";
        std::cin >> room_number;
        Guest new_guest(id_card,today,name, gender) ;
        m.check_in(new_guest, room_number);
      }else if(flag==5){
        string room_number;
        cout << "Please input the room number: ";
        std::cin >> room_number;
        m.check_out(room_number);
      }else if(flag==6){
        string room_number;
        cout << "input your room number: ";
        cin >> room_number;
        cout << "\n";
        m.find_room(room_number);
      }else if(flag==7){
        string room_number, room_type;
        cout << "Please input the information of the room" << endl;
        cout << "number name: ";
        std::cin >> room_number;
        cout << "room type: ";
        std::cin >> room_type;
        Room a_room(room_number, room_type);
        m.new_room(a_room);
      }else{
        exit(0);
      }
      system("pause");
      system("cls"); // 清空屏幕

    }
  }else{
    if(!strcmp(argv[1], "show") &&!strcmp( argv[2], "room")){
      m.show_room();
    }else if(!strcmp(argv[1], "show") &&!strcmp( argv[2], "guest")){
      m.show_guest();
    }else if(!strcmp(argv[1], "show") &&!strcmp( argv[2], "empty")){
      m.show_empty_room();
    }else if(!strcmp(argv[1], "in")){
      string id_card(argv[2]), name(argv[3]), gender(argv[4]);
      string room_number(argv[5]);
      Guest new_guest(id_card, today, name, gender);
      m.check_in(new_guest, room_number);
    }else if(!strcmp(argv[1], "out")){
      string room_number(argv[2]);
      m.check_out(room_number);
    }else if(!strcmp(argv[1], "find")){
      string room_number(argv[2]);
      m.find_room(room_number);
    }else if(!strcmp(argv[1], "add")){
      string room_number(argv[2]);
      string room_type(argv[3]);
      Room a_room(room_number, room_type);
      m.new_room(a_room);
    }else{
      cout << "usage: "
        << "manage show room : Show all room.\n"
        << "manage show guset : Show all guest.\n"
        << "manage show empty : Find empty room.\n"
        << "manage in <id card> <name> <gender> <room number>:Check in.\n"
        << "manage out <room number>:Check out.\n"
        << "manage find <room number>:Find the room by room number.\n"
        << "manage add <room number> <room type>:Add a new room.\n"
        << endl;
    }
  }

  return 0;
}
