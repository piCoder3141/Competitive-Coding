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
    if (n == 1){
        if (n == abs(m)){
            cout << -1; return 0;
        }
        cout << "1 3"; return 0;
    }
    if (m < 0 || m >= n-1){
        cout << -1; return 0;
    }
    vector<pii> segs(n);
    segs[0] = {1, 3*m + 5};
    for (int i = 1; i < n; i++){
        segs[i] = {3*i, 3*i+1};
    }
    for (auto p : segs){
        cout << p.first << " " << p.second << "\n";
    }
}

// if M < 0 || M >= N-1 -> ans = -1
// else create N-1 disjoint segments with distance 2 : (3, 4), (6, 7), (9, 10) .. 
// after this. L_N = 1. R_N = 3(M+1) + 2
