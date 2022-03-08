#include <iostream>
#include <cmath>
using namespace std;

typedef struct bottom{
    uint64_t s[34];
    int num[2];
}bottom;

uint64_t comb(int a, int b);
bottom thearray(int a, int b);

uint64_t comb(int a, int b){
    if(b > a-b)
        return comb(a,a-b);
    if(a == 0)
        return 1;
    if(b == 0 || b == a)
        return 1;
    bottom init = thearray(a,b);
    for(int i = 0; i < init.num[1] - init.num[0]; i++){
        for (int j = init.num[0]; j > 0; j--){
            init.s[j] += init.s[j-1];
        }
    }

    for(int i = 0; i < b; i++){
        for(int j = 0; j <= init.num[0]-1; j++)
            init.s[j] += init.s[j+1];
        init.num[0] --;
    }
    return init.s[0];
}

bottom thearray(int a, int b){
    bottom init;
    init.num[0] = min(a-b,b);
    init.num[1] = max(a-b,b);
    for (int i = 0; i <= init.num[0]; i++)
        init.s[i] = comb (init.num[0],i);
    return init;  
}

int main(void){
    int a,b;
    while(cin >> a >> b)
        cout << comb(a,b) << endl;
    return 0;
}