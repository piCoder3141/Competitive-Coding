#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const ll MOD = 998244353;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    set<int> knights;
    vector<int> ans(n+1), remove;
    for (int i = 0; i < n; i++) knights.insert(i+1);
    for (int i = 0; i < m; i++){
        remove.clear();
        int l, r, x; cin >> l >> r >> x;
        auto it = knights.lower_bound(l);
        for (; *it <= r && it != knights.end(); it++){
            if (*it == x) continue;
            ans[*it] = x;
            remove.push_back(*it);
        }
        for (auto y : remove) knights.erase(y);
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}
