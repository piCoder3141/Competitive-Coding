#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const ll MOD = 998244353;
const int M = 2e5 + 1;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    bitset<M> bit;
    bit.reset();
    bit[0] = 1;
    for (int i = 0; i < n; i++) bit |= (bit << a[i]);
    int sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];
    if (sum & 1 || bit[sum/2] == 0){
        cout << 0; return 0;
    }
    cout << 1 << "\n";
    for (int i = 0; i < n; i++){
        if (a[i] & 1){
            cout << i+1; return 0;
        }
        int x = (sum - a[i]) / 2;
        if (bit[x] == 0){
            cout << i+1; return 0;
        }
    }
}


