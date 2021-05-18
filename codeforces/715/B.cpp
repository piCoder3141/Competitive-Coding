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
        int n; cin >>n;
        string s; cin >>s;
        bool ok = true;
        vector<int> ts, ms;
        for (int i = 0; i < n; i++){
            if (s[i] == 'T') ts.push_back(i);
            else ms.push_back(i);
        }
        int mlen = ms.size(), tlen = ts.size();
        if (tlen != mlen*2){
            cout << "NO\n"; continue;
        }
        for (int i = 0; i < mlen; i++){
            int m = ms[i], l = ts[i], r = ts[tlen - mlen + i];
            if (l > m || r < m){
                ok = false; break;
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}

