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
        int n; ll k; cin >> n >> k;
        vector<ll> p(n);
        for (int i = 0; i < n; i++) cin >> p[i];
        sort(p.begin(), p.end());
        auto ip = unique(p.begin(), p.end());
        p.resize(distance(p.begin(), ip));
        int sz = p.size();
        vector<ll> ends(2), mids;
        ends[0] = p[0] - 1;
        ends[1] = k - p[sz-1];
        for (int i = 0; i < sz-1; i++){
            mids.push_back(p[i+1] - p[i] - 1);
        }
        ll ans = 0;
        for (auto m : mids) ans = max(ans, m);
        vector<ll> mix;
        mix.push_back(ends[0]);
        mix.push_back(ends[1]);
        for (auto m : mids) mix.push_back((m+1)/2);
        sort(mix.rbegin(), mix.rend());
        ans = max(ans, mix[0] + mix[1]);
        long double prob = 1.0 * ans / k;
        cout << fixed << setprecision(10);
        cj(tt) << prob << nl;
    }
}

