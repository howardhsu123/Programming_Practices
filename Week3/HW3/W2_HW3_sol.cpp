#include <bits/stdc++.h>

using namespace std;

struct Score{
	int a, b, c, d ;
	int s ;
} ;


Score read(void){
	Score score ;

	cin >> score.a ;
	cin >> score.b ;
	cin >> score.c ;
	cin >> score.d ;

	score.s = score.a
			+ score.b
			+ score.c
			+ score.d ;

	return score ;
}


void print(Score score){
	cout << score.s << " "
		 << score.a << " "
		 << score.b << " "
		 << score.c << " "
		 << score.d << endl ;
}


bool cmp(Score x, Score y){
	if( x.s != y.s )
		return x.s > y.s ;
	if( x.a != y.a )
		return x.a < y.a ;
	if( x.b != y.b )
		return x.b < y.b ;
	if( x.c != y.c )
		return x.c < y.c ;
	return x.d < y.d ;
}


int main() {
	int N ;
	cin >> N ;

	Score score[500] ;
	for(int i=0 ; i<N ; i++)
		score[i] = read() ;

	sort(score, score+N, cmp) ;

	for(int i=0 ; i<N ; i++)
		print(score[i]) ;

	return 0 ;
}
