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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++){
        // ticks[1..3] -> input
        // proc_ticks[1..3] = {{h, m, s, n} for each i in 1..3}
        // order = {1, 2, 3}: Permute order; hour hand, minute hand, second hand
        // how to set baseline? 
        ll ticks[3];
        ll order[] = {0, 1, 2};
        for (int i = 0; i < 3; i++) cin >> ticks[i];
        vector<vector<ll>> proc_ticks(3, vector<ll>(4));
        ll hticks = 36e11, mticks = 6e10, sticks = 1e9;
        ll left;
        for (int i = 0; i < 3; i++){
            left = ticks[i];
            proc_ticks[i][0] = left / hticks; left = left % hticks;
            proc_ticks[i][1] = left / mticks; left = left % mticks;
            proc_ticks[i][2] = left / sticks; left = left % sticks;
            proc_ticks[i][3] = left;
        }
        ll h, m, s, n, s_tick, m_tick;
        bool ans = false;
        do{
            int p = order[0], q = order[1], r = order[2];
            h = proc_ticks[p][0]; m = proc_ticks[p][1]; s = proc_ticks[p][2];
            n = proc_ticks[p][3];
            s_tick = 720 * s * sticks;
            m_tick = 12 * (m * mticks + s*sticks);
            if ((m_tick == ticks[q]) && (s_tick == ticks[r])){
                ans = true;
                break;
            }
        } while(next_permutation(order, order + 3));
        if (ans) cj(tt) << h << " " << m <<  " " << s << " " << n << nl;
    }
}

