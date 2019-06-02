// filename: manage.cpp
#include <iostream>

#include "date.h"
#include "room.h"
#include "manage.h"
using namespace std;

int main(int argc, char const *argv[]) {
  Manage m;

  // 测试客房信息的录入
  Room a("100", "single room", "fulle");
  m.new_room(a);
  m.show_room();

  // 录入客人信息
  Date today(1,10,2005);
  Guest a_woman("11901", today, "admin", "female");
  m.new_guest(a_woman);
  m.show_guest();

  // 测试查找空房间
  m.show_empty_room();

  // 测试房间号查找;
  m.find_room("101");
  m.find_room("-1");
  return 0;
}
