#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++){
        int n, k; cin >> n >> k;
        vector<int> a(n);
        bool flag = true;
        int peaks = 0, l = 1, r = n;
        for (int i = 0; i < n; i++){
            if (peaks == k) flag = false;
            if (i&1 && flag){
                a[i] = r--; 
                if (i < n-1) peaks++;
            }
            else{
                a[i] = l++;
            }
        }
        if (peaks < k){
            cout << "-1\n"; continue;
        }
        for (auto x : a) cout << x << " "; cout << "\n";
    }
}
