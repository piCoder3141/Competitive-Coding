#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const ll MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    set<ll> ht; 
    for (int i = 0; i < n; i++){
        ll x; cin >> x;
        ht.insert(x);
    }
    ll ans = 1;
    ll prev = 0;
    for (auto it = ht.begin(); it != ht.end(); it++){
        ans = (ans * (*it - prev + 1)) % MOD;
        prev = *it;
    }
    cout << ans;
}


