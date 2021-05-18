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

int arr[] = {0, 2, 5, 3, 4, 1};

int query(int t, int i, int j, int x){
    int ans;
    if (t == 1){
        ans = max(min(x, arr[i]), min(x+1, arr[j]));
    }
    else{
        ans = min(max(x, arr[i]), max(x+1, arr[j]));
    }
    return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++){
        int n; cin >> n;
        vector<int> p(n+1, 0);
        int val = n;
        int lo = 1, hi = n-1;
        int mid, x;
        while (lo <= hi){
            mid = (lo + hi)/2;
            cout << "? 2 " << 1 << " " << 2 << " " << mid << endl;
            cin >> x;
            // x = query(2, 1, 2, mid);
            // cout << x << nl;
            if (mid == x){
                val = min(mid, val);
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        p[1] = val;
        if (val > n/2){
            int opos;
            for (int j = 2; j <= n; j++){
                cout << "? 2 " << j << " " << 1 << " " << 1 << endl;
                cin >> x;
                // x = query(2, j, 1, 1);
                // cout << x << nl;
                if (x < val) p[j] = x;
                if (p[j] == 1) opos = j;
            }
            for (int j = 2; j <= n; j++){
                if (p[j] > 0) continue;
                cout << "? 1 " << opos << " " << j << " " << n-1 << endl;
                cin >> x;
                // x = query(1, opos, j, n-1);
                // cout << x << nl;
                p[j] = x;
            }
            cout << "! ";
            for (int j = 1; j <= n; j++) cout << p[j] << " ";
            cout << endl;
        }
        else{
            int npos;
            for (int j = 2; j <= n; j++){
                cout << "? 1 " << 1 << " " << j << " " << n-1 << endl;
                cin >> x;
                // x = query(1, 1, j, n-1);
                // cout << x << nl;
                if (x > val) p[j] = x;
                if (p[j] == n) npos = j;
            }
            for (int j = 2; j <= n; j++){
                if (p[j] > 0) continue;
                cout << "? 2 " << j << " " << npos << " " << 1 << endl;
                cin >> x;
                // x = query(2, j, npos, 1);
                // cout << x << nl;
                p[j] = x;
            }
            cout << "! ";
            for (int j = 1; j <= n; j++) cout << p[j] << " ";
            cout << endl;
        }
    }
}

