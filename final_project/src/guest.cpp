// filename : guest.cpp
#include <iostream>
#include <string>

#include "guest.h"
#include "date.h"
using namespace std;

int main(int argc, char const *argv[]) {
  Date today(1,2,2018);
  Guest a_man("100000", today,"Mr.a");
  a_man.show();

  cout << "\n\n";
  Guest a_woman("108", today, "a", "girl");
  a_woman.show();
  return 0;
}
