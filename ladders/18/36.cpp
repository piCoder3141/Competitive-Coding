#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const ll MOD = 998244353;
const int inf = 1e9;
vector<vector<pii>> adj;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    adj.assign(n, vector<pii>());
    vector<int> vis(n, false), par(n, -1);
    map<pii, int> used;
    vector<pair<pii, int>> edges(m);
    for (int i = 0;i < m; i++){
        int x, y, z; cin >> x >> y >> z; x--; y--;
        adj[x].emplace_back(y, z);
        adj[y].emplace_back(x, z);
        edges[i] = {{x, y}, z};
    }
    int st = 0, dest = n-1;
    vector<int> d(n, inf), z_val(n, -1);
    queue<int> q;
    q.push(st); d[st] = 0; z_val[st] = 0;
    int sz;
    while(!q.empty()){
        sz = q.size();
        for (int i = 0; i < sz; i++){
            int v = q.front(); q.pop();
            for (auto e : adj[v]){
                int u = e.first, z = e.second;
                if (d[u] <= d[v]) continue;
                if (z_val[u] >= z_val[v] + z) continue;
                z_val[u] = z_val[v] + z;
                if (d[u] == inf) q.push(u);
                d[u] = d[v] + 1;
                par[u] = v;
            }
        }
    }
    vector<int> path;
    while (par[dest] != -1){
        path.push_back(dest);
        dest = par[dest];
    }
    path.push_back(0);
    int ps = path.size();
    for (int i = 1; i < ps; i++){
        int u = path[i], v = path[i-1];
        used[make_pair(u, v)] = used[make_pair(v, u)] = 1;
    }
    int K = 0;
    vector<vector<int>> ans;
    for (int i = 0; i < m; i++){
        int u, v, z; 
        u = edges[i].first.first; v = edges[i].first.second;
        z = edges[i].second;
        if (used[make_pair(u, v)] == 1 && z == 0){
            K++;
            ans.push_back({u+1, v+1, 1});
        }
        if (used[make_pair(u, v)] == 0 && z == 1){
            K++;
            ans.push_back({u+1, v+1, 0});
        }
    }
    cout << K << "\n";
    for (auto e : ans){
        for (auto x : e) cout << x << " ";
        cout << "\n";
    }
}
