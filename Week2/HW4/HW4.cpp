#include <iostream>

int main(void){
    int n = 0;
    int water = 0;
    int m = 0;
    while(std::cin >> m){
        if(m >= n)
            n = m;
        else
            water += n-m;
    }
    std::cout << water << std::endl;
    return 0;
}