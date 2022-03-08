#include <iostream>

int main(void){
    char name[8] = "Alice";
    for( int i = 0; name[i]; i++ )
        std::cout << i << ": " << name[i] << " " << std::endl;
    for( int i = 0; i < sizeof(name) ; i++)
        std::cout << i << ": " << name[i] << " " << std::endl;
    return 0;
}