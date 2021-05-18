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
    vector<long double> p(n);
    for (int i = 0 ; i < n; i++) cin >> p[i];
    sort(p.rbegin(), p.rend());
    cout << fixed << setprecision(13);
    if (p[0] >= 0.5){
        cout << p[0]; return 0;
    }
    long double ans = p[0], neg_prod = 1 - p[0], curr = p[0];
    for (int i = 1; i < n; i++){
        curr = (1-p[i])*curr + neg_prod * p[i];
        ans = max(ans, curr);
        neg_prod *= (1 - p[i]);
    }
    cout << ans;
}

// p1 p2 -> Probability of not getting upset = p1(1-p2) + p2(1-p1) = p1 + p2 - 2p1p2
// p1 p2 p3 -> p1(1-p2)(1-p3) + p2(1-p1)(1-p3) + p3(1-p1)(1 - p2)
// p1 + p2 + p3 + 3 p1p2p3
