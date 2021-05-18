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
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        // a[i] > a[i-1] a[i] = min() a[i-1] = a[i]-1
        int mn = a[0], id = 0;
        for (int i = 0; i < n; i++){
            if (a[i] < mn){
                mn = a[i]; id = i;
            }
        }
        vector<pair<pii, pii>> ans;
        for (int i = 0; i < n; i++){
            if (i == id) continue;
            if ((i+id)%2 != 0){
                ans.push_back({{i+1, id+1}, {mn+1, mn}});
                a[i] = mn+1;
            } 
            if ((i+id)%2 == 0){
                ans.push_back({{i+1, id+1}, {mn, mn}});
                a[i] = mn;
            }
        }
        cout << ans.size() <<nl;
        for (auto x : ans){
            cout << x.first.first << " " << x.first.second << " ";
            cout << x.second.first << " " << x.second.second<< nl;
        }
    }
}

