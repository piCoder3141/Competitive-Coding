#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define cj(t) cout << "Case #" << t << ": "
#define nl "\n"

const int inf = 1e9;
const ll INF = 1e18;
const ll mod = 1e9 + 7;

ll powmod(ll x, ll y, ll md = mod){
    ll ret = 1;
    while (y > 0){
        if (y&1) ret = (ret*x) % md;
        x = (x*x) % md; y /= 2;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    const int MX = 1e6;
    vector<int> dp(MX+1, -1); dp[1] = 1;
    for (int N = 3; N <= MX; N++){
        int val = N-1, mx = 1;
        for (int p = 2; p*p <= val; p++){
            if (val % p != 0) continue;
            mx = max(mx, dp[val/p]);
            mx = max(mx, dp[p]);
        }
        dp[N] = 1 + mx;
    }

    for (int tt = 1; tt <= t; tt++){
        int n; cin >> n;
        int ans = 1;
        for (int p = 3; p*p <= n; p++){
            if (n % p != 0) continue;
            ans = max(ans, dp[n/p]);
            ans = max(ans, dp[p]);
        }
        cj(tt) << ans << nl;
    }
}

