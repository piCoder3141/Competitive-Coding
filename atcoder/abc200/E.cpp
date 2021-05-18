#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const ll MOD = 998244353;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    ll k; cin >> k;
    // Assuming 0 <= i, j, k <= n-1;
    vector<vector<ll>> dp(3, vector<ll>(3*n));
    vector<ll> pref(3*n);
    // dp[S][0] = 1; 0 <= S <= n-1; dp[S][0] = 0 otherwise. 
    for (int S = 0; S < n; S++) dp[0][S] = 1; 
    pref = dp[0];
    for (int i = 1; i < 3*n; i++){
        pref[i] += pref[i-1];
        if (i >= n) pref[i] -= dp[0][i-n];
    }
    // for (auto x : pref) cout << x << " ";
    // cout << endl;
    for (int i = 1; i < 3; i++){
        dp[i][0] = 1;
        for (int s = 1; s < 3*n; s++){
            dp[i][s] = pref[s];
        }
        pref = dp[i];
        for (int s = 1; s < 3*n; s++){
            pref[s] += pref[s-1];
            if (s >= n) pref[s] -= dp[i][s-n];
        }
        // for (auto x : pref) cout << x << " ";
        // cout << endl;
    }
    // Find sum S of the Kth cake. 
    pref = dp[2];
    for (int i = 1; i < 3*n; i++) pref[i] += pref[i-1];
    ll S = lower_bound(pref.begin(), pref.end(), k) - pref.begin();
    if (S == 0){
        cout << "1 1 1"; return 0;
    }
    // for (int i = 0; i < 3; i++){
    //     for (int j = 0; j < 3*n; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // Find B, T and P; 
    ll M = pref[S-1];
    int B=0, T=0;
    ll curr = M;
    for (B = 0; curr < k && B <= min(S, 1ll*n-1); B++){
        curr += dp[1][S-B];
    }
    curr -= dp[1][S-B+1];
    B--;
    S -= B;
    for (T = 0; curr < k && T <= min(S, 1ll*n-1); T++){
        curr += dp[0][S-T];
    }
    T--;
    S -= T;
    B++; T++; S++;
    cout << B << " " << T << " " << S; 
}

// If we can find the sum of the Kth cake. 
// 3, 4, 4, 4, 5, 5, 5
// The sum can be in between 0 and 3N-3. 
// i+j+k = S and 0 <= i, j, k < N 
// dp[S][i] = Number of ways to get sum S with i parameters. 
// dp[S][i] = dp[S][i-1] + dp[S-1][i-1] + ... + dp[max(S-N, 0][i-1];
// Found the sum of the Kth cake. 
// let's assume the sum is S. and there are M cakes with sum S-1. let's assume the beauty is B. 
// dp[S][2] + dp[S-1][2] + ... + dp[max(S-N, 0)][2] + M  > K 
// I need to find the first B where M + dp[S][2] + dp[S-1] + ... + dp[S-B][2] > K
// Let's M = M + dp[S][2] + .. dp[S-(B-1)][2]. S = S - B; 
// I need to find the first B wehre M + dp[S][1] + dp[S-1] + ... + dp[S-T] > K 
