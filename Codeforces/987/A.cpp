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
        int prev = -1, cnt = 1, mxcnt = 1;

        for (int i = 0; i < n; i++){
            int x; cin >> x;
            if (x == prev){
                cnt++; mxcnt = max(mxcnt, cnt);
            }
            else{
                cnt = 1; prev = x;
            }
        }
        
        cout << n - mxcnt << "\n";
    }
}

