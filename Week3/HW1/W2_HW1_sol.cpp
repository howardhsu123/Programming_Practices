#include <bits/stdc++.h>

using namespace std ;


int main(void){
	int digits[10] ;

	int value ;
	while(cin >> value){
		digits[0] = value/10 ;
		digits[1] = value%10 ;

		for(int i=2 ; i<10 ; i++)
			cin >> digits[i] ;

		int sum = digits[0] * 1 ;
		for(int i=1, s=9 ; i<10 ; i++, s--)
			sum += digits[i] * s ;

		int checksum = (10 - sum%10) %10 ;

		cout << value << "-" ;
		for(int i=2 ; i<10 ; i++)
			cout << digits[i] ;
		cout << checksum << endl ;
	}

	return 0 ;
}
