#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const ll MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll r, g; cin >> r >> g;
    if (r > g) swap(r, g);
    ll tot = r+g;
    ll h[901], pref[901];
    h[0] = 0; pref[0] = 0;
    for (ll i = 1; i <= 900; i++){
        h[i] = i;
        pref[i] = pref[i-1] + h[i];
    }
    ll pos = upper_bound(pref, pref + 901, tot)- pref - 1;
    vector<vector<ll>> dp(1+1, vector<ll>(r+1, 0));
    dp[0][r] = 1ll;
    ll y, idx = 1;
    for (ll t = 1; t <= pos; t++){
        for (ll x = max(0ll, r-pref[t]); x <= r; x++){
            y = tot - pref[t] - x;
            if (y < 0) continue;
            if (x + h[t] <= r) dp[idx][x] = (dp[idx][x] + dp[idx^1][x + h[t]]) % MOD;
            if (y + h[t] <= g) dp[idx][x] = (dp[idx][x] + dp[idx^1][x]) % MOD;
        }
        idx ^= 1;
        dp[idx].assign(r+1, 0);
    }
    ll ans = 0;
    for (ll x = 0; x <= r; x++){
        ans = (ans + dp[pos&1][x]) % MOD;
    }
    cout << ans;
}

// dp[t][r] -> Filled top 't' levels with 'r' red blocks remaining.
// dp[t+1][r][g] -> dp[t][r][g+h(t+1)] + dp[t][r+h(t+1)][g];
// t+1 -> total - pref(t+1) - r
