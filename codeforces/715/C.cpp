#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1; // cin >> t;
    for (int tt = 1; tt <= t; tt++){
        int n; cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        ll ans = a[n-1] - a[0];
        vector<vector<ll>> dp(n, vector<ll>(n, 0));
        for (int len = 2; len <= n; len++){
            for (int l = 0; l < n - len + 1; l++){
                int r = l + len - 1;
                dp[l][r] = a[r] - a[l] + min(dp[l+1][r], dp[l][r-1]);
            }
        }
        cout << dp[0][n-1];
    }
}

