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
        vector<int> p(n), pinv(n);
        for (int i = 0; i < n; i++){
            int x; cin >> x; x--;
            p[i] = x; pinv[x] = i;
        }

        bool poss = true;
        for (int i = 0; i < n; i++){
            if (abs(i - pinv[i]) > 1) {poss = false; break;}
        }

        cout << (poss ? "YES": "NO") << "\n";
    }
}


