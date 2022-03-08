#include <iostream>

using namespace std;

int gcd(int a,int b){
    while (a && b){
        if (a > b)
            a %= b;
        else
            b %= a;
    }
    return a+b;
}

int main(void){
    int n;
    int p;
    cin >> n >> p;
    for(int i = 1; i <= n; i++){
        cout << i << ' ' ;
        if (i % gcd(n,p))
            cout << (i % gcd(n,p)) ;
        else
            cout << i % gcd(n,p) + gcd(n,p);
        cout << endl;
    }
    return 0;
}