#include<bits/stdc++.h>

using namespace std; 

#define ll long long
#define ii pair<int, int>
#define pll pair<ll, ll>

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n, x, y; cin >> n; 
		string s1, s2; cin >> s1 >> s2;
		int count = 0;
		for (int i = 0; i < n; i++){
			x = s1[i] - '0';
			y = s2[i] - '0';
			if (x > y) count++;
			else if (x < y) count--;
		}
		if (count > 0){
			cout << "RED\n";
		}
		else if (count < 0){
			cout << "BLUE\n";
		}
		else{
			cout << "EQUAL\n";
		}
	}
}