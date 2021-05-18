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
        // 1 2 3 4 - 0000
        // 1 2 4 3 - 0001
        // 1 3 2 4 - 0010
        // 1 4 3 2 - 0011
        // 2 1 3 4 - 0100
        // 2 1 4 3 - 0101
        // 3 2 1 4 - 0110
        // 4 3 2 1 - 0111
        // 2 1 3 4 5 - 1000
        // 2 1 3 5 4 - 1001
        // 2 1 4 3 5 - 1010
        int n; ll k; cin >> n >> k;
        string bin = "";
        k--;
        if (k == 0){
            for (int i = 1; i <= n; i++){
                cout << i << " ";
            }
            cout << "\n";
            continue;
        }
        while (k > 0){
            if (k&1) bin += '1';
            else bin += '0';
            k /= 2;
        }
        // reverse(bin.begin(), bin.end());
        int len = bin.length();
        int m = len + 1;
        if (m > n){
            cout << -1 << "\n"; continue;
        }
        vector<int> subans(m);
        int place=m, prev=-1;
        bin += '0';
        for (int i = 0; i < m; i++){
            if (bin[i] == '1') continue;
            for (int j = i; j > prev; j--){
                subans[j] = place - (i-j);
            }
            prev = i;
            place = m-i-1;
        }
        reverse(subans.begin(), subans.end());
        vector<int> ans(n);
        for (int i = 0; i < n-m; i++){
            ans[i] = i+1;
        }
        for (int i = n-m; i < n; i++){
            ans[i] = n-m + subans[i-n+m];
        }
        for (auto x : ans) cout << x << " "; cout << "\n";
    }
}

