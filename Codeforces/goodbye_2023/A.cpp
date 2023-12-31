#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++){
        int n, k; cin >> n >> k;
        bool ans = true;
        int rem = 2023;
        for (int i = 0; i < n; i++){
            int x; cin >> x;
            if (rem % x != 0){
                ans = false;
            }
            else rem = rem / x;
        }
        if (!ans){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        cout << rem << " ";
        for (int i = 0; i < k-1; i++) cout << "1 ";
        cout << "\n";
    }
}

