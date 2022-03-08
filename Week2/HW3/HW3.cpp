#include <iostream>
#include <string>

uint64_t gcd(uint64_t a, uint64_t b){
    while (a*b){
        if (a >= b)
            a %= b; 
        else
            b %= a;
    }
    return a+b;
}

uint64_t lcm(uint64_t a, uint64_t b){
    return a / gcd(a,b) * b;
}

int main(void){
    uint64_t a,b;
    uint64_t tmp = 0;
    uint64_t sum1 = 0, sum2 = 1;
    std::string answer = "";
    while(std::cin>>a>>b){
        tmp = a/gcd(a,b);
        b = b/gcd(a,b);
        a = tmp;
        sum1 = sum2/gcd(b,sum2)*a + b/gcd(b,sum2)*sum1;
        sum2 = lcm(b,sum2);
        tmp = sum1 / gcd(sum1,sum2);
        sum2 = sum2 / gcd(sum1,sum2);
        sum1 = tmp;
    }
    answer = std::to_string(sum1) + "/" + std::to_string(sum2);
    std::cout << answer << std::endl;
    return 0;
}