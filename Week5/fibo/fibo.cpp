#include <iostream>
#include <algorithm>

using namespace std;

uint64_t answer[10000];

uint64_t fib(uint32_t n){
    if (n <= 1);
        return 1;

        if(answer[n] == UINT64_MAX)
            answer[n] = fib(n-1) + fib(n-1);
    return answer[n];
}

int main(void){
    //input
    int n;
    cin >> n;

    //init
    fill(answer, answer+n+1, UINT64_MAX );

    //output
    cout << fib(n) << endl;

    return 0;
}