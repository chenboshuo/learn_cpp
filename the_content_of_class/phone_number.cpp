// filename: phone_number
#include "PhoneNumber.h"

int main(int argc, char const *argv[]) {
  PhoneNumber phone;  // create object phone

  cout << "Enter phone number in the form (xxx) xxx-xxxx" << endl;

  // cin >> phone involkes operator >> by implicitly issuing
  // the non-member function call operator >> (cin, phone)
  cin >> phone;

  cout << "The phone number entered was: ";

  cout << phone << endl;  // calls << (cout, phone)
  return 0;
}
/**
 * Enter phone number in the form (xxx) xxx-xxxx
 * (123) 456-7890
 * The phone number entered was: (123)456-7890
 */
