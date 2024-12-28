#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++){
        int n; cin >> n;
        vector<vector<int>> mat(n, vector<int>(n));
        for (int i = 0; i < n; i++){
            string s; cin >> s;
            for (int j = 0; j < n; j++) mat[i][j] = s[j]-'0';;
        }

        int ans = 0;
        vector<int> pos(n+1), neg(n+1), change(n+1);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (j > 0) pos[j] = 0;
                pos[j] ^= pos[j+1];
            }
            for (int j = n; j >= 0; j--){
                if (j < n) neg[j] = 0;
                if (j > 0) neg[j] ^= neg[j-1];
            }
            change[0] = pos[0];
            for (int j = 1; j < n; j++) change[j] = pos[j] ^ neg[j] ^ change[j-1];
            for (int j = 0; j < n; j++){
                if (mat[i][j] ^ change[j]){
                    ans++;
                    pos[j] ^= 1; neg[j+1] ^= 1;
                }
            }
        }

        cout << ans << "\n";
    }
}


