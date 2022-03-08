#include <bits/stdc++.h>

using namespace std ;

struct Status{
	int H, W ;
	int lands[512][512] ;
} ;


int dhdw[][2] = {
	{ 0, 1},
	{ 0,-1},
	{ 1, 0},
	{-1, 0}} ;


int dfs(int h, int w, Status &s){
	/// boundaries ///
	if( h < 0 || s.H <= h )
		return 0 ;
	if( w < 0 || s.W <= w )
		return 0 ;

	/// is uncovered lands? ///
	if( s.lands[h][w] != 1 )
		return 0 ;

	/// color ///
	s.lands[h][w] = 2 ;

	for(int dir=0 ; dir<4 ; dir++)
		dfs( h+dhdw[dir][0], w+dhdw[dir][1], s) ;


	return 1 ;
}


void input(Status &s){
	cin >> s.H >> s.W ;

	for(int h=0 ; h<s.H ; h++){
		for(int w=0 ; w<s.W ; w++)
			cin >> s.lands[h][w] ;
	}
}


int main(void){
	Status status ;

	input(status) ;

	int ans = 0 ;
	for(int h=0 ; h<status.H ; h++){
		for(int w=0 ; w<status.W ; w++)
			ans += dfs(h, w, status) ;
	}

	cout << ans << endl ;

	return 0 ;
}
