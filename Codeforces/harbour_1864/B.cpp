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
        int n, k; cin >> n >> k;
        string s; cin >> s;
        if (k & 1){
            string os = "", es = "";
            for (int i = 0; i < n; i++){
                if (i&1) os += s[i];
                else es += s[i];
            }
            sort(os.begin(), os.end());
            sort(es.begin(), es.end());
            s = "";
            for (int i = 0; i < n; i++){
                if (i&1) s += os[i/2];
                else s += es[i/2];
            }
        }
        else{
            sort(s.begin(), s.end());
        }
        cout << s << "\n";
    }
}


