#include <stdio.h>
#include <string.h>
#include <stdlib.h>// malloc
main(){
char *str1;
char *str2="Test" ;
str1=(char *)malloc(5);
strcpy(str1,str2);
printf("%s\n", str1);
free(str1);
}
// output
// Test
