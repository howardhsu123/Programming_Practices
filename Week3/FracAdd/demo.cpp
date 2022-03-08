#include <iostream>

using namespace std;

struct Fraction{
    int64_t numerator;
    int64_t denominator;
};

int64_t gcd (int64_t a, int64_t b){
    while (a && b){
        if (a > b)
            a %= b;
        else
            b %= a;
    }
    return a+b;
}

int64_t lcm (int64_t a, int64_t b){
    return a/gcd(a,b) * b;
}

Fraction add(Fraction v1, Fraction v2){
    Fraction answer;
    
    answer.numerator = v2.denominator/gcd(v1.denominator,v2.denominator) * v1.numerator + v1.denominator/gcd(v1.denominator,v2.denominator) * v2.numerator; 
    answer.denominator = lcm(v1.denominator, v2.denominator);
    int64_t d = gcd (answer.numerator, answer.denominator);
    answer.numerator /= d;
    answer.denominator /= d;
    return answer;
}

int main(void){
    Fraction frac[100];
    Fraction sum{0, 1};

    int number_of_frac;
    for (number_of_frac = 0; cin >> frac[number_of_frac].numerator >> frac[number_of_frac].denominator; number_of_frac++){
        int64_t d = gcd (frac[number_of_frac].numerator, frac[number_of_frac].denominator);
        frac[number_of_frac].numerator /= d; 
        frac[number_of_frac].denominator /= d;
        cout << frac[number_of_frac].numerator << "/" << frac[number_of_frac].denominator << endl;
        sum = add(sum,frac[number_of_frac]);
        cout << sum.numerator << "/" << sum.denominator << endl;
    }

    

    return 0;
}