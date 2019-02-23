/* file: inverse_string.cpp */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  int i,len;
  char *str;
  if (argc != 2) {
    printf("%s\n", "usage: inverse_string <string>");
    return 1;
  }
  len = strlen(argv[1]);
  str = (char*)malloc(len+1);
  for (i = 0; i < len; i++) {
    str[i] = argv[1][len-1-i];
  }
  str[i] = '\0';
  printf("%s\n", str);
  free(str);
  return 0;
}
// $ inverse_string abcde
// edcba
