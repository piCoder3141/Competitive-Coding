#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++){
        int n; cin >> n;
        adj.assign(n, vector<int>());
        a.assign(n, 0);

        for (int i = 1; i < n; i++){
            int x; cin >> x;
            adj[x-1].push_back(i);
        }

        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
    }
}

