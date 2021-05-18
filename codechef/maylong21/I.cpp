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

int n;
vector<int> ans, days;
vector<bool> others;
vector<vector<int>> adj;

void dfs(int v, int p){
    if (adj[v].size() == 1 && p != -1) return;
    int mn_days = 2*n + 1;
    for (auto u : adj[v]){
        if (u == p) continue;
        dfs(u, v);
        mn_days = min(mn_days, days[u]);
    }
    for (auto u : adj[v]){
        if (u == p) continue;
        if (days[u] > mn_days){
            others[v] = true;
            break;
        }
    }
    if (!others[v] || p == -1) days[v] = mn_days + 1;
    else days[v] = mn_days + 2;
}

void reconstruct(int v, int p, int alive_at){
    if (adj[v].size() == 1 && p != -1){
        ans.push_back(v); return;
    }
    int threshold, mn_days;
    if (alive_at == -1){
        if (!others[v] || p == -1){
            for (auto u : adj[v]){
                if (u == p) continue;
                if (days[u] == days[v] - 1) reconstruct(u, v, -1);
            }
        }
        else{
            threshold = days[v] - 1;
            for (auto u : adj[v]){
                if (u == p) continue;
                if (days[u] >= threshold) reconstruct(u, v, threshold);
            }
        }
    }
    else{
        if (!others[v]){
            for(auto u : adj[v]){
                if (u == p) continue;
                reconstruct(u, v, alive_at);
            }
        }
        else{
            mn_days = 2*n + 1;
            for (auto u : adj[v]){
                if (u == p) continue;
                mn_days = min(mn_days, days[u]);
            }
            threshold = min(alive_at, mn_days+1);
            for (auto u : adj[v]){
                if (u == p) continue;
                if (days[u] >= threshold) reconstruct(u, v, threshold);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++){
        cin >> n;
        days.assign(n, 0);
        others.assign(n, false);
        adj.assign(n, vector<int>());

        for (int i = 0; i < n-1; i++){
            int u, v; cin >> u >> v; u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ans.clear();
        dfs(0, -1);
        reconstruct(0, -1, -1);

        cout << ans.size() << " " << days[0] << nl;
        sort(ans.begin(), ans.end());
        for (auto x : ans) cout << x+1 << " ";
        cout << nl;
    }
}
// Need -> days[v]: Minimum number of days to reach a given node. (Excluding 0). (One DFS)
// Reconstruct(v, p, alive_at = -1)
// If (v is leaf) add to answer.
// If (alive_at != -1)
//   If (!others[v] || p == -1) dfs(u, v, -1) if (days[u] == days[v] -1)
//   else reconstruct(u, v, threshold) where threshold = days[v] - 1 && days[u] >= threshold
//Else
//   If (!others[v]) dfs(u, v, alive_at) for every child. 
//   else reconstruct(u, v, threshold) where threshold = min(mn_days+1, alive_at) && days[u] >= threshold
