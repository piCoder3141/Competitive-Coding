#include<bits/stdc++.h>

using namespace std; 

#define ll long long
#define ii pair<int, int>
#define pll pair<ll, ll>

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t=1; cin >> t;
	while(t--){
		int n, m; cin >> n >> m; 
		vector<vector<int>> p(n, vector<int>(n)), ans(n, vector<int>(n));
		int x;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				cin >> x; x--;
				p[i][j] = x;
			}
		}
		vector<int> shift(3, 0), ord(3);
		iota(ord.begin(), ord.end(), 0);
		string s; cin >> s;
		for (int i = 0; i < m; i++){
			char c = s[i];
			if (c == 'R'){
				shift[1] = (shift[1] + 1) % n;
			}
			else if (c == 'L'){
				shift[1] = (shift[1] + n - 1) % n;
			}
			else if (c == 'U'){
				shift[0] = (shift[0] + n - 1) % n;
			}
			else if (c == 'D'){
				shift[0] = (shift[0] + 1) % n;
			}
			else if (c == 'I'){
				swap(ord[1], ord[2]);
				swap(shift[1], shift[2]);
			}
			else if (c == 'C'){
				swap(ord[0], ord[2]);
				swap(shift[0], shift[2]);
			}
		}
		vector<int> curr(3), ncoords(3);
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				curr[0] = i; curr[1] = j; curr[2] = p[i][j];
				for (int k = 0; k < 3; k++){
					ncoords[k] = (shift[k] + curr[ord[k]]) % n;
				}
				ans[ncoords[0]][ncoords[1]] = ncoords[2];
			}
		}

		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				cout << ans[i][j] + 1 << " ";
			}
			cout << endl;
		}
	}
}