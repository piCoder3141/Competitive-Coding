#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const ll MOD = 998244353;
int n, m;
ll ans = 0;
vector<vector<int>> adj;
vector<int> col;

bool safe(int v, int c){
    for (auto u : adj[v]){
        if (col[u] == c) return false;
    }
    return true;
}

void solve(int v){
    if (v == n){
        ans++;
        return;
    }
    for (int c = 1; c <= 3; c++){
        if (safe(v, c)){
            col[v] = c;
            solve(v+1);
            col[v] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    adj.assign(n, vector<int>());
    col.assign(n, 0);
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    solve(0);
    cout << ans;
}


