#include <iostream>
#include<climits>
int max(int a, int b){
// inline int max(int a, int b){
    return a>b? a: b;
}
int main() {
    int t = 10000000;
    int c;
    while(t--)
        c = max(INT_MAX,1000000000);
    std::cout << c;
}
/*
没有inline
Finished in 16 ms
2147483647

加上inline
Finished in 8 ms
2147483647
*/
