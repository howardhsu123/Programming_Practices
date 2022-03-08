#include <bits/stdc++.h>

using namespace std ;


bool board[6][6] ;
int N ;

int rows[6], cols[6] ;


int dfs(int r, int c){
	/// safe ///
	if( r == N )
		return 1 ;

	if( c == N )
		return dfs(r+1, 0) ;


	/// try ///
	int sum = 0 ;

	/// skip ///
	sum += dfs(r, c+1) ;

	/// test ///
	if( !board[r][c] && rows[r] < 2 && cols[c] < 2 ){
		//board[r][c] = true ;
		rows[r] ++ ;
		cols[c] ++ ;

		sum += dfs(r, c+1) ;

		cols[c] -- ;
		rows[r] -- ;
		//board[r][c] = false ;
	}

	return sum ;
}


int main(void){
	/// initialize ///
	cin >> N ;
	for(int r=0 ; r<N ; r++){
		for(int c=0 ; c<N ; c++)
			board[r][c] = false ;

		rows[r] = 0 ;
		cols[r] = 0 ;
	}

	/// put k ///
	int k ;
	cin >> k ;

	int r, c ;
	while( k-- ){
		cin >> r >> c ;

		board[r][c] = true ;
		rows[r] ++ ;
		cols[c] ++ ;
	}

	/// answer ///
	cout << dfs(0,0) << endl ;

	return 0 ;
}
