#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const ll MOD = 998244353;
const int MX = 1e5 + 4;

ll cnt[MX], dp[MX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        int x; cin >> x; cnt[x]++;
    }
    dp[1] = cnt[1];
    for (ll i = 1; i < MX; i++){
        dp[i] = max(dp[i-1], dp[i-2] + cnt[i]*i);
    }
    cout << dp[MX-1];
}

// ll score[x] <- score on deleting all x's
// set<pair<ll, ll>> heap; heap.insert({score[x], x})
// while (!heap.empty()) ans += top.first; adj1 = {score[top-1], top-1}, adj2
// heap.erase(adj1) heap.erase(adj2)
