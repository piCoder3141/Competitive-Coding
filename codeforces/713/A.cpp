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
        int ans = 0, wrong = -1;
        vector<pii> a(n);
        for (int i = 0; i < n; i++){
            int x; cin >> x;
            a[i] = {x, i+1};
        }
        sort(a.begin(), a.end());
        if (a[0].first == a[1].first){
            cout << a[n-1].second << endl;
        }
        else{
            cout << a[0].second << endl;
        }
    }
}

