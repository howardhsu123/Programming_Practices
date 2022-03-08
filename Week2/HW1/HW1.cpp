#include <iostream>

int main(void){
    int32_t a, b;
    while(std::cin >> a >> b){
        if (a>b){
            std::cout << a;
            std::cout << " ";
            std::cout << b << std::endl;
        }
        else{
            std::cout << b;
            std::cout << " ";
            std::cout << a << std::endl;
        }
    }
    return 0;
}