// filename: time.cpp
#include "Time.h"
int main(int argc, char const *argv[]) {
  Time t;

  // initialize hourRef with the reference returned by bad_set_hour
  unsigned int &hourRef = t.bad_set_hour(20); // 20 is a valid hour
  cout << "Valid hour before modification: " << hourRef << endl;

  hourRef = 30;
  cout << "\nInvalid hour after modification: " << t.get_hour() << endl;

  // Dangerous : Function call that returns
  // a reference can be used as an Ivalue
  t.bad_set_hour(12) = 74;
  cout << "\nPOOR PROGRAMING PRACTICE!!!!!"
    << "\nt.bad_set_hour(12) as an  Ivalue, invalid hour: "
    << t.get_hour()
    << endl;
}
 /*

## 9.8 time实例研究--返回private数据成员的应用或指针

对hourRef 的赋值其实在修改private的值, 破坏类的封装性
output

Valid hour before modification: 20

Invalid hour after modification: 30

POOR PROGRAMING PRACTICE!!!!!
t.bad_set_hour(12) as an  Ivalue, invalid hour: 74

 */
