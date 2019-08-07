#ifndef ARRAY_H
#define ARRAY_H

#include <iomanip>
#include <iostream>
#include <stdexcept>

using namespace std;

class Array {
  friend istream &operator>>(istream &input, Array &a);
  friend ostream &operator<<(ostream &output, const Array &a);

 public:
  explicit Array(int array_size = 10);
  Array(const Array &right);
  ~Array();  // destructor
  size_t get_size() const;

  const Array &operator=(const Array &);      // assignment
  bool operator==(const Array &right) const;  // equality operator

  // inwquility operator: return the opposite of == operator
  bool operator!=(const Array &right) { return !(*this == right); }

  // subscript operator for const objects return rvalue
  int &operator[](int);

 private:
  size_t size;  // pointer-based array size
  int *ptr;
};

// default constructor for class Array
Array::Array(int array_size)
    : size(array_size > 0
               ? array_size
               : throw invalid_argument("Array size must be greater than 0")),
      ptr(new int[size]) {
  for (size_t i = 0; i < size; ++i) {
    ptr[i] = 0;  // set pointer-based array element
  }
}

// copy instrucotr for class Array;
// must receive a reference to an array
Array::Array(const Array &array_to_copy)
    : size(array_to_copy.size), ptr(new int[size]) {
  for (size_t i = 0; i < size; ++i) {
    ptr[i] = array_to_copy.ptr[i];  // copy into object
  }
}

//  distructor for class Array
Array::~Array() {
  delete[] ptr;  // release pointer based-array space
}

// return number of elements of Array
size_t Array::get_size() const {
  return size;  // number of size in Array
}

// overload assignment operator;
// const return avoids (a1 = a2) = a3
const Array &Array::operator=(const Array &right) {
  if (&right != this) {  // avoid self-assignment
    // for array of difference sizes, dellocate original
    // left-size Array, then allocate new left-side Array
    if (size != right.size) {
      delete[] ptr;
      size = right.size;    // resize this object
      ptr = new int[size];  // create space for Array copy
    }

    for (size_t i = 0; i < size; ++i) {
      ptr[i] = right.ptr[i];  // copy array into object
    }
  }
  return *this;  // enables x = y = z, for example
}

// determine if two arrays are quual and reutrn true,
// otherwise return false
bool Array::operator==(const Array &right) const {
  if (size != right.size) {
    return false;  // arrays of different number of elements
  }

  for (size_t i = 0; i < size; ++i) {
    if (ptr[i] != right.ptr[i]) {
      return false;  // Arrays contents are not equal
    }
  }
  return true;  // Arrays are equal;
}

// overloaded subscript operator for non-const Arrays
// reference return creates a modified lvalue
int &Array::operator[](int subscript) {
  // check for subscript operator for const Arrays;
  // ToDo :   if (subscript < 0 || subscript >= size) {
  if (subscript < 0 || subscript >= size) {
    throw out_of_range("Subscript out of range");
  }
  return ptr[subscript];
}

// overload input operator for class Array
istream &operator>>(istream &input, Array &a) {
  for (size_t i = 0; i < a.size; ++i) { input >> a.ptr[i]; }
  return input;
}

// overload output operator for class Array
ostream &operator<<(ostream &output, const Array &a) {
  // output private ptr-based array
  for (size_t i = 0; i < a.size; ++i) {
    output << setw(12) << a.ptr[i];
    if ((i + 1) % 4 == 0) {  // 4 numbers per row of output
      cout << endl;
    }
  }
  if (a.size % 4 != 0) { cout << endl; }

  return output;  // enables cout << x << y
}
#endif
