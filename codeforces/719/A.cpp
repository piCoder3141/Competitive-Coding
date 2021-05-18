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
        vector<bool> used(26, false);
        string s; cin >> s;
        bool ans = true;
        used[s[0] - 'A'] = true;
        for (int i = 1; i < n; i++){
            if (used[s[i] - 'A'] && s[i] != s[i-1]){
                ans = false; break;
            }
            used[s[i] - 'A'] = true;
        }
        cout << (ans ? "YES":"NO") << "\n";
    }
}

