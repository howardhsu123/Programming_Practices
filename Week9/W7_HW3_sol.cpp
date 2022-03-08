#include <bits/stdc++.h>

using namespace std ;

struct Set{
	vector<int32_t> data ;

	Set(){
		data.reserve(30000) ;
	}

	void input(){
		int N ;
		cin >> N ;

		for(int i=0 ; i<N ; i++){
			int32_t v ;
			cin >> v ;

			data.emplace_back(v) ;
		}

		sort(data.begin(), data.end()) ;
	}

	void output(){
		for(int i=0 ; i<data.size() ; i++ )
			cout << " " << data[i] ;
		cout << endl ;
	}

	Set operator * (const Set &b) const {
		Set ans ;

		int i_a = 0 ;
		int i_b = 0 ;

		while( i_a < data.size() && i_b < b.data.size() ) {
			auto d_a = data[i_a] ;	// renaming
			auto d_b = b.data[i_b] ;

			if( d_a == d_b ){
				ans.data.emplace_back(d_a) ;

				i_a ++ ;
				i_b ++ ;
			}
			else if( d_a < d_b )
				i_a ++ ;
			else
				i_b ++ ;
		}

		return ans ;
	}

	Set operator + (const Set &b) const {
		Set ans ;

		int i_a = 0 ;
		int i_b = 0 ;

		while( i_a < data.size() && i_b < b.data.size() ) {
			auto d_a = data[i_a] ;	// renaming
			auto d_b = b.data[i_b] ;

			if( d_a == d_b ){
				ans.data.emplace_back(d_a) ;

				i_a ++ ;
				i_b ++ ;
			}
			else if( d_a < d_b ){
				ans.data.emplace_back(d_a) ;
				i_a ++ ;
			}
			else{
				ans.data.emplace_back(d_b) ;
				i_b ++ ;
			}
		}

		// clean up
		for( ; i_a < data.size() ; i_a++ )
			ans.data.emplace_back(data[i_a]) ;
		for( ; i_b < b.data.size() ; i_b++ )
			ans.data.emplace_back(b.data[i_b]) ;

		return ans ;
	}
};


int main(void){
	Set S1, S2 ;

	S1.input() ;
	S2.input() ;

	cout << "union:" ;
	(S1+S2).output() ;

	cout << "intersection:" ;
	(S1*S2).output() ;

	return 0 ;
}
