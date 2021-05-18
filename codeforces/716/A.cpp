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
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        bool ok = false;
        for (int i = 0; i < n; i++){
            bool curr = true;
            for (int j = 1; j*j <= a[i]; j++){
                if (j*j == a[i]){
                    curr = false;
                }
            }
            ok = ok | curr;
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}

