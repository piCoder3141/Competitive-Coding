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
        int n, m; cin >> n >> m;
        vector<vector<int>> b(n, vector<int>(m)), ass(n, vector<int>(m, 0));
        set<pair<int, pii>> lens;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> b[i][j];
                lens.insert({b[i][j], {i, j}});
            }
        }
        auto it = lens.begin();
        for (int i = 0; i < m; i++){
            pii p = (*it).second;
            ass[p.first][p.second] = i+1; it++;
        }
        vector<int> paths[m+1];
        bool found, skip;
        for (int pl = 1; pl <= m; pl++){
            found = false;
            for (int i = 0; i < n; i++){
                skip = false;
                if (!found){
                    for (int j = 0; j < m; j++){
                        if (ass[i][j] == pl){
                            found = true;
                            paths[pl].push_back(b[i][j]);
                            skip = true; break;
                        }
                    }
                }
                if (skip) continue;
                for (int j = 0; j < m; j++){
                    if (ass[i][j] == 0){
                        ass[i][j] = pl;
                        paths[pl].push_back(b[i][j]);
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++){
            for (int pl = 1; pl <= m; pl++){
                cout << paths[pl][i] << " ";
            }
            cout << "\n";
        }
    }
}

