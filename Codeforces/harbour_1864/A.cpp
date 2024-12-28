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
        int x, y, n; cin >> x >> y >> n;
        vector<int> a(n);
        a[n-1] = y;
        int diff = 1;
        for (int i = n-2; i >= 0; i--){
            a[i] = a[i+1] - diff++;
        }
        if (a[0] < x){
            cout << "-1\n"; continue;
        }
        a[0] = x;
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << "\n";
    }
}


