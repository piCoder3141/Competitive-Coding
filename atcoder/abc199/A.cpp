#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const ll MOD = 998244353;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, c; cin >> a >> b >> c;
    bool ans = a*a + b*b < c*c;
    cout << (ans ? "Yes" : "No");
}


