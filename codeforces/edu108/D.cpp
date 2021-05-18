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
    vector<ll> a(n), b(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    // b1 -> a1 and an. bn -> a1 and an -> a1b1 + anbn OR a1 bn + an b1
    // (a1 - an) (bn - b1) = Change (only if a1 > an && bn > b1 and vice versa)
    vector<vector<ll>> change(n, vector<ll>(n, 0));
    for (int i = 0; i < n-1; i++){
        change[i][i+1] = b[i]*a[i+1] + b[i+1]*a[i] - b[i]*a[i] - b[i+1]*a[i+1];
    }
    for (int len = 3; len <= n; len++){
        for (int i = 0; i + len-1 < n; i++){
            int j = i + len - 1;
            change[i][j] = b[i]*a[j] + b[j]*a[i] - b[i]*a[i] - b[j]*a[j];
            change[i][j] += change[i+1][j-1];
        }
    }
    for (int i = 0; i < n; i++) ans += a[i]*b[i];
    ll mx = 0;
    for (int len = 2; len <= n; len++){
        for (int i = 0; i + len - 1 < n; i++){
            int j = i + len - 1;
            mx = max(mx, change[i][j]);
        }
    }
    cout << ans + mx << endl;
}


