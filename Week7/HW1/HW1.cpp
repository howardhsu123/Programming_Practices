#include <iostream>
#include <cmath>

using namespace std;

struct BigNum{
    int digit[100];
    BigNum();
    void output(void);
    void input(void);
    BigNum operator + (const BigNum &b) const;
    BigNum operator * (const int &b) const;
    BigNum operator * (const BigNum &b) const;
};

BigNum::BigNum(){
    for(int i = 0 ; i < 100 ; i++)
		digit[i] = 0;
}

void BigNum::input(){
    char str[100];
    cin >> str;
    int len = 0;
    while(1){
        if(str[len] == '\0')
            break;
        len++;
    }

    for(int i = 0 ; i < len ; i++)
		digit[i] = str[len-1-i] - '0';
}

void BigNum::output(void){
    int len;
    for(len = 99; !digit[len] && len >= 0 ; len--);

    for (; len >= 0; len--){
        cout << digit[len];
    }
    cout << endl;
}

BigNum BigNum::operator + (const BigNum &b) const{
    BigNum sum;

    int carry = 0;
    for(int i = 0; i < 100; i++){
        sum.digit[i] = (digit[i] + b.digit[i] + carry) % 10;
        carry = (digit[i] + b.digit[i] + carry) / 10;
    }

    return sum;    
}

BigNum BigNum::operator * (const int &b) const{
    BigNum sum;

    int carry = 0;
    for(int i = 0; i < 100 ; i++){
        sum.digit[i] = (digit[i] * b + carry) % 10;
        carry = (digit[i] * b + carry) / 10;
    }
    
    return sum;
}

BigNum BigNum::operator * (const BigNum &b) const{
    BigNum sum;
    BigNum a = *this;
    for(int i = 0; i < 100; i++){
        sum = sum + a * b.digit[i];
        a = a * 10;
    }

    return sum;
}

int main(void){
    BigNum a;
    BigNum b;
    a.input();
    b.input();
    (a*b).output();
    return 0;
}