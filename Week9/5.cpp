#include <iostream> 
using namespace std;
const int V = 50;
int g[V][V], dp[V], stk[V][V], mx;

int dfs(int n, int ns, int dep){
        if (0 == ns) {
            if (dep > mx)
                mx = dep;
            return 1;
        }
    int i, j, k, p, cnt;
    for (i = 0; i < ns; i++) {
        k = stk[dep][i];

        if (dep + n - k <= mx)
            return 0;
        if (dep + dp[k] <= mx)
            return 0;

        cnt = 0;
        for (j = i + 1; j < ns; j++) {
            p = stk[dep][j];
            if (g[k][p])
                stk[dep + 1][cnt++] = p;
        }
        dfs(n, cnt, dep + 1);
    }
    return 1;
}
int clique(int n) {
     int i, j, ns;
     mx = 0;
     for ( i = n - 1; i >= 0; i--) {
        ns = 0;
        for (j = i + 1; j < n; j++)
            if (g[i][j])
                stk[1][ns++] = j;
        dfs(n, ns, 1);
        dp[i] = mx;
    }
    return mx;
}

int main(void){
    int N;
    cin >> N;

    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++){
            g[i][j] = 0;
        }
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> g[i][j];
        }
    }

    cout << clique(N) << endl;
   
    return 0;
}