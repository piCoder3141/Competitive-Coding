#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const ll MOD = 998244353;
const int MAXBIT = 30;
vector<int> tree;
int n;
void build(){
    for (int i = n-1; i >= 0; i--)
        tree[i] = tree[i << 1] & tree[(i << 1) | 1];
}

int query(int l, int r){
    int res = (1 << MAXBIT) - 1;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1){
        if (l&1) res &= tree[l++];
        if (r&1) res &= tree[--r];
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m; cin >> n >> m;
    vector<int> l(m), r(m), q(m), a(n), sum(n);
    for (int i = 0; i < m; i++){
        cin >> l[i] >> r[i] >> q[i]; l[i]--;
    }
    for (int i = 0; i < MAXBIT; i++){
        sum.assign(n+1, 0);
        for (int j = 0; j < m; j++){
            if ((q[j] >> i) & 1){
                sum[l[j]]++;
                sum[r[j]]--;
            }
        }
        for (int j = 1; j < n; j++) sum[j] += sum[j-1];
        for (int j = 0; j < n; j++){
            if (sum[j] > 0) a[j] |= (1 << i);
        }
    }
    tree.assign(2*n, 0);
    for (int i = n; i < 2*n; i++) tree[i] = a[i-n];
    build();
    bool ok = true;
    for (int i = 0; i < m; i++){
        if (query(l[i], r[i]) != q[i]){
            ok = false; break;
        }
    }
    if (ok){
        cout << "YES\n";
        for (auto x : a) cout << x << " ";
    }
    else{
        cout << "NO";
    }
}


