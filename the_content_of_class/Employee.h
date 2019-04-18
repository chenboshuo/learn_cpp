// file: Employee.h
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
  // const Date birth_date; // composition: member object
  // const Date hire_date; // composition: member object

  // static member data
  static unsigned int count; // number of objects instantiated

public:
  Employee(const string &first, const string &last);
  ~Employee(); // provide to confirm destruction order

  string get_first_name() const;
  string get_last_name() const;
  static unsigned int get_count(); // return # of objects instantiated
};

#endif

// define and initialize static at global namespace scope
unsigned int Employee::count = 0;// cannot include keyword static

/**
 * define static memer function that returns numbers of
 * Employee objects instantiated
 * @return count
 */
unsigned int Employee::get_count(){
  return count;
}


Employee::Employee(const string &first, const string &last)
  : first_name(first), last_name(last){
  ++count; // increment static count of employees
  cout << "Employee object constructor: "
    << first_name << ' ' << last_name << endl;
};


Employee::~Employee(){
  cout << "Employ object destructor: "
    << last_name << ", " << first_name << endl;
  --count;
}


string Employee::get_first_name() const {
  return first_name;
}

string Employee::get_last_name() const {
  return last_name;
}
