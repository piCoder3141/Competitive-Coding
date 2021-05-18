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
    vector<int> a(n), b(n), c(1002); 
    for (int i = 0; i < n; i++){
        int x; cin >> x; c[x]++;
    }
    for (int i = 0;i < n; i++){
        int x; cin >> x; c[x+1]--;
    }
    for (int i = 1; i <= 1000; i++) c[i] += c[i-1];
    int ans = 0;
    for (int i = 1; i <= 1000; i++){
        if (c[i] == n) ans++;
    }
    cout << ans;
}


