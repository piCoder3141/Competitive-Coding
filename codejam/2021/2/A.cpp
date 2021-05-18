#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define cj(t) cout << "Case #" << t << ": "
#define nl "\n"

const int inf = 1e9;
const ll INF = 1e18;
const ll mod = 1e9 + 7;

ll powmod(ll x, ll y, ll md = mod){
    ll ret = 1;
    while (y > 0){
        if (y&1) ret = (ret*x) % md;
        x = (x*x) % md; y /= 2;
    }
    return ret;
}

int query(int type, int i, int j){
    int x;
    if (type == 0){
        cout << "M " << i+1 << " " << j+1 << endl;
        cin >> x; return (x-1);
    }
    else if(type == 1){
        cout << "S " << i+1 << " " << j+1 << endl;
        cin >> x;
    }
    else{
        cout << "D" << endl;
        cin >> x; return x;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n; cin >> t >> n;
    for (int tt = 1; tt <= t; tt++){
        for (int i = 0; i < n-1; i++){
            int x = query(0, i, n-1);
            if (x > i){
                x = query(1, i, x);
            }
        }
        int x = query(2, 0, 0);
        if (x == -1) return 0;
    }
}

