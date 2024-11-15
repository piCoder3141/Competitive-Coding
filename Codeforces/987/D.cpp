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
        int cmax = -1, prev_max = -1, tmp = -1;
        vector<int> a(n), last_max(n), nsmall(n);
        map<int, vector<int>> mp;

        for (int i = 0; i < n; i++){
            cin >> a[i];
            cmax = max(a[i], cmax);
            last_max[i] = cmax;
            mp[a[i]].push_back(i);
        }

        for (auto it = mp.begin(); it != mp.end(); it++){
            int x = it->first;
            vector<int> pos = it->second;

            for (int p: pos){
                nsmall[p] = max(p, prev_max);
                tmp = max(tmp, p);
            }

            prev_max = tmp;
        }

        vector<int> ans(n);
        int st = n-1, prev_p = INT_MAX;
        for (auto it = mp.rbegin(); it != mp.rend(); it++){
            int x = it->first, p = (it->second)[0];
            if (p > prev_p) continue;
            int np = nsmall[p];
            
            if (np > prev_p){
                for (int i = st; i >= p; i--) ans[i] = ans[np];
            }
            else{
                for (int i = st; i >= p; i--) ans[i] = x;
            }

            prev_p = p;
            st = p-1;
        }

        for (int d: ans) cout << d << " ";
        cout << "\n";

    }
}


