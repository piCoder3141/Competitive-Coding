#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const ll MOD = 998244353;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<ll> a(n+1); 
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<ll> prefix(n+1), suffix(n+2);
    for (int i = 1; i <= n; i++) prefix[i] = a[i] + prefix[i-1];
    for (int i = n; i > 0; i--) suffix[i] = a[i] + suffix[i+1];
    vector<ll> ealt(n+1), oalt(n+1);
    for (int i = 1; i <= n; i++){
        if(i&1){
            oalt[i] = oalt[i-1] + a[i];
            ealt[i] = ealt[i-1] - a[i];
        }
        else{
            oalt[i] = oalt[i-1] - a[i];
            ealt[i] = ealt[i-1] + a[i];
        }
    }
    ll ans = 1;
    ll lo, hi, x;
    // for par in {0, 1} lo = 1, hi = n;
    // if (lo % 2 != par) lo++
    // if (hi % 2 != par) hi--
    // while (lo <= hi){
    // mid = (hi + lo)/2
    // }
    for (int c = 1; c < n; c++){
        for (int par = 0; par < 2; par++){
            ll cnt = -1;
            lo = 0; hi = 1ll*c;
            if (lo % 2 != par) lo++;
            if (hi % 2 != par) hi--;
            while (lo <= hi){
                x = (hi + lo)/2;
                if (x % 2 != par) x--;
            }
        }
    }
}


