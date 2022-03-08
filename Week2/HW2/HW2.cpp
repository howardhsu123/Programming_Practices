#include <iostream>
#include <string>
#include <cmath>

int main(void){
    uint32_t n;
    std::cin >> n;
    std::string answer = std::to_string(n) + "=";
    int k = 0;
    while (n % 2 == 0){
        n = n / 2;
        k ++;
    }
    if (k == 1)
        answer += std::to_string(2) + "x";
    if ( k > 1 )
        answer += std::to_string(2) + "^" + std::to_string(k) + "x";

    for(uint32_t i = 3;i<=sqrt(n);i+=2){
        k = 0;
        while (n % i == 0){
            n /= i;
            k ++;
        }
        if (k == 1)
            answer += std::to_string(i) + "x";
        if (k > 1)
            answer += std::to_string(i) + "^" + std::to_string(k) + "x";
    }
    if(n!=1)
        answer += std::to_string(n);
    else
        answer.pop_back();
    std::cout << answer << std::endl;
    return 0;
}
