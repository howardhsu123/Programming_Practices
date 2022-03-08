#include <bits/stdc++.h>

using namespace std ;


struct Matrix{
	uint64_t m[2][2] ;
} ;


Matrix mult(Matrix &a, Matrix &b, uint64_t R){
	Matrix m ;
	m.m[0][0] = m.m[0][1] = m.m[1][0] = m.m[1][1] = 0 ;

	for(int r=0 ; r<2 ; r++){
		for(int c=0 ; c<2 ; c++){
			for(int i=0 ; i<2 ; i++){
				m.m[r][c] += a.m[r][i] * b.m[i][c] ;
				m.m[r][c] %= R ;
			}
		}
	}

	return m ;
}


/// n >= 1 ///
Matrix power(uint64_t n, uint64_t R){
	Matrix m ;

	m.m[0][0] = 0 ; m.m[0][1] = 1 ;
	m.m[1][0] = 1 ; m.m[1][1] = 1 ;

	/// m^1 ///
	if( n == 1 )
		return m ;

	/// m^n = m^(n/2) ///
	Matrix m_2 = power(n/2, R) ;
	m_2 = mult(m_2, m_2, R) ;

	if( n%2 )
		m_2 = mult(m_2, m, R) ;

	return m_2 ;
}


uint64_t F(uint64_t n, uint64_t R){
	if( n==0 )
		return 0 ;

	Matrix m = power(n, R) ;

	// |a b|^n  |0|
	// |c d|  * |1|
	return m.m[0][1] ;
}


int main(void){
	uint64_t n, R ;
	cin >> n >> R ;

	cout << F(n, R) << endl ;

	return 0 ;
}
