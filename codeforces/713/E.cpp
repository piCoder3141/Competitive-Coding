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
        int n, l, r, s;
        cin >> n >> l >> r >> s;
        int len = r-l+1;
        vector<int> subseg(len);
        for (int i = 0; i < len; i++) subseg[i] = i+1;
        int mn = (len * (len+1))/2;
        // n, n-1, ... , n-len+1
        // sum = len * (2n - len + 1)/2
        int mx = (len * (2*n - len + 1))/2;
        if (s < mn || s > mx){
            cout << "-1\n"; continue;
        }

        int excess = s - mn;
        int k = len-1;
        while (excess > 0){
            int mposs = n - len + 1 + k;
            if (mposs - subseg[k] > excess){
                subseg[k] += excess;
                excess = 0; break;
            }
            excess -= (mposs - subseg[k]);
            subseg[k] = mposs;
            k--;
        }
        vector<bool> used(n+1, false);
        for (int i = 0; i < len; i++) used[subseg[i]] = true;
        vector<int> ans(n);
        int nxt = 1;
        for (int i = 0; i < l-1; i++){
            while (used[nxt]) nxt++;
            ans[i] = nxt;
            used[nxt] = true;
        }
        for (int i = l-1; i < r; i++){
            ans[i] = subseg[i-l+1];
        }
        for (int i = r; i < n; i++){
            while(used[nxt]) nxt++;
            ans[i] = nxt;
            used[nxt] = true;
        }
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
}

