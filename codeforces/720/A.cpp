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
        ll a, b; cin >> a >> b;
        // am + an = ab p
        // p = 3; m = 2b-1, 2b+1
        if (b == 1){
            cout << "NO\n"; continue;
        }
        ll x = a *(2*b-1), y = a * (2*b+1), z = 4*a*b; 
        cout << "YES\n";
        cout << x << " " << y << " " << z << nl;
    }
}

