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
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int l = 0, r = n-1;
        for (int i = 0; i < k; i++){
            while (a[l] == 0) l++;
            if (l >= r) break;
            a[l]--; a[r]++;
        }
        for (auto x : a) cout << x << " "; cout << "\n";
    }
}

