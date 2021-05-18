#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const ll MOD = 998244353;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q; cin >> n;
    string s; cin >> s;
    cin >> q;
    int len = 2*n, swapped = 0;
    string sub[2];
    sub[0] = s.substr(0, n);
    sub[1] = s.substr(n, n);
    while(q--){
        int t, a, b; cin >> t >> a >> b;
        a--; b--;
        if (t == 2){
            swapped ^= 1;
        }
        else{
            char ca, cb;
            if (swapped){
                a = (a + n) % len;
                b = (b + n) % len;
            }
            if (a < n) ca = sub[0][a];
            else ca = sub[1][a-n];
            if (b < n) cb = sub[0][b];
            else cb = sub[1][b-n];

            if (a < n) sub[0][a] = cb;
            else sub[1][a-n] = cb;
            if (b < n) sub[0][b] = ca;
            else sub[1][b-n] = ca;
        }
    }
    cout << sub[swapped] << sub[swapped^1];
}


