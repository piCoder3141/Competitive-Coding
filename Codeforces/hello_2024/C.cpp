#include <bits/stdc++.h>

using namespace std;

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
        vector<vector<int>> sub;
        sub.push_back(vector<int>(a[0], 1));
        for (int i = 1; i < n; i++){
            if (a[i] <= a[i-1]){
                sub.push_back(vector<int>(a[i], 1));
            }
            else{
                sub.back().push_back(a[i]);
            }
        }
        int ans = 0;
        for (auto const &v: sub){
            int sz = v.size();
            ans += max(sz - 2, 0);
        }

        cout << ans << "\n";
    }
}

