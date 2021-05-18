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

const int MX = 1e5 + 1;
ll fact[MX+1], inv_fact[MX+1];

void preprocess(){
    fact[0] = inv_fact[0]  = 1;
    for (int i = 1; i < MX; i++){
        fact[i] = (fact[i-1] * i) % mod;
        inv_fact[i] = powmod(fact[i], mod-2);
    }
}

ll choose(ll n, ll r){
    ll ans = fact[n];
    ans = (ans * inv_fact[r]) % mod;
    ans = (ans * inv_fact[n-r]) % mod;
    return ans;
}

vector<vector<int>> pos, adj;
bool imposs;
vector<int> v;
vector<ll> subtree, value;

int make_tree(int start, int l, int r){
    if (start == -1) return -1;
    if (pos[start].size() == 0){
        imposs = true; return -1;
    }
    int cand = lower_bound(pos[start].begin(), pos[start].end(), l) - pos[start].begin();
    if (cand > r || cand == (int) pos[start].size()){
        imposs = true; return -1;
    }
    int root = upper_bound(pos[start].begin(), pos[start].end(), r) - pos[start].begin() - 1;
    root = pos[start][root];
    int left, right;
    if (root > l){
        left = make_tree(start, l, root-1);
        if (left == -1) return -1;
        adj[root].push_back(left);
    }
    if (root < r){
        right = make_tree(start+1, root+1, r);
        if (right == -1) return -1;
        adj[root].push_back(right);
    }
    return root;
}

void dfs(int v){
    if (adj[v].size() == 0){
        subtree[v] = 1ll;
        value[v] = 1ll;
        return;
    }
    ll sub_size = 0;
    ll prod = 1, one_sub;
    for (auto u : adj[v]){
        dfs(u);
        sub_size += subtree[u];
        prod = (prod * value[u]) % mod;
        one_sub = subtree[u];
    }
    subtree[v] = 1ll*sub_size + 1ll;
    value[v] = (prod * choose(sub_size, one_sub)) % mod;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    preprocess();
    for (int tt = 1; tt <= t; tt++){
        int n; cin >> n;
        pos.assign(n, vector<int>());
        adj.assign(n, vector<int>());
        v.assign(n, 0);
        subtree.assign(n, 0ll);
        value.assign(n, 0ll);
        imposs = false;
        for (int i = 0; i < n; i++){
            cin >> v[i]; v[i]--;
            pos[v[i]].push_back(i);
        } 
        int root = make_tree(0, 0, n-1);
        if (imposs){
            cj(tt) << 0 << nl;
            continue;
        }
        dfs(root);
        cj(tt) << value[root] << nl;
    }
}

