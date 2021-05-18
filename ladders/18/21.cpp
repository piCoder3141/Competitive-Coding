#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t= 1; // cin >> t;
    for (int tt = 1; tt <= t; tt++){
        ll n, m, b, mod; cin >> n >> m >> b >> mod;
        vector<vector<vector<ll>>> dp(2, vector<vector<ll>>(m+1, vector<ll>(b+1)));
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        dp[0][0][0] = 1;
        for (int i = 1; i <= n; i++){
            int idx = i & 1;
            for (int j = 0; j <= m; j++){
                for (int k = 0; k <= b; k++){
                    dp[idx][j][k] = dp[idx ^ 1][j][k];
                    if (j > 0 && k >= a[i-1]){
                        dp[idx][j][k] += dp[idx][j-1][k-a[i-1]];
                    }
                    dp[idx][j][k] %= mod;
                }
            }
        }
        ll ans = 0;
        for (int k = 0; k <= b; k++){
            ans = (ans + dp[n&1][m][k]) % mod;
        }
        cout << ans;
    }
}

