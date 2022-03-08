#include <iostream> 
#include <algorithm>

using namespace std;

bool cmp(int a, int b){
    return (a < b);
}

void calculate(uint64_t dp[50010], int c[11], int k){
    dp[0] = 1;
    for (int sum = 1; sum < 50010; sum++){
        dp[sum] = 0;
    }
    for (int i = 1; i <= k; i++){
        for (int sum = c[i-1]; sum < 50010; sum++){
            dp[sum] += dp[sum-c[i-1]];
            dp[sum] %= 1000000007;
        }
    }
}

int main(void){
    uint64_t dp[50010]; // dp[sum] record the combination methods to form sum.
    int k;
    cin >> k;
    int c[11];
    for(int i = 0; i < k; i++){ // currencies
        cin >> c[i];
    }
    sort(c,c+k,cmp);

    calculate(dp,c,k);
    int T;
    /*
    cout << 47500 << ' ' << dp[47500] << endl;
    */
    cin >> T; 
   
    while(T--){ //T test cases
        int x;
        cin >> x;
        cout << dp[x] << endl;
    }
    
    return 0;
}