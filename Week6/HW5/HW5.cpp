#include <iostream>
#include <cmath>

using namespace std;

struct Solver{
    int dp[50001];
    int k;
    int coin[11];

    Solver(void){
        cin >> k;
        for(int i = 0; i < k; i++)
            cin >> coin[i];

        for(int i = 1; i < 50001; i++)
            dp[i] = 99999;
        dp[0] = 0;
    }

    int solve(int x){
        for (int i = 0; i < k; i++){
            for (int sum = 1; sum <= x; sum++){
                if (sum < coin[i])
                    continue;
                dp[sum] = min(dp[sum-coin[i]] + 1, dp[sum]);
            }
        }
        return dp[x];
    }
};

int main(void){
    Solver solver;
    int T;
    cin >> T;
    int x;
    while(T--){
        cin >> x;
        cout << solver.solve(x) << endl; 
    }
    
    return 0;
}