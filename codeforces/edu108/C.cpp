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
        // n, u, s, sz(n), studs, pref, ans
        int n; cin >> n;
        vector<int> u(n), sz(n);
        vector<ll> s(n), ans(n+1);
        vector<vector<ll>> studs(n+1, vector<ll>());
        for (int i = 0; i < n; i++){
            cin >> u[i]; u[i]--;
        }
        for (int i = 0; i < n; i++){
            cin >> s[i];
        }
        for (int i = 0; i < n; i++){
            studs[u[i]].push_back(s[i]);
            sz[u[i]]++;
        }
        for (int i = 0; i < n; i++){
            sort(studs[i].rbegin(), studs[i].rend());
            for (int j = 1; j < sz[i]; j++){
                studs[i][j] += studs[i][j-1];
            }
            for (int k = 1; k <= sz[i]; k++){
                int last = sz[i] - 1 - (sz[i] % k);
                ans[k] += studs[i][last];
            }
        }
        for (int i = 1; i <= n; i++) cout << ans[i] << " ";
        cout << nl;
    }
}

