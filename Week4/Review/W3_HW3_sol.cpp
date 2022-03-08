#include <bits/stdc++.h>

using namespace std ;


uint64_t ans(int r, int c, uint64_t buf[66][66]){
	if( buf[r][c] == 0 ){
		if( c == 0 )
			buf[r][c] = 1 ;
		else if( c == r )
			buf[r][c] = 1 ;
		else
			buf[r][c] = ans(r-1, c, buf) + ans(r-1, c-1, buf) ;
	}

	return buf[r][c] ;
}


int main(void){
	uint64_t buf[66][66] = {0} ;

	int r, c ;
	while(cin >> r >> c)
		cout << ans(r, c, buf) << endl ;

	return 0 ;
}
