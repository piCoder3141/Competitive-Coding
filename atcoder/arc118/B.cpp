#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const ll MOD = 998244353;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k; cin >> k;
    ll n, m; cin >> n >> m;
    vector<ll> a(k), b(k);
    for (int i = 0; i < k; i++) cin >> a[i];
    ll b_low, b_hi;
    ll diff;
    vector<pair<ll, pair<ll, int>>> to_sort;
    for (int i = 0; i < k; i++){
        b_low = (a[i]*m)/n; b_hi = (a[i]*m + n-1)/n;
        if (b_low == b_hi) to_sort.push_back({0, {b_low, i}});
        else{
            diff = abs(a[i]*m - b_low*n);
            to_sort.push_back({diff, {b_low, i}});
            diff = abs(a[i]*m - b_hi*n);
            to_sort.push_back({diff, {b_hi, i}});
        }
    }
    sort(to_sort.rbegin(), to_sort.rend());
    vector<bool> used(k, true);
    int sz = to_sort.size();
    ll val, sum=0; int idx;
    ll ans = -1;
    for (int j = 0; j < sz; j++){
        diff = to_sort[j].first;
        val = to_sort[j].second.first; idx = to_sort[j].second.second;
        if (used[idx] && diff > 0){
            used[idx] = false; continue;
        } 
        b[idx] = val; sum += val;
        if (ans == -1) ans = diff;
    }
    if (sum == m){
        for (auto x : b) cout << x << " "; 
        return 0;
    }
    ll deficit = m - sum;
    ll change;
    vector<pll> new_ans(k);
    if (deficit > 0){
        change = 1;
        for (int i = 0; i < k; i++){
            new_ans[i] = make_pair(ans, i);
            ll new_b = b[i] + 1;
            ll new_diff = abs(a[i]*m - new_b*n);
            new_ans[i].first = max(ans, new_diff);
        }
    }
    else{
        change= -1;
        for (int i = 0; i < k; i++){
            new_ans[i] = make_pair(ans, i);
            ll new_b = b[i] - 1;
            ll new_diff = abs(a[i]*m - new_b*n);
            new_ans[i].first = max(ans, new_diff);
        }
    }
    sort(new_ans.begin(), new_ans.end());
    for (int j = 0; j < abs(deficit); j++){
        b[new_ans[j].second] += change;
    }
    for (auto x : b) cout << x << " ";
}

// sort fractions with indices and increase or decrease. reverse order. 

