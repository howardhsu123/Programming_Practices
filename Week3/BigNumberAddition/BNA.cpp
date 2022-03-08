#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

struct BigNum{
    int N;
    int digits[100];
    void init(void);
    void output(void);
    void add(BigNum B);
};

void BigNum::init(void){
    fill(digits,digits+100,0);
    cin >> N;
    for(int i = N - 1; i >= 0; i--){
        cin >> digits[i];
    } 
}

void BigNum::output(void){
    for(int i = N-1; i >= 0 ; i--){
        cout << digits[i];
    }
    cout << endl;
}

void BigNum::add(BigNum B){
    int carry = 0; 
    int i;
    for (i = 0; i <= min(B.N,N) || carry ;i++){
        digits[i] += carry + B.digits[i];
        carry = digits[i] / 10;
        digits[i] %= 10;
    }
    N = i;
}

int main(void){
    BigNum A, B;
    A.init();
    B.init();
    A.add(B);
    A.output();
    return 0;
}