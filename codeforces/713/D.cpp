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
        vector<ll> b(n+2);
        for (int i = 0; i < n+2; i++){
            cin >> b[i];
        }
        sort(b.begin(), b.end());
        ll sum = 0;
        for (int i = 0; i < n; i++){
            sum += b[i];
        }
        if (sum == b[n]){
            for (int i = 0; i < n;i++){
                cout << b[i] << " ";
            }
            cout << "\n";
            continue;
        }
        sum += b[n];
        bool flag = true;

        for (int i = 0; i <= n; i++){
            if (sum - b[i] == b[n+1]){
                for (int j = 0; j <= n; j++){
                    if (j == i) continue;
                    cout << b[j] << " ";
                }
                cout << "\n";
                flag = false;
                break;
            }
        }
        if (flag) cout << "-1\n";
    }
}

