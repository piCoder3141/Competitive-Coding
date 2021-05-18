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
const int MX = 5e6;
int phi[MX], a[MX];

void precompute(){
    for (int i = 0; i < MX; i++) phi[i] = i;
    for (int p = 2; p < MX; p++){
        if (phi[p] == p){
            phi[p] = p-1;
            for (int q = 2*p; q < MX; q += p){
                phi[q] = (phi[q]/p) * (p-1);
            }
        }
    }
    for (int p = 2; p < MX; p++){
        a[p] += p-1;
        for (int q = p*2; q < MX; q += p){
            a[q] += (p-1) * phi[q/p];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++){
        int k; cin >> k;
        int M = 4*k;
        int ans = M + a[M+1]/2;
        cout << ans << nl;
    }
}

