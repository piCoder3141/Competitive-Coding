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
int n;
vector<vector<int>> adj;

pll dfs(int v, int p){
    pll ret = {1ll, 0ll};
    // ends & mids; ret.second += mids; ret.first += 2 *ends;
    // sq = (ends*ends) % mod; sum_of_sq = sum_of_sq + sq % mod; sum += ends; 
    // ret.second += (sum*sum) % mod - sum_of_sq + mod)
    ll ends=0, mids=0, sq=0, sum_of_sq=0, sum=0, tmp=0;
    for (auto u : adj[v]){
        if (u == p) continue;
        pll p = dfs(u, v);
        ends = p.first; mids = p.second;
        ret.second = (ret.second + mids) % mod;
        ret.first = (ret.first + 2*ends) % mod;
        sq = (ends*ends) % mod; sum_of_sq = (sum_of_sq + sq) % mod;
        sum = (sum + ends) % mod;
    }
    tmp = ((sum*sum)%mod - sum_of_sq + mod) % mod;
    ret.second = (ret.second + tmp) % mod;
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++){
        cin >> n;
        adj.assign(n, vector<int>());
        for (int i = 0; i < n-1; i++){
            int u, v; cin >> u >> v; u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        pll p = dfs(0, -1);
        ll ans = (p.first + p.second) % mod;
        cout << ans << nl;
    }
}

