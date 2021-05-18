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
        int n; ll W, wr; cin >> n >> W >> wr;
        set<ll> wts;
        ll cnt[100001];
        memset(cnt, 0ll, sizeof(cnt));
        for (int i = 0; i < n; i++){
            ll x; cin >> x;
            cnt[x]++; wts.insert(x);
        }
        bool ans = false;
        for (auto w : wts){
            ll c = cnt[w];
            c -= cnt[w]%2;
            wr += w*c;
        }
        if (wr >= W) ans = true;
        cout << (ans ? "YES" : "NO") << nl;
    }
}

