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
int n; ll x;
int sz;
vector<vector<int>> adj;
vector<ll> values;
void dfs(int v, int p){
    ll val = 1;
    vector<ll> tmp;
    for (auto u : adj[v]){
        if (u == p) continue;
        dfs(u, v);
        tmp.push_back(values[u]);
    }
    sort(tmp.rbegin(), tmp.rend());
    sz = tmp.size();
    for (int i = 1; i <= sz; i++) val += tmp[i-1]* i;
    values[v] = val;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++){
        cin >> n >> x;
        adj.assign(n, vector<int>());
        values.assign(n, 0ll);
        for (int i = 0; i < n-1; i++){
            int u, v; cin >> u >> v; u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0, -1);
        ll ans = values[0] % mod; 
        ans = (ans * x) % mod;
        cout << ans << nl;
    }
}

