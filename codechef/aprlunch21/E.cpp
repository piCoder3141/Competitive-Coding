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
    for (int tt = 1; tt <= t; tt++){
        int n, m, k; cin >> n >> m >> k;
        bool swapped = false;
        if (n > m) swapped = true;
        vector<vector<int>> grid;
        if (swapped) grid.assign(m, vector<int>(n));
        else grid.assign(n, vector<int>(m));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (swapped) cin >> grid[j][i];
                else cin >> grid[i][j];
            }
        }
        if (swapped) swap(n, m);
        int rmask = (1 << n) - 1;
        ll sum, ans = 0;
        vector<int> rows;
        vector<ll> dp(k+1); dp[0] = 1ll;
        for (int msk = 1; msk <= rmask; msk++){
            rows.clear();
            dp.assign(k+1, 0); dp[0] = 1ll;
            for (int r = 0; r < n; r++){
                if (!((msk >> r) & 1)) continue;
                rows.push_back(r);
            }
            for (int i = 0; i < m; i++){
                sum = 0;
                for (auto r : rows) sum += grid[r][i];
                for (int j = k; j > 0; j--){
                    if (sum > j) continue;
                    dp[j] = (dp[j] + dp[j-sum]) % mod;
                }
            }
            ans = (ans + dp[k]) % mod;
        }
        cout << ans << nl; continue;
    }
}

