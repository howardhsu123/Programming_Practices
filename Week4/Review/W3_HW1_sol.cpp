#include <bits/stdc++.h>

using namespace std ;


struct Board{
	char b[3][4] ;
} ;


bool input(Board &board){
	if( cin >> board.b[0] ){
		cin >> board.b[1] ;
		cin >> board.b[2] ;

		return true ;
	}

	return false ;
}


bool win(Board &board, char player){
	int r, c ;

	/// rows ///
	for(r=0 ; r<3 ; r++){
		for(c=0 ; c<3 ; c++){
			if( board.b[r][c] != player )
				break ;
		}

		if( c == 3 )
			return true ;
	}

	/// cols ///
	for(c=0 ; c<3 ; c++){
		for(r=0 ; r<3 ; r++){
			if( board.b[r][c] != player )
				break ;
		}

		if( r == 3 )
			return true ;
	}

	/// diagonal ///
	for(r=0 ; r<3 ; r++){
		if( board.b[r][r] != player )
			break ;
	}
	if( r == 3 )
		return true ;

	for(r=0 ; r<3 ; r++){
		if( board.b[r][2-r] != player )
			break ;
	}
	if( r == 3 )
		return true ;

	return false ;
}


bool judge(Board &board){
	/// check number ///
	int nx = 0, no = 0 ;
	for( int r=0 ; r<3 ; r++){
		for(int c=0 ; c<3 ; c++){
			if( board.b[r][c] == 'X' )
				nx ++ ;
			else if( board.b[r][c] == 'O' )
				no ++ ;
		}
	}
	if( nx-no > 1 || nx-no < 0 )
		return false ;

	/// win ///
	bool wx = win(board, 'X') ;
	bool wo = win(board, 'O') ;

	if( wx && wo )
		return false ;
	if( wx ){
		if( nx == no )
			return false ;

		cout << "X win" << endl ;
		return true ;
	}
	if( wo ){
		if( nx > no )
			return false ;

		cout << "O win" << endl ;
		return true ;
	}

	/// tie ///
	if( nx+no == 9 ){
		cout << "Tie" << endl ;
		return true ;
	}

	/// Not Yet ///
	cout << "Not yet" << endl ;
	return true ;
}


int main(void){
	Board board ;

	while( input(board) ){
		if(	!judge(board) )
			cout << "Cheating!" << endl ;
	}

	return 0 ;
}
