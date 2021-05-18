#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const ll MOD = 998244353;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin >> s;
    int n = s.length(); 
    vector<int> pi(n);
    set<int> middle;
    for (int i = 1; i < n; i++){
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j]) j = pi[j-1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
        if (i < n-1) middle.insert(j);
    }
    bool ok = false;
    string ans; 
    int last = pi[n-1];
    while (last > 0){
        auto it = middle.lower_bound(last);
        if (it != middle.end()){
            ok = true; ans = s.substr(0, last);
            break;
        }
        last = pi[last-1];
    }
    cout << (ok ? ans : "Just a legend");
}

// pi[j] <- maximum length prefix of s[0..j] which is also a suffix.
// pi[0] = 0; for j > 0: k = pi[j-1]; while(k > 0 && s[k] != s[j]) k = pi[k]; 
// Fianlly if (s[k] == s[j]) pi[j] = k+1;
