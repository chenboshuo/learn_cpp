// filename: manage.cpp
#include <iostream>
#include <string>

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
      }else{
        exit(0);
      }
      system("pause");
      system("cls"); // 清空屏幕

    }
  }

  // // 测试查找空房间
  // m.show_empty_room();
  //
  // // 录入客人信息
  // Date today(1,10,2005);
  // Guest a_woman("119010", today, "what", "female");
  // m.check_in(a_woman, "107");
  // m.show_guest();
  //
  //
  // // 测试房间号查找;
  // m.find_room("101");
  // m.find_room("-1");
  //
  // // 测试退房
  // m.check_out("100");
  return 0;
}
