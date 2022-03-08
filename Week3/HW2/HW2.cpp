#include <iostream>
#include <algorithm>

using namespace std;

struct BigNum{
    int N;
    int digits[100];
    void init(void);
    void output(void);
    void minus(BigNum B);
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

int compare(BigNum A, BigNum B){
    //return 1 if A > B
    //return 0 if A == B
    //return -1 if A < B
    
    if (A.N > B.N)
        return 1; 
    else if (A.N == B.N){
        for (int i = A.N-1; i >= 0; i++){
            if(A.digits[i] > B.digits[i])
                return 1;
            else if (A.digits[i] < B.digits[i])
                return -1;
        }
        return 0;
    }
    return -1;
}
void BigNum::minus(BigNum B){
    int carry = 0;
    int flag = 0;
    for(int i = 0; i < N ; i++){
        digits[i] += 10;
        digits[i] -= B.digits[i] + carry;
        carry = 1 - digits[i] / 10;
        digits[i] %= 10;
        if (digits[i] != 0)
            flag = i;
    }
    N = flag + 1;
}

int main(void){
    BigNum A, B;
    A.init();
    B.init();
    if (compare(A,B) == 1){
        A.minus(B);
        A.output();
    }
    else if (compare(A,B) == -1){
        B.minus(A);
        B.output();
    }
    else
        cout << 0 << endl;  
    return 0;
}