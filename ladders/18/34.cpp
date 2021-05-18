#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const ll MOD = 998244353;
vector<vector<int>> adj, up;
vector<int> tin, tout,lca_cnt, unpaired, end_cnt;
int n, k, l, timer;

void dfs1(int v, int p){
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; i++){
        up[v][i] = up[up[v][i-1]][i-1];
    }

    for (int u : adj[v]){
        if (u != p){
            dfs1(u, v);
        }
    }
    tout[v] = ++timer;
}

bool is_anc(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v){
    if (is_anc(u, v)) return u;
    if (is_anc(v, u)) return v;
    for (int i = l; i >= 0; i--){
        if (!is_anc(up[u][i], v)) u = up[u][i];
    }
    return up[u][0];
}

void dfs2(int v, int p){
    if (adj[v].size() == 1 && v != p){
        unpaired[v] = end_cnt[v] - lca_cnt[v]*2; return;
    }
    for (int u : adj[v]){
        if (u == p) continue;
        dfs2(u, v);
        unpaired[v] += unpaired[u];
    }
    unpaired[v] -= (lca_cnt[v]*2);
    unpaired[v] += end_cnt[v];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    adj.assign(n, vector<int>());
    tin.assign(n, 0); tout.assign(n, 0);
    lca_cnt.assign(n, 0); unpaired.assign(n, 0);
    end_cnt.assign(n, 0);
    timer = 0; l = ceil(log2(n));
    up.assign(n, vector<int>(l+1));
    vector<pii> edges(n-1);
    for (int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v; u--; v--;
        edges[i] = {u, v};
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(0, 0);
    cin >> k;
    for (int i = 0; i < k; i++){
        int a, b; cin >> a >> b; a--; b--;
        int w = lca(a, b);
        lca_cnt[w]++;
        end_cnt[a]++; end_cnt[b]++;
    }
    dfs2(0, 0);
    for (auto e : edges){
        int u = e.first, v = e.second;
        if (u == up[v][0]) swap(u, v);
        cout << unpaired[u] << " ";
    }
}
