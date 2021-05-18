#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const ll MOD = 998244353;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    int a[n];
    for (int i = 0; i < m; i++){
        cin >> a[i];
    }
    for (int i = 0; i < m; i++){
        cout << a[i] << " ";
    }
}


