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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++){
        int n, m; cin >> n >> m;
        vector<vector<int>> adj(n, vector<int>());
        for (int b = 1; b <= n; b++){
            int rem = m % b;
            adj[rem].push_back(b);
        }
        ll ans = n-1;
        int threshold;
        for (int a = 2; a < n; a++){
            for (int x = m % a; x < n; x+=a){
                threshold = max(a, x);
                int pos = upper_bound(adj[x].begin(), adj[x].end(), threshold) - adj[x].begin();
                ans += adj[x].size() - pos;
            }
        }
        cout << ans << nl;
    }
}
// Fix a. x = M mod a. => x = ((M mod b) mod a) Find all b such that this holds. 
// M mod b = x, x + a, x + 2a, x + floor(M-x/a)a x + a, x + 2a, x + floor(M-x/a)a
