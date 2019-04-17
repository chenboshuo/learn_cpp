#ifndef EMPLOYE_E
#define EMPLOYE_E

#include <string>
#include "Date.h"
#include <iostream>

using namespace std;

class Employee{
private:
  string first_name; // composition: member object
  string last_name; // composition: member object
  const Date birth_date; // composition: member object
  const Date hire_date; // composition: member object

public:
  Employee(const string &first, const string &last,
           const Date &date_of_bitrh, const Date &date_of_hire);
  void print() const;
  ~Employee(); // provide to confirm destruction order
};

Employee::Employee(const string &first, const string &last,
  const Date &date_of_bitrh, const Date &date_of_hire)
  : first_name(first), last_name(last), birth_date(date_of_bitrh),
    hire_date(date_of_hire){
  cout << "Employee object constructor: "
    << first_name << ' ' << last_name << endl;
};

void Employee::print() const {
  cout << last_name << ", " << first_name << " Hired: ";
  hire_date.print();
  cout << " Birthday: ";
  birth_date.print();
  cout << endl;
}

Employee::~Employee(){
  cout << "Employ object destructor: "
    << last_name << ", " << first_name << endl;
}

#endif
