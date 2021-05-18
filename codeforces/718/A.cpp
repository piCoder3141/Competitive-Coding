#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++){
        ll n; cin >> n;
        if (n % 2050 != 0){
            cout << -1 << "\n"; continue;
        }
        n /= 2050;
        int ans = 0;
        while (n > 0){
            ans += n % 10; n /= 10;
        }
        cout << ans << "\n"; 
    }
}

