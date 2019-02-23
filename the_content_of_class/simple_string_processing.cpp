#include <string.h>
#include <stdlib.h>
main(){
char *str1;
char *str2="Test" ;
str1=malloc(5);
strcpy(str1,str2);
printf("%s", str1);
free(str1);
}
