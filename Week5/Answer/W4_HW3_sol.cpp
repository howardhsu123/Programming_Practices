#include <bits/stdc++.h>

using namespace std ;


struct Status{
	int H, W ;

	char map[32][32] ;
	uint32_t steps[32][32] ;
} ;


void input(Status &s){
	cin >> s.H >> s.W ;

	for(int h=0 ; h<s.H ; h++){
		cin >> s.map[h] ;

		for(int w=0 ; w<s.W ; w++){
			if( s.map[h][w] != 'S' )
				s.steps[h][w] = UINT32_MAX-1 ;
			else
				s.steps[h][w] = 0 ;
		}
	}
}


void solve(Status &s){
	int dhdw[][2] = {
		{ 0, 1},
		{ 0,-1},
		{ 1, 0},
		{-1, 0},
		{ 1, 1},
		{-1,-1},
		{ 1,-1},
		{-1, 1}} ;

	/// try updating ///
	for(bool updated=true ; updated ; ){
		updated = false ;

		/// scan map ///
		for(int h=0 ; h<s.H ; h++){
			for(int w=0 ; w<s.W ; w++){
				/// wall ///
				if( s.map[h][w] == '#' )
					continue ;

				/// neighbor ///
				for(int dir=0 ; dir<8 ; dir++){
					int hh = h + dhdw[dir][0] ;
					int ww = w + dhdw[dir][1] ;

					/// valid neighnor ///
					if( 0<=hh && hh<s.H && 0<=ww && ww<s.W ){
						/// can be update from neighbor? ///
						if( s.steps[h][w] > s.steps[hh][ww]+1 ){
							s.steps[h][w] = s.steps[hh][ww]+1 ;
							updated = true ;
						}
					}
				}
			}
		}
	}
}


void output(Status &s){
	for(int h=0 ; h<s.H ; h++){
		for(int w=0 ; w<s.W ; w++){
			if( s.map[h][w] == 'E' ){
				cout << "(" << h+1 << "," << w+1 << "):" ;

				if( s.steps[h][w] < UINT32_MAX-1 )
					cout << s.steps[h][w] << endl ;
				else
					cout << "unavailable" << endl ;
			}
		}
	}
}


int main(void){
	Status status ;

	input(status) ;
	solve(status) ;
	output(status) ;

	return 0 ;
}
