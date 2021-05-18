#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define cj(t) cout << "Case #" << t << ": "
#define nl "\n"

const int inf = 1e9;
const ll INF = 1e18;
const ll mod = 1e9 + 7;

ll powmod(ll x, ll y, ll md = mod){
    ll ret = 1;
    while (y > 0){
        if (y&1) ret = (ret*x) % md;
        x = (x*x) % md; y /= 2;
    }
    return ret;
}

string construct(string beg, int n){
    string ret = beg;
    ll curr = stoll(beg);
    int len = beg.length();
    while (len < n){
        curr++; beg = to_string(curr);
        ret += beg; len += beg.length();
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++){
        string ans = "1234567891011121314";
        int ans_len = ans.length();
        string candidate, snum; cin >> snum;
        int sz = snum.length(), csz;
        string anum = "1";
        for (int i = 0; i < sz; i++) anum += "0";
        sz = anum.length();
        for (int len = 1; len <= (sz+1)/2; len++){
            string scurr = anum.substr(0, len);
            ll curr = stoll(scurr);
            candidate = construct(scurr, sz);
            csz = candidate.length();
            if (csz > sz || (csz == sz && candidate > anum)){
                if (csz < ans_len || (csz == ans_len && candidate < ans)){
                    ans_len = csz;
                    ans = candidate;
                }
            }
            curr++; scurr = to_string(curr);
            candidate = construct(scurr, sz);
            csz = candidate.length();
            if (csz > sz || (csz == sz && candidate > anum)){
                if (csz < ans_len || (csz == ans_len && candidate < ans)){
                    ans_len = csz;
                    ans = candidate;
                }
            }
        }
        sz = snum.length();
        for (int len = 1; len <= (sz+1)/2; len++){
            string scurr = snum.substr(0, len);
            ll curr = stoll(scurr);
            candidate = construct(scurr, sz);
            csz = candidate.length();
            if (csz > sz || (csz == sz && candidate > snum)){
                if (csz < ans_len || (csz == ans_len && candidate < ans)){
                    ans_len = csz;
                    ans = candidate;
                }
            }
            curr++; scurr = to_string(curr);
            candidate = construct(scurr, sz);
            csz = candidate.length();
            if (csz > sz || (csz == sz && candidate > snum)){
                if (csz < ans_len || (csz == ans_len && candidate < ans)){
                    ans_len = csz;
                    ans = candidate;
                }
            }
        }
        cj(tt) << ans << nl;
    }
}

