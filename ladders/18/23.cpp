#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const ll MOD = 998244353;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k; cin >> n >> k;
    vector<pii> ans;
    set<pii> a;
    int freq[10001];
    memset(freq, 0, sizeof(freq));
    int mx = 0, mn = 1e4+1;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        a.insert({x, i+1});
        freq[x]++;
        mx = max(mx, x);
        mn = min(mn, x);
    }
    int i;
    for (i = 0; i < k; i++){
        if (mx - mn <= 1) break;
        pii mnp = *a.begin(), mxp = *a.rbegin();
        ans.emplace_back(mxp.second, mnp.second);
        a.erase(mxp); a.erase(mnp);
        mxp.first--; mnp.first++;
        a.insert(mxp); a.insert(mnp);
        freq[mx]--; freq[mn]--;
        freq[mx-1]++; freq[mn+1]++;
        while(freq[mx] == 0) mx--;
        while(freq[mn] == 0) mn++;
    }
    cout << mx - mn << " " << i << "\n";
    for (auto pp : ans) cout << pp.first << " " << pp.second << "\n";
}

// Maintain freq, mx, min
// for i : 1 to k -> freq[mx]--; freq[mn]--; update mx and mn

