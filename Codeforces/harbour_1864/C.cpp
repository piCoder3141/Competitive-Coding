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
        int x; cin >> x;
        vector<int> ans(1, x);

        int pow2 = 1;
        for (int b = 0; b <= 30; b++){
            if (x == pow2){
                while (x > 1){
                    x >>= 1;
                    ans.push_back(x);
                }
            }
            else{
                if ((x >> b) & 1){
                    x -= pow2;
                    ans.push_back(x);
                }
            }
            pow2 <<= 1;
        }
        cout << ans.size() << "\n";
        for (int &d: ans) cout << d << " ";
        cout << "\n";
    }
}


