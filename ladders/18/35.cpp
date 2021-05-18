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
    if (n == 1){
        cout << 1; return 0;
    }
    vector<int> a(n), pref(n), suff(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    pref[0] = 1;
    for (int i = 1; i < n; i++){
        if (a[i] > a[i-1]) pref[i] = pref[i-1] + 1;
        else pref[i] = 1;
    }
    suff[n-1] = 1;
    for (int i = n-2; i >= 0; i--){
        if (a[i] < a[i+1]) suff[i] = suff[i+1] + 1;
        else suff[i] = 1;
    }
    int ans = max(suff[1] + 1, pref[n-2] + 1);
    for (int i = 1; i <= n-2; i++){
        ans = max(ans, pref[i-1] + 1);
        ans = max(ans, suff[i+1] + 1);
        if (a[i+1] - a[i-1] <= 1) continue;
        ans = max(ans, pref[i-1] + 1 + suff[i+1]);
    }
    cout << ans;
}


