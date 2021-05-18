#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const ll MOD = 1e9+7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q; cin >> n; 
    ll sum = 0, x;
    for (int i = 0; i < n; i++){
        cin >> x; sum += x;
    }
    cin >> q;
    for (int i = 0; i < q; i++){
        cin >> x;
        sum *= 2;
        sum %= MOD;
        sum = (sum + MOD) % MOD;
        cout << sum << "\n";
    }
}


