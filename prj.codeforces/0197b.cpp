#include <iostream>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void printFraction(int a, int b) {
    int g = gcd(abs(a), abs(b));
    a /= g;
    b /= g;

    if (b < 0) {
        a = -a;
        b = -b;
    }

    std::cout << a << "/" << b << std::endl;
}

int main(){
 int n;
 int m;
 std::cin >> n >> m;
 int a0;
 int a_garbage;
 std::cin >> a0;
 for(int i=0;i<n;i++){
     std::cin >> a_garbage;
 }
 int b0;
 int b_garbage;
 std::cin >> b0;
 for(int i=0;i<m;i++){
     std::cin >> b_garbage;
 }
 
 if (n>m){
     if ((a0>0 && b0>0)||(a0<0 && b0<0)){
        std::cout << "Infinity";
     } else {
         std::cout << "-Infinity";
     }
 } else if (n<m){
     std::cout << "0/1";
 } else printFraction(a0,b0);
 
}
