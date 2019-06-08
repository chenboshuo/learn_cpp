#include <iostream>
#include <string>

using namespace std;

class Create_and_destory {
 private:
  int objectID;
  string message;

 public:
  Create_and_destory(int id, string message_string)
      : objectID(id), message(message_string) {
    std::cout << "Object" << objectID << "  constructor runs  " << message
              << '\n';
  }

  virtual ~Create_and_destory() {
    // output newline for certain objects
    cout << (objectID == 1 || objectID == 6 ? "\n" : "");

    std::cout << "Object" << objectID << "  destructor runs  " << message
              << '\n';
  }
};

void create(void) {
  cout << "\nCREATE FUNCTION: EXECUTION BEGINS" << '\n';
  Create_and_destory fifth(5, "(locate automatic in create)");
  static Create_and_destory sixth(6, "(local static in create)");
  Create_and_destory seventh(7, "(locate automatic in create)");
  cout << "\nCREATE FUNCTION: EXECUTION ENDS" << '\n';
}

Create_and_destory first(1, "(global before main)");  // global object

int main(int argc, char const *argv[]) {
  cout << "\nMAIN FUNCTION: EXECUTION BEGINS" << endl;
  Create_and_destory second(2, "(local automic in main)");
  static Create_and_destory third(3, "(local static in main)");

  create();  // call function to create objects

  cout << "\nMAIN FUNCTION: EXECUTION RESUMES" << endl;
  Create_and_destory fourth(4, "(local automatic in main)");
  cout << "\nMAIN FUNCTION: EXECUTION ENDS" << endl;
  return 0;
}
/**
 * Object1  constructor runs  (global before main)

MAIN FUNCTION: EXECUTION BEGINS
Object2  constructor runs  (local automic in main)
Object3  constructor runs  (local static in main)

CREATE FUNCTION: EXECUTION BEGINS
Object5  constructor runs  (locate automatic in create)
Object6  constructor runs  (local static in create)
Object7  constructor runs  (locate automatic in create)

CREATE FUNCTION: EXECUTION ENDS
Object7  destructor runs  (locate automatic in create)
Object5  destructor runs  (locate automatic in create)

MAIN FUNCTION: EXECUTION RESUMES
Object4  constructor runs  (local automatic in main)

MAIN FUNCTION: EXECUTION ENDS
Object4  destructor runs  (local automatic in main)
Object2  destructor runs  (local automic in main)

Object6  destructor runs  (local static in create)
Object3  destructor runs  (local static in main)

Object1  destructor runs  (global before main)
 */
