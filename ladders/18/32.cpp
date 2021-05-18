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
    vector<ll> h(n), p(m); 
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < m; i++) cin >> p[i];

    ll ans = 0;
    // Fix t. vis(m, false); nxt
    // for (int i = 0; i < n; i++) if (h[i] + t < p[nxt]) continue;
    // if (h[i] - t > p[nxt]) ok = false; break;
    // if (h[i] <= p[nxt]) right = h[i] + t; while (p[nxt] <= right) vis[nxt] = true; nxt++;
    // else diff = h[i] - p[nxt]; right = max((t - diff)/ 2 , t - 2diff) + h[i]

    ll lo = 0, hi = 1e11, right;
    ans = hi;
    vector<bool> vis;
    while (lo <= hi){
        ll t = (lo + hi) / 2;
        vis.assign(m, false);
        int nxt = 0;
        bool ok = true;
        for (int i = 0; i < n && nxt < m; i++){
            if (h[i] + t < p[nxt]) continue;
            if (h[i] - t > p[nxt]){
                ok = false; break;
            }
            if (h[i] <= p[nxt]){
                right = h[i] + t;
            }
            else{
                right = h[i] + max((t - h[i] + p[nxt])/2, t - 2*(h[i] - p[nxt]));
            }
            while(nxt < m && p[nxt] <= right){vis[nxt] = true; nxt++;}
        }
        if(!vis[m-1]) ok = false;
        if (ok){
            ans = min(ans, t);
            hi = t-1;
        }
        else{
            lo = t+1;
        }
    }
    cout << ans;
}


