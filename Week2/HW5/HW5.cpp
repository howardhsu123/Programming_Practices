#include <iostream>

int main(void){
    uint64_t a,b;
    std::cin >> a >> b;
    uint64_t n = a^b;
    int count = 0;
    while(n){
        count ++;
        n &= n-1;
    }  
    std::cout << count << std::endl;
    return 0;
}