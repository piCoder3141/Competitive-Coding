#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const int MOD = 998244353;

struct node{
    long long cnt;
    int next[2];

    node() {
        cnt = 0;
        next[0] = next[1] = -1;
    }
};

vector<node> trie;

void add(int x){
    int v = 0;
    for (int i = 29; i >= 0; i--){
        int bit = (x >> i) & 1;
        if (trie[v].next[bit] == -1){
            trie[v].next[bit] = trie.size();
            trie.push_back(node());
        }
        v = trie[v].next[bit];
        trie[v].cnt++;
    }
}

long long solve(int v, int k){
    long long idx = k+1;
    bool zero_child = (trie[v].next[0] != -1);
    bool one_child = (trie[v].next[1] != -1);

    long long ans = 0;
    if (zero_child && one_child){ 
        ans += ((2 * (idx / 2) + 1) + (2 * ((idx+1) / 2))) * (trie[trie[v].next[0]].cnt * trie[trie[v].next[1]].cnt);
    }
    else if (!zero_child && !one_child){
        ans += idx * trie[v].cnt * trie[v].cnt;
    }

    if (zero_child){
        ans += solve(trie[v].next[0], k);
    }
    if (one_child){
        ans += solve(trie[v].next[1], k+1);
    }

    return ans;
}

long long powmod(long long x, int y){
    long long ret = 1;
    while (y > 0){
        if (y & 1) ret = (ret * x) % MOD;
        y >>= 1; x = (x * x) % MOD;
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++){
        trie.clear();
        trie.push_back(node());

        int n; cin >> n;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            add(x);
        }

        long long ans = solve(0, 0) % MOD;
        long long n_inv = powmod(n, MOD-2);

        ans = (ans * n_inv) % MOD;
        ans = (ans * n_inv) % MOD;

        cout << ans << "\n";
    }
}


