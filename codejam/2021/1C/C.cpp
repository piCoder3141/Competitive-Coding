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

int bin_not(int v){
    if (v == 0) return 1;
    string sv = "";
    while (v > 0){
        if (v&1) sv += '1';
        else sv += '0';
        v /= 2;
    }
    reverse(sv.begin(), sv.end());
    string ans = "";
    for (auto c : sv){
        if (c == '0') ans += '1';
        else ans += '0';
    }
    return stoi(ans, nullptr, 2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++){
        string a, b; cin >> a >> b;
        int A = stoi(a, nullptr, 2), B = stoi(b, nullptr, 2);
        int MX = 1 << 16;
        vector<int> vis(MX, -1);
        vis[A] = 0;
        queue<int> q;
        q.push(A);
        while (!q.empty()){
            int sz = q.size();
            for (int i = 0; i < sz; i++){
                int v = q.front(); q.pop();
                if (v*2 < MX){
                    if (vis[v*2] == -1){
                        vis[v*2] = vis[v] + 1;
                        q.push(v*2);
                    }
                }
                int u = bin_not(v);
                if (vis[u] == -1){
                    vis[u] = vis[v] + 1;
                    q.push(u);
                }
            }
        }
        if (vis[B] == -1){
            cj(tt) << "IMPOSSIBLE" << nl;
        }
        else cj(tt) << vis[B] << nl;
    }
}

