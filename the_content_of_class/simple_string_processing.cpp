#include <cstring>
#include <iostream>
using namespace std;

main(){
char *str1;
char *str2="Test" ;
str1=new char[50];
strcpy(str1,str2);
cout<<str1<<endl;
delete[] str1;

}
// output
// Test
