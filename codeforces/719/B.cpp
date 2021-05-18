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
        string num; cin >> num;
        int d = num.length();
        int ans = 9 * (d-1);
        for (int k = 1; k < 10; k++){
            string ordinary = "";
            for (int i = 0; i < d; i++) ordinary += '0' + k;
            if (ordinary <= num) ans++;
        }
        cout << ans << "\n";
    }
}
// 1 - 9, 11, 22, 99, 111, 
// 9 one-digit numbers, 9 two-digit numbers and so on. 
// Suppose `n` is a d-digit number - ans = 9*(d-1) + number of ordinary d-digit numbers < n.
//
