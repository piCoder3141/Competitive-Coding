#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const ll MOD = 998244353;

int n, m;

vector<vector<int>> adj;
vector<bool> vis;
vector<int> component;

void dfs(int v){
    vis[v] = true;
    component.push_back(v);
    for (auto u : adj[v]){
        if (vis[u]) continue;
        dfs(u);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    adj.assign(n, vector<int>());
    vis.assign(n, false);
    bool ans = true; 
    vector<ll> a(n), b(n);
    ll sa=0, sb = 0;

    // input
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++){
        if (vis[i]) continue;
        component.clear();
        dfs(i);
        sa = sb =0;
        for (auto x : component){
            sa += a[x]; sb += b[x];
        }
        if (sa != sb){
            ans = false; break;
        }
    }

    cout << (ans ? "Yes" : "No");
}

// Do a DFS and find the connected components. Check if the sum of a]i] and b[i] is the same for this component. 
// If all the compoennts pass the test. 
