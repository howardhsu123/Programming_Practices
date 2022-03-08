#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std ;

bool cmp(pair<int16_t,int64_t> A, pair<int16_t,int64_t> B){
    return (A.second < B.second);
}

struct Polynomial{
	vector<pair<int16_t,int64_t>> data ;

	Polynomial(){
		data.reserve(100) ;
	}

	void input(){
		int N ;
		cin >> N ;

		for(int i=0 ; i<N ; i++){
            pair<int16_t,int64_t> tmp;
			cin >> tmp.first >> tmp.second;
			data.emplace_back(tmp);
		}

		sort(data.begin(), data.end(), cmp) ;
	}

	Polynomial operator + (const Polynomial &b) const {
		Polynomial ans ;

		int i_a = 0 ;
		int i_b = 0 ;

		while( i_a < data.size() && i_b < b.data.size() ) {
			auto d_a = data[i_a].second ;	// renaming
			auto d_b = b.data[i_b].second ;
            pair<int16_t,int64_t> tmp;

			if( d_a == d_b ){
                tmp.first = data[i_a].first + b.data[i_b].first;
                tmp.second = data[i_a].second;
				ans.data.emplace_back(tmp) ;

				i_a ++ ;
				i_b ++ ;
			}
			else if( d_a < d_b ){
				tmp.first = data[i_a].first;
                tmp.second = data[i_a].second;
				ans.data.emplace_back(tmp) ;
				i_a ++ ;
			}
			else{
				tmp.first = b.data[i_b].first;
                tmp.second = b.data[i_b].second;
				ans.data.emplace_back(tmp);
				i_b ++ ;
			}
		}

        for( ; i_a < data.size() ; i_a++ ){
            pair<int16_t,int64_t> tmp;
            tmp.first = data[i_a].first;
            tmp.second = data[i_a].second;
			ans.data.emplace_back(tmp);
        }
		for( ; i_b < b.data.size() ; i_b++ ){
            pair<int16_t,int64_t> tmp;
			tmp.first = b.data[i_b].first;
            tmp.second = b.data[i_b].second;
			ans.data.emplace_back(tmp);
        }

		return ans ;
	}
};


int main(void){
	Polynomial S1, S2, S3 ;

	S1.input() ;
	S2.input() ;
	
    S3 = S1+S2;

    bool isnotfirst = false;
    bool iszero = true;
    for(int i = S3.data.size() - 1; i >= 0; i--){
        if (!S3.data[i].first)
            continue;
        else if (S3.data[i].first > 0){
            iszero = false;
            if (isnotfirst){
                if(S3.data[i].second > 1){
                    if (S3.data[i].first != 1)
                        cout << "+" << S3.data[i].first << "x^" << S3.data[i].second;
                    else
                        cout << "+" << "x^" << S3.data[i].second;
                }
                else if(S3.data[i].second == 1){
                    if (S3.data[i].first != 1)
                        cout << "+" << S3.data[i].first << "x";
                    else
                        cout << "+x";
                }
                else
                    cout << "+" << S3.data[i].first;
            }
            else{
                if(S3.data[i].second > 1){
                    if (S3.data[i].first != 1)
                        cout << S3.data[i].first << "x^" << S3.data[i].second;
                    else
                        cout << "x^" << S3.data[i].second;
                }
                else if(S3.data[i].second == 1){
                    if (S3.data[i].first != 1)
                        cout << S3.data[i].first << "x";
                    else
                        cout << "x";
                }
                else
                    cout << S3.data[i].first;

                isnotfirst = true;
            }
        }
        else {
            iszero = false;
            if (isnotfirst){
                if(S3.data[i].second < 1){
                    if (S3.data[i].first != -1)
                        cout << S3.data[i].first << "x^" << S3.data[i].second;
                    else
                        cout << "x^" << S3.data[i].second;
                }
                else if(S3.data[i].second == -1){
                    if (S3.data[i].first != -1)
                        cout  << S3.data[i].first << "x";
                    else
                        continue;
                }
                else
                    cout << S3.data[i].first;
            }
            else{
                if(S3.data[i].second > -1){
                    if (S3.data[i].first != -1)
                        cout << S3.data[i].first << "x^" << S3.data[i].second;
                    else
                        cout << "-x^" << S3.data[i].second;
                }
                else if(S3.data[i].second == -1){
                    if (S3.data[i].first != -1)
                        cout << S3.data[i].first << "x";
                    else
                        cout << "-x";
                }
                else
                    cout << S3.data[i].first;

                isnotfirst = true;
            }
        }
    }
    if (iszero)
        cout << "0" << endl;
    else
        cout << endl;

	return 0 ;
}
