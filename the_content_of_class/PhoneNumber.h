// filename: PhoneNumber.h
// PhoneNumber calss definition
#ifndef PHONENUMBER_H
#define PHONENUMBER_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
class PhoneNumber {
 public:
  friend ostream &operator<<(ostream &output, const PhoneNumber &number);
  friend istream &operator>>(istream &input, PhoneNumber &number);

 private:
  string area_code;  // 3-digit area code
  string exchange; // 3-digit exchange
  string line;  // 4-digit line

};

#endif

/** overload stream insertion operator;
 * cannot be a member function if we would like to
 * invoke(调用) it with
 * cout << some_phone_number;
 *
 */
ostream &operator<<(ostream &output, const PhoneNumber &number){
  output << "(" << number.area_code << ")"
    << number.exchange << "-" << number.line;
}

/**
 * overload the stream extraction
 * cannot be a member function if we would like to invoke it with
 * cin >> some_phone_number
 */
istream &operator>>(istream &input, PhoneNumber &number){
  input.ignore();  // skip "("
  input >> setw(3) >>  number.area_code; // input area_code
  input.ignore(2); // skip ") "
  input >> setw(3) >> number.exchange;  // input exchange
  input.ignore();  // skip dash "-"
  input >> setw(4) >> number.line;  // input line
  return input;  // enables cin >> a >> b >> c;
}
