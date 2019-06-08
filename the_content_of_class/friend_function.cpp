#include <iostream>

using namespace std;

class Count {
  friend void setX(Count &, int val);  // friend declaration
 private:
  int x;  // data memer

 public:
  Count() : x(0){};

  // output x
  void print() { cout << x << endl; }
};

// function setX can modify private data of Count
// bacause setX is delcare as a friend of Count
void setX(Count &c, int val) { c.x = val; }

int main(int argc, char const *argv[]) {
  Count counter;  // create Count object

  cout << "counter.x after instantiation: " << endl;
  counter.print();
  setX(counter, 8);
  cout << "counter.x after call to setX friend function" << endl;
  counter.print();
  return 0;
}
/**
 * counter.x after instantiation:
0
counter.x after call to setX friend function
8
 */
