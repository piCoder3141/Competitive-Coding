#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const ll MOD = 998244353;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n; 
    vector<int> p(n+1);
    for (int i = 1; i <= n; i++) cin >> p[i];
    vector<vector<int>> grid(n+1, vector<int>(n+1, -1));
    // pos = n to 1. curr = (pos, pos) if possible curr = (pos + 1, pos) else pos, pos-1)
    int val, x, y;
    for (int pos = n; pos >= 1; pos--){
        x = pos, y = pos;
        val = p[pos];
        for (int i = 0; i < val; i++){
            grid[x][y] = val;
            if (x < n && grid[x+1][y] == -1){
                x++;
            }
            else y--;
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}


