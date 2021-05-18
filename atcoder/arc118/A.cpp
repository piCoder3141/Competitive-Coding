#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const ll MOD = 998244353;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll r, n; cin >> r >> n;
    ll ceiling = (n*100)/r;
    if (n*100 % r != 0) ceiling++;
    ll ans = ceiling + n - 1;
    cout << ans;
}

// Smallest value first. t x + tx/100
// While tx < 100. We get the same value
// Find first first x such that tx >= 100. This is the first value. We want to find the Nth one
// next value -> tx >= 200; x + 1
// x >= N*100/t
