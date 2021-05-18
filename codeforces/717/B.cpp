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
        for (int i = 0; i < n; i++) cin >> a[i];
        int reqd = 0;
        for (int i = 0; i < n; i++) reqd ^= a[i];
        bool ok = false;
        if (reqd == 0){
            ok = true;
        }
        else{
            int left = 0, right = 0;
            for (int i = 0; i < n-2; i++){
                left ^= a[i];
                right = 0;
                for (int j = i+1; j < n; j++) right ^= a[j];
                for (int j = i+1; j < n-1; j++){
                    right ^= a[j];
                    if (left == right && left == reqd){
                        ok = true; break;
                    }
                }
                if (ok) break;
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}

