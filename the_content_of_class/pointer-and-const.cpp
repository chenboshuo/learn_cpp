/**
 * 8.10
 * Attempting to modify data through a noconstant
 * pointer to constant data.
 */

void f( const int *xPtr) {
  *xPtr = 100// error cannot modified an illegal modification
}

int main(int argc, char const *argv[]) {
  int y = 0;
  f(&y);
  return 0;
}
/** output
 * pointer-and-const.cpp: In function 'void f(const int*)':
 * pointer-and-const.cpp:8:11: error: assignment of read-only location '* xPtr'
 *  *xPtr = 100;
 */
