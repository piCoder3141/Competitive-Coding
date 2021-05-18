#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const ll MOD = 998244353;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n; m = n;
    if (n == 4){
        cout << 1 << "\n" << 1; return 0;
    }
    vector<int> factors;
    for (int x = 2; x*x <= n; x++){
        if (n % x == 0){
            factors.push_back(x);
        }
        while (n % x == 0){
            n /= x;
        }
    }
    if (n > 1){
        factors.push_back(n); n = 1;
    }
    n = m;
    int sz = factors.size();
    if (sz == 1){
        if (factors[0] == 2){
            cout << n/2 << "\n";
            for (int i = 1; i <= n; i+=2){
                cout << i << " ";
            }
            return 0;
        }
        int ans = n - n/factors[0] - 1;
        cout << ans << "\n";
        for (int i = 1; i < n-1; i++){
            if (i % factors[0] == 0) continue;
            cout << i << " ";
        }
        return 0;
    }
    else if (sz == 2){
        if (factors[0] == 2 && n % 4 != 0){
            int x = n/2;
            int ans = x - x / factors[1] - 1;
            cout << ans << "\n";
            for (int i = 1; i < n-1; i++){
                if (__gcd(i, n) == 1) cout << i << " ";
            }
            return 0;
        }
    }
    vector<int> coprime;
    for (int i = 1; i < n; i++){
        if (__gcd(i, n) == 1) coprime.push_back(i);
    }
    sz = coprime.size();
    cout << sz << "\n";
    for (auto y : coprime) cout << y << " ";
}


