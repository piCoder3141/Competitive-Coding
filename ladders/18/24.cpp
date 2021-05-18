#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const ll MOD = 998244353;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    ll actual = 0, ans;
    vector<vector<int>> pos(n+1);
    vector<ll> a(m);
    for (int i = 0; i < m; i++){
        cin >> a[i];
        if (i > 0) actual += abs(a[i] - a[i-1]);
        pos[a[i]].push_back(i);
    }
    ans = actual;
    // cout << ans << endl;
    vector<ll> adj;
    ll diff_or, diff_new;
    for (int i = 1; i <= n; i++){
        diff_or = diff_new = 0;
        adj.clear();
        for (auto p : pos[i]){
            if (p > 0 && i != a[p-1]) adj.push_back(a[p-1]);
            if (p < m-1 && i != a[p+1]) adj.push_back(a[p+1]);
        }
        sort(adj.begin(), adj.end());
        for (auto b : adj) diff_or += abs(b - i);
        int sz = adj.size();
        ll median = adj[sz/2];
        for (auto b : adj) diff_new += abs(b - median);
        ans = min(ans, actual - diff_or + diff_new);
    }
    cout << ans;
}

// pos[i] <- all the position where `i` appears. 
// For each i from 1 to n. -> for each p in pos.
// maintain mn_large, mx_small (initially i), cnt_large, cnt_small
// ans = min(ans, actual - abs(change_large - change_small))
