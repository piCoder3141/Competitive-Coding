#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const ll MOD = 998244353;
vector<vector<int>> adj, grid;
int n, m;
vector<bool> vis;
bool cycle = false;

int dx[] = {0, 1}, dy[] = {1, 0};

bool valid(int x, int y){
    return (x < n && x >= 0 && y < m && y >= 0);
}
void dfs(int v, int p){
    vis[v] = true;
    for (auto u : adj[v]){
        if (u == p) continue;
        if (vis[u]){
            cycle = true; continue;
        }
        dfs(u, v);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    string s; 
    grid.assign(n, vector<int>(m));
    for (int i = 0; i < n; i++){
        cin >> s;
        for (int j = 0; j < m; j++){
            int c = s[j] - 'A';
            grid[i][j] = c;
        }
    }
    int V = n*m, v, w;
    adj.assign(V, vector<int>());

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            v = i*m + j;
            for (int k = 0; k < 2; k++){
                int x = i + dx[k], y = j + dy[k];
                if (!valid(x,y)) continue;
                w = x*m + y;
                if (grid[i][j] == grid[x][y]){
                    adj[v].push_back(w);
                    adj[w].push_back(v);
                }
            }
        }
    }
    vis.assign(V, false);
    for (int i = 0; i < V; i++){
        if (vis[i]) continue;
        dfs(i, -1);
        if (cycle) break;
    }
    cout << (cycle ? "Yes": "No") << "\n";
}


