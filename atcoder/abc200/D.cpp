#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const ll MOD = 998244353;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    const int num = 200;
    int n; cin >> n; 
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i]; a[i] %= num;
    }
    vector<vector<ll>> dp(n+1, vector<ll>(num));
    dp[0][0] = 1;
    int val;
    bool found = false;
    for (int i = 1; i <= n; i++){
        for (int x = 0; x < 200; x++){
            dp[i][x] = dp[i-1][x];
            dp[i][x] += dp[i-1][(x-a[i-1] + num) % num];
            if (dp[i][x] > 1){
                val = x;
                found = true;
                break;
            }
        }
    }
    if (!found){
        cout << "NO"; return 0;
    }
    cout << "YES\n";
    int first=1, second = 1;
    for (first = 1; first <= n; first++){
        if (dp[first][val] == 1) break;
    }
    for (second = 1; second <= n; second++){
        if (dp[second][val] > 1) break;
    }
    vector<int> sub1, sub2;
    first--; second--;
    sub1.push_back(first); sub2.push_back(second);

}

// let's compute dp[i][x] = Number of subsets of A[0..i] such that there sum modulo 200 is x. 
// Final answer: If there is some x such that dp[n-1][x] >= 2. dp
