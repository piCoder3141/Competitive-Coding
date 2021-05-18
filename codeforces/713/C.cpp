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
        int a, b; cin >> a >> b;
        string s; cin >> s;
        int n = a + b;
        bool ok = true;
        if ((a&1) && (b&1)) ok = false;
        for (int i = 0; i < n/2; i++){
            if (s[i] == '?' && s[n-i-1] == '?') continue;
            if (s[i] != '?' && s[n-i-1] != '?'){
                if (s[i] != s[n-i-1]){
                    ok = false; break;
                }
            }
            else if (s[i] == '?') s[i] = s[n-i-1];
            else s[n-i-1] = s[i];
        }
        int ca = 0, cb = 0;
        for (int i = 0; i < n; i++){
            if (s[i] == '0') ca++;
            else if (s[i] == '1') cb++;
        }
        if (ca > a || cb > b) ok = false;
        if (!ok){
            cout << "-1\n"; continue;
        }
        int la = a - ca, lb = b - cb;
        for (int i = 0; i < n/2; i++){
            if (s[i] == '?'){
                if (la >= 2){
                    s[i] = s[n-i-1] = '0'; la -= 2;
                }
                else if (lb >= 2){
                    s[i] = s[n-i-1] = '1'; lb -= 2;
                }
                else{
                    ok = false; break;
                }
            }
        }
        if (n & 1 && s[n/2] == '?'){
            if (la >= 1){
                s[n/2] = '0';
            }
            else if (lb >= 1){
                s[n/2] = '1';
                
            }
            else ok = false;
            
        }
        cout << (ok ? s : "-1") << "\n";

    }
}

