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
        if ((n <= 25) && (n & 1)){
            cout << "-1\n";
            continue;
        }
        int place_new = 1, x = 2;
        if (n & 1){
            for (int i = 1; i <= n; i++){
                if ((i == 1) || (i == 10) || (i == 26)) cout << 1 << " ";
                else if ((i == 23) || (i == 27)){
                    cout << 2 << " ";
                }
                else{
                    if (place_new) {
                        cout << ++x << " ";
                    }
                    else{
                        cout << x << " ";
                    }
                    place_new ^= 1;
                }
            }
        }
        else{
            for (int i = 1; i <= n/2; i++) cout << i << " " << i << " ";
            cout << "\n";
        }
    }
}


