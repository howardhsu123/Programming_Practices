#include <iostream>
#include <algorithm>

using namespace std ;


struct Solver{
	int16_t ans[1000001] ;

	Solver(){
		fill(ans, ans+1000001, INT16_MAX) ;

		ans[0] = 1 ;
	}

	int16_t solve(int x){
		if( x<0 )
			return 0 ;

		if( ans[x] == INT16_MAX ){
			int16_t sum = 0 ;

			sum += solve(x-1) ;
			sum %= 1000000007 ;

			sum += solve(x-5) ;
			sum %= 1000000007 ;

			sum += solve(x-10) ;
			sum %= 1000000007 ;

			sum += solve(x-50) ;
			sum %= 1000000007 ;

			ans[x] = sum ;
		}

		return ans[x] ;
	}
} ;


int main(void){
	Solver solver ;

	int x ;
	while( cin >> x )
		cout << solver.solve(x) << endl ;

	return 0 ;
}
