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
        if (n == 2){
            cout << -1 << "\n"; continue;
        }
        if (n == 1){
            cout << 1 << "\n"; continue;
        }
        vector<vector<int>> ans(n, vector<int>(n));
        for (int i = 0; i < n; i++) ans[i][i] = i+1;
        int x, y, curr = n+1;
        for (int diag = 1; diag <= n; diag++){
            // Upper diagonal
            x = 0, y = diag;
            for (int i = 0; i < n-diag; i++){
                ans[x][y] = curr++;
                x++; y++;
            }
            // Lower diagonal
            x = diag; y = 0;
            for (int i = 0; i < n-diag; i++){
                ans[x][y] = curr++;
                x++; y++;
            }
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
}
// I fill 1..n in the first row, n+1 ... 2n in the second row and so on.
// 1..n in the diagonal.
// 148
// 625
// 973
// (r, c) would be the top of my top diagonal. (0, 0), (0, 1)
