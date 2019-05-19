#include <iostream>

using namespace std;
class Base {
 public:
  virtual void display(){
    cout << "Base's display function was called" << endl;
  }
};

class FirstB :public Base{
 public:
  void display() {
    cout << "FirstB's display function was called " << endl;
  }
};

class SecondB :public Base{
 public:
  void display() {
    cout << "SecondB's display function was called " << endl;
  }
};

int main(int argc, char const *argv[]) {
  Base *ptr;
  Base b;
  FirstB b_1;
  SecondB b_2;

  ptr = &b;
  ptr -> display();

  ptr = &b_1;
  ptr -> display();

  ptr = &b_2;
  ptr -> display();
  return 0;
}
/*
Base's display function was called
FirstB's display function was called
SecondB's display function was called
 */
