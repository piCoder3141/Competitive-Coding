#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const ll MOD = 1e9 + 7;

ll powmod(ll x, ll y){
    ll ret = 1;
    while(y > 0){
        if (y&1) ret = (ret * x) % MOD;
        x = (x*x) % MOD; y /= 2;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++){
        ll n, k; cin >> n >> k;
        ll ans = powmod(n, k);
        cout << ans << "\n";

    }
}

