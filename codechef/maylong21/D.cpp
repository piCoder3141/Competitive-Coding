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
        int grid[3][3];
        int cnt[2] = {0};
        string s;
        for (int i = 0; i < 3; i++){
            cin >> s;
            for (int j = 0; j < 3; j++){
                if (s[j] == 'X') grid[i][j] = 0;
                else if (s[j] == 'O') grid[i][j] = 1;
                else grid[i][j] = -1;
                if (grid[i][j] != -1) cnt[grid[i][j]]++;
            }
        }
        if (!(cnt[0] == cnt[1] || cnt[0] == cnt[1]+1)){
            cout << 3 << nl; continue;
        }
        vector<vector<pii>> wins[2];
        vector<pii> tmp;
        int player;
        for (int r = 0; r < 3; r++){
            player = grid[r][0];
            if (player == -1) continue;
            if (grid[r][1] == player && grid[r][2] == player){
                tmp.clear();
                for (int j = 0; j < 3; j++) tmp.emplace_back(r, j);
                wins[player].push_back(tmp);
            }
        }
        for (int c = 0; c < 3; c++){
            player = grid[0][c];
            if (player == -1) continue;
            if (grid[1][c] == player && grid[2][c] == player){
                tmp.clear();
                for (int j = 0; j < 3; j++) tmp.emplace_back(j, c);
                wins[player].push_back(tmp);
            }
        }
        for (int k : {-1, 1}){
            player = grid[1][1];
            if (player == -1) continue;
            if (grid[2][1+k] == player && grid[0][1-k] == player){
                tmp.clear();
                tmp.emplace_back(1, 1); tmp.emplace_back(2, 1+k);
                tmp.emplace_back(0, 1-k);
                wins[player].push_back(tmp);
            }
        }
        if (wins[0].size() > 0 && wins[1].size() > 0){
            cout << 3 << nl; continue;
        }
        else if (wins[0].size() > 0){
            if (cnt[0] == cnt[1]+1) cout  << 1 << nl;
            else cout << 3 << nl;
        }
        else if (wins[1].size() > 0){
            if (cnt[0] == cnt[1]) cout << 1 << nl;
            else cout << 3 << nl;
        }
        else if (cnt[0] + cnt[1] == 9){
            cout << 1 << nl; continue;
        }
        else{
            cout << 2 << nl;
        }
    }
}

