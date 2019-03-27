/**
 * 8.11
 * Attempting to modify a constant pointer to nonconstant data
 */

int main(int argc, char const *argv[]) {
  int x, y;

  // ptr is a xonstant pointer to an integer that can
  // be modified throu ptr ,  but ptr always points to
  // the same memory location
  int * const ptr = &x; // const pointer must be initialized

  *ptr = 7;// allowed: *ptr is not xonst
  ptr = &y; // error: ptr is const; cannot assign to it a new adress
}
/** output
 * pointer-and-const.cpp: In function 'int main(int, const char**)':
 * pointer-and-const.cpp:15:10: error: assignment of read-only variable 'ptr'
 *    ptr = &y; // error: ptr is const; cannot assign to it a new adress
 */
