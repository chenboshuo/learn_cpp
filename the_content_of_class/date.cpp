#include "Date.h"
#include "Employee.h"

using namespace std;

int main(int argc, char const *argv[]) {
  Date birth(7, 24, 1949);
  Date hire(3, 12, 1988);
  Employee manager("Bob", "Blue", birth, hire);

  cout << endl;
  manager.print();
}
/**
 * output
Date object constructor for date 7/24/1949
Date object constructor for date 3/12/1988
Employee object constructor: Bob Blue

Blue, Bob Hired: 3/12/1988 Birthday: 7/24/1949
Employ object destructor: Blue, Bob
Date object destructor for date 3/12/1988
Date object destructor for date 7/24/1949
Date object destructor for date 3/12/1988
Date object destructor for date 7/24/1949

这些输出确认 Employee 对象是由外而内进行撤销的, 即Employee的析构函数首先运行,
然后成员对象与他们构造相反的顺序撤销.

 */
