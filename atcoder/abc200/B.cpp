#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const ll MOD = 998244353;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n; cin >> n;
    int k; cin >> k;
    for (int i = 0; i < k; i++){
        if (n % 200 == 0) n /= 200;
        else{
            n = (n*1000) + 200;
        }
    }
    cout << n;
}


