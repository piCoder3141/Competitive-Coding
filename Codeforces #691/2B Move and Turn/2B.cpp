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
		int k = n/2 + 1;
		if (n%2 == 0){
			cout << k*k << "\n";
		}
		else{
			cout << 2 * k * (k+1) << "\n";
		}
	}
}