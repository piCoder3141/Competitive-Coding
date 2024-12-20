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
        long long n, b, c; cin >> n >> b >> c;
        // b = 0 => n operations if (c >= n) else if (c == n-1) n-1 operations else not possible
        // b > 0 => bi + c >= n => i >= ceil((n - c) / b)

        long long ans = 0;
        if (b == 0){
            if (c >= n) ans = n;
            else if (c >= n-2) ans = n-1;
            else ans = -1;
        }
        else{
            long long i = max(0ll, (n - c + b-1) / b);
            ans = n - i;
        }

        cout << ans << "\n";
    }
}


