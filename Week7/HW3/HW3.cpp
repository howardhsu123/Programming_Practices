#include <iostream>

using namespace std;

int solve(const int &n, const int &k, int dp1[102], bool dp2[102]){
    int t = 0;
    while(n - t){
        dp1[t+1] = dp1[t] ;
        for(int i = 1; i <= k; i++){
            dp1[t+1] ++; // next one
            dp1[t+1] %= (n + 1);
            while (dp2[(dp1[t+1])]){
                dp1[t+1] ++;//skip death
                dp1[t+1] %= (n + 1); 
            }
        }
        dp2[dp1[++t]] = true ;
    }
    return dp1[n];
}

int main(void){
    int n,k;
    while(cin >> n){
        cin >> k;
        int dp1[102]; // record the number of death at t-th run;
        bool dp2[102]; // record true if the i-th person is dead;
        dp1[0] = 0;
        for(int i = 0; i <= n; i++)
            dp2[i] = false;
        dp2[0] = true;

        cout << solve(n,k,dp1,dp2) << endl;
    }
    return 0;
}