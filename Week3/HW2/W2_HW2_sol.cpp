#include <bits/stdc++.h>

using namespace std;

struct BigNumber{
	int digit[50] ;
} ;


BigNumber read(void){
	int d ;
	cin >> d ;

	BigNumber num ;
	fill(num.digit, num.digit+50, 0) ;

	for(int i=d-1 ; i>=0 ; i--)
		cin >> num.digit[i] ;

	return num ;
}


void print(BigNumber num){
	int i ;
	for(i=50-1 ; i>0 ; i--){
		if( num.digit[i] )
			break ;
	}

	for( ; i>=0 ; i-- )
		cout << num.digit[i] ;

	cout << endl ;
}


bool cmp(BigNumber a, BigNumber b){
	for(int i=50-1 ; i>=0 ; i--){
		if( a.digit[i] != b.digit[i] )
			return a.digit[i] < b.digit[i] ;
	}

	return false ;
}


BigNumber sub(BigNumber a, BigNumber b){
	int carry = 0 ;
	for( int i=0 ; i<50 ; i++){
		a.digit[i] += carry - b.digit[i] ;

		if( a.digit[i] < 0 ){
			a.digit[i] += 10 ;
			carry = -1 ;
		}
		else
			carry = 0 ;
	}

	return a ;
}


int main() {
	BigNumber a = read() ;
	BigNumber b = read() ;

	if( cmp(b, a) )
		print(sub(a, b)) ;
	else
		print(sub(b, a)) ;

	return 0 ;
}
