#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const ll MOD = 1e9 + 7;
const int N = 101;

ll paths[N][2];
int n, k, d;

ll f(int n, int sgn){
    if (n < 0) return 0ll;
    if (paths[n][sgn] != -1) return paths[n][sgn];

    ll ans = 0;
    if (sgn){
        for (int i = d; i <= k; i++){
            ans = (ans + f(n-i, 0)) % MOD;
        }
        for (int i = 1; i <= k; i++){
            ans = (ans + f(n-i, 1)) % MOD;
        }
    }
    else{
        for (int i = 1; i <= d-1; i++){
            ans = (ans + f(n-i, 0)) % MOD;
        }
    }
    return paths[n][sgn] = ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k >> d;
    memset(paths, -1, sizeof(paths));
    paths[0][0] = 1;
    cout << f(n, 1);
}

// f(n, v, d) -> root is vertex v. Number of paths with sum n. d = 0 {does not contain d} 
// f(n, v, 0) -> f(n-1, v, 0) + ... + f(n-k, v, 0)
// f(n, v, 1) -> f(n-d, v, 0) + f(n-1, v, 1) + ... + f(n-k, v, 1)
