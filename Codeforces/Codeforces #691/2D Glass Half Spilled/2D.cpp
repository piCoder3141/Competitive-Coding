#include<bits/stdc++.h>

using namespace std; 

#define ll long long
#define ii pair<int, int>
#define pll pair<ll, ll>

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t=1; // cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> a(n), b(n);
		int T = 0;
		double B = 0;
		for (int i = 0; i < n; i++){
			cin >> a[i] >> b[i];
			T += a[i]; B += 1.0 * b[i];
		}
		vector<vector<int>> dp(n+1, vector<int>(T+1, -1));
		dp[0][0] = 0;
		for (int i = 0; i < n; i++){
			for (int j = i; j >= 0; j--){
				for (int x = 0; x <= T - a[i]; x++){
					if (dp[j][x] == -1) continue;
					dp[j+1][x+a[i]] = max(dp[j+1][x+a[i]], dp[j][x] + b[i]);
				}
			}
		}
		double ans = 0;
		cout << fixed;
		for (int k = 1; k <= n; k++){
			for (int x = 1; x <= T; x++){
				if (dp[k][x] == -1) continue;
				ans = max(ans, min((double) x, B/2.0 + (double) dp[k][x]/2.0));
			}
			cout << setprecision(11) << ans << " ";
		}
	}
}