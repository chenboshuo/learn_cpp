/* file: inverse_string.cpp */
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
  int i,len;
  string str;
  if (argc != 2) {
    printf("%s\n", "usage: inverse_string <string>");
    return 1;
  }
  str = argv[1];
  len = str.length();
  for (i = 0; i < len/2; i++) {
    char temp = str[i];
    str[i] = str[len-i-1];
    str[len-i-1] = temp;
  }
  cout << str << '\n';
  delete &str;
  return 0;
}
// $ inverse_string abcde
// edcba
