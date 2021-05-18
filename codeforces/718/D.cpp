#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const ll INF = 1e17;
const ll MOD = 998244353;
const int N = 501;

int n, m;
ll dp[N][N][21], wt[N][N][4];

int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
bool valid(int x, int y){
    return (x >= 0 && x < n && y >= 0 && y < m);
} 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(wt, -1, sizeof(wt));
    cin >> n >> m;
    int K; cin >> K;
    if (K & 1){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cout << "-1 ";
            }
            cout << "\n";
        }
        return 0;
    }
    K /= 2;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m-1; j++){
            ll x; cin >> x;
            wt[i][j][0] = x;
            wt[i][j+1][1] = x;
        }
    }
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < m; j++){
            ll x; cin >> x;
            wt[i][j][2] = x;
            wt[i+1][j][3] = x;
        }
    }
    memset(dp, 0, sizeof(dp));
    int x, y;
    for (int k = 1; k <= K; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                dp[i][j][k] = INF;
                for (int l = 0; l < 4; l++){
                    x = i + dx[l]; y = j + dy[l];
                    if (!valid(x,y)) continue;
                    dp[i][j][k] = min(dp[i][j][k], wt[i][j][l] + dp[x][y][k-1]);
                }
            }
        }
    }
    if(true){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cout << dp[i][j][K]*2 << " ";
            }
            cout << "\n";
        }
    }
}

// n, m global. valid(x,y) 
// weight(x, y) -> right, left, down, up<
