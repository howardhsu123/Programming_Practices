#include <bits/stdc++.h>

using namespace std ;


struct XY{
	double x, y ;
	bool done ;
} ;


double distance(XY &a, XY &b){
	double dx = a.x - b.x ;
	double dy = a.y - b.y ;

	return sqrt(dx*dx + dy*dy) ;
}


int main(void){
	int N ;
	cin >> N ;

	XY xy[512] ;
	for(int i=0 ; i<N ; i++){
		cin >> xy[i].x >> xy[i].y ;
		xy[i].done = false ;
	}

	double sum = 0 ;
	XY now = {0,0,false} ;

	for(int i=0 ; i<N ; i++){
		double max_d = 0 ;
		int max_j ;

		for(int j=0 ; j<N ; j++){
			if( xy[j].done )
				continue ;

			double d = distance(now, xy[j]) ;
			if( max_d < d ){
				max_d = d ;
				max_j = j ;
			}
		}

		xy[max_j].done = true ;

		sum += max_d ;
		now = xy[max_j] ;

		cout << fixed << setprecision(2) << sum << endl ;
	}


	return 0 ;
}
