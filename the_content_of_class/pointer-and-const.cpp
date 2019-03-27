/**
 * 8.12
 * Attempting to modify a constant pointer to constant data
 */

int main(int argc, char const *argv[]) {
  int x = 5, y;

  // ptr is a constant pointer to a const integer.
  // ptr always points to the same location;
  // the integer at that location cannot be modified
  const int * const ptr = &x; // const pointer must be initialized

  *ptr = 7;// error: *ptr is const; cannot assigned assigned a new value
  ptr = &y; // error: ptr is const; cannot assign to it a new adress
}
/** output
 * pointer-and-const.cpp: In function 'int main(int, const char**)':
 * pointer-and-const.cpp:14:10: error: assignment of read-only location '*(const int*)ptr'
 * *ptr = 7;// error: *ptr is const; cannot assigned assigned a new value
 *           ^
 * pointer-and-const.cpp:15:10: error: assignment of read-only variable 'ptr'
 *    ptr = &y; // error: ptr is const; cannot assign to it a new adress
 */
