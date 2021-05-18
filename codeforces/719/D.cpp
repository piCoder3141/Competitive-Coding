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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
            b[i] = a[i] - (i+1);
        }
        // -(N-1) <= b[i] <= N-1 (2N-1 values)
        // vector cnt of size 2N - 1. cnt[i] = number positions with value i-N;
        long long ans = 0;
        vector<long long> cnt(2*n);
        for (int i = 0; i < n; i++){
            cnt[b[i] + n]++;
        }
        for (int i = 0; i < 2*n; i++){
            ans += (1ll * cnt[i] * (cnt[i]-1))/2;
        }
        cout << ans << "\n";
    }
}
// array A - 1 <= a[i] <= n;
// (i, j) s.t. i < j && aj - ai = j-i;
// Brute force - For every i, iterate from j+1 to n and increment answer when found correct pair.
// Let's find all the pairs with the first index i.
// All j such that aj = a[i] + j-i;
// a[j] - j = a[i] - i
// b[k] = a[k] - k
// 3 5 1 4 6 6
// 2 3 -2 0 1 0
