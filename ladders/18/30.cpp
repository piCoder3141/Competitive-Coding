#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const ll MOD = 998244353;
int a[18][1 << 17];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    for (int i = 0; i < (1 << n); i++){
        cin >> a[0][i];
    }
    for(int l = 1; l <= n; l++){
        int x = 1 << (n-l);
        for (int i = 0; i < x; i++){
            if (l & 1){
                a[l][i] = a[l-1][i << 1] | a[l-1][(i << 1) | 1];
            }
            else{
                a[l][i] = a[l-1][i << 1] ^ a[l-1][(i << 1) | 1];
            }
        }
    }
    for (int q = 0; q < m; q++){
        int p, val; cin >> p >> val; p--;
        a[0][p] = val;
        for (int l = 1; l <= n; l++){
            if (l&1){
                a[l][p >> 1] = a[l-1][p] | a[l-1][p^1];
            }
            else{
                a[l][p >> 1] = a[l-1][p] ^ a[l-1][p^1];
            }
            p >>= 1;
        }
        cout << a[n][0] << "\n";
    }
}


