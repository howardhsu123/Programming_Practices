#include <bits/stdc++.h>

int gcd(int a, int b){
    while (a * b != 0){
        if (a >= b){
           a -= b; 
        }
        else{
            b -= a;
        }
    }
    return a+b;
}

int lcm(int a, int b){
    return a / gcd(a,b) * b;
}

int main(void){
    int value1, value2;

    std::cin >> value1 >> value2;

    std::cout << gcd(value1,value2) << std::endl ;
    std::cout << lcm(value1,value2) << std::endl ;

    return 0;
}