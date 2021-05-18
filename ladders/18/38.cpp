#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const ll MOD = 998244353;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k, d; cin >> n >> k >> d;
    ll prod = 1;
    bool ok = false;
    for (int i = 1; i <= d; i++){
        prod *= k;
        if (prod >= n){
            ok = true; break;
        }
    }
    if (!ok){
        cout << -1; return 0;
    }
    vector<vector<int>> ans(n, vector<int>(d, 0));
    for (int i = 1; i < n; i++){
        ans[i] = ans[i-1];
        for (int j = d-1; j >= 0; j--){
            ans[i][j] = (ans[i][j] + 1) % k;
            if (ans[i][j]) break;
        }
    }
    for (int j = 0; j < d; j++){
        for (int i = 0; i < n; i++){
            cout << ans[i][j] + 1 << " ";
        }
        cout << "\n";
    }
}


