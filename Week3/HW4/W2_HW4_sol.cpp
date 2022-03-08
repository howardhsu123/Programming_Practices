#include <bits/stdc++.h>

using namespace std ;


int main(void){
	int N, P ;
	cin >> N >> P ;

	int window[500] ;
	fill(window, window+N, 0) ;

	for(int i=0, color=1 ; i<N ; i++){
		if( window[i] == 0 ){
			for(int ii=i ; window[ii]==0 ; ii=(ii+P)%N)
				window[ii] = color ;

			color += 1 ;
		}

		cout << i+1 << " " << window[i] << endl ;
	}

	return 0 ;
}
