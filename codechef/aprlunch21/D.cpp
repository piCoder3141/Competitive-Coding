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

int n, k, a;
vector<int> height, last, has_spec, spec, spec_child;
vector<vector<int>> adj;

void dfs1(int v, int p, int h){
    height[v] = h;
    if (spec[v]){
        has_spec[v] = 1;
        spec_child[v] = v;
    }
    for (auto u : adj[v]){
        if (u == p) continue;
        dfs1(u, v, h+1);
        if (has_spec[u]){
            has_spec[v] = 1;
            spec_child[v] = spec_child[u];
        }
    }
}

void dfs2(int v, int p, int prev){
    last[v] = prev;
    if (has_spec[v]) last[v] = v;
    for (auto u : adj[v]){
        if (u == p) continue;
        dfs2(u, v, last[v]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++){
        cin >> n >> k >> a; a--;
        spec.assign(n, 0);
        adj.assign(n, vector<int>());
        for (int i = 0;i < k; i++){
            int x;
            cin >> x; spec[x-1] = 1;
        }
        for (int i = 0;i < n-1; i++){
            int u, v; cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        height.assign(n, 0);
        last.assign(n, 0);
        has_spec.assign(n, 0);
        spec_child.assign(n, -1);
        dfs1(a, -1, 0);
        dfs2(a, -1, a);
        for (int i = 0; i < n; i++){
            cout << 2*height[last[i]] - height[i] << " ";
        }
        cout << nl;
        for (int i = 0; i < n; i++){
            cout << spec_child[last[i]] + 1 << " ";
        }
        cout << nl;
    }
}
// for each v I need - height[v], last[v], has_spec[v]
// height and has_spec in dfs1
// last in dfs2
// final answer for b = height[last[b]] - (height[b] - height[last[b]])
