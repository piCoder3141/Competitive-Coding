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
    vector<int> a(n);
    vector<long long> cnt(200, 0);
    for (int i = 0; i < n; i++){
        cin >> a[i]; a[i] %= 200;
        cnt[a[i]]++;
    }
    long long ans = 0;
    for (int k = 0; k < 200; k++){
        ans += (1ll* cnt[k] * (cnt[k]-1)) / 2;
    }
    cout << ans;
}

// if (a-b) is divisible by 200. => a = b (mod 200). 
// for each a[i] I will compute its value modulo 200. 
// suppose there are 5 numbers. with a[i] % 200 = 1. 5*(5-1)/2 pairs.
