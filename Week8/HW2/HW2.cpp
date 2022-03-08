#include <iostream>
#include <cmath>

using namespace std;

struct map{
    int H,W,S;
    int starts[10001][2];
    uint16_t dp[100][100];
    int move[4][2]{
        {1,0},
        {-1,0},
        {0,1},
        {0,-1}
    };
    map(){
        cin >> H >> W;

        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++)
                dp[i][j] = UINT16_MAX;
        }

        cin >> S;
        for(int i = 0; i < S; i++){
            cin >> starts[i][0] >> starts[i][1];
            dp[starts[i][0]][starts[i][1]] = 0;
        }
    }
    void solve(){
        for(uint16_t i = 0; i < H; i++){
            for(uint16_t j = 0; j < W; j++){
                for(int k = 0; k < S; k++){
                    uint16_t tmp = abs(i - starts[k][0]) + abs(j - starts[k][1]);
                    dp[i][j] = min(tmp,dp[i][j]);
                }
            }
        }
    } 
};



int main(void){
    map A;
    A.solve();

    for(int i = 0; i < A.H; i++){
        for(int j = 0; j < A.W; j++){
            if (A.dp[i][j] == 0)
                cout << '@';
            else
                cout << A.dp[i][j]%10;
        }
        cout << endl;
    }    
    return 0;
}