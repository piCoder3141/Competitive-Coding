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
		int n, m; cin >> n >> m;
		vector<ll> a(n), b(m), diff(n-1);
		ll diff_gcd, mod_val, ans;
		for (int i = 0; i < n; i++){
			cin >> a[i];
			if (i > 0){
				diff[i-1] = abs(a[i] - a[i-1]);
			}
		}
		for (int i = 0; i < m; i++){
			cin >> b[i];
		}
		diff_gcd = -1;
		for (int i = 0; i < n-1; i++){
			if (diff[i] == 0) continue;
			diff_gcd = (diff_gcd == -1) ? diff[i] : __gcd(diff_gcd, diff[i]);
		}
		if (diff_gcd != -1){
			mod_val = a[0] % diff_gcd;
		}
		for (int i = 0; i < m; i++){
			if (diff_gcd == -1){
				cout << a[0] + b[i] << " "; continue;
			}
			ans = __gcd(b[i] + mod_val, diff_gcd);
			cout << ((ans == 0) ? diff_gcd : ans) << " ";
		}
		cout << "\n";
	}
}