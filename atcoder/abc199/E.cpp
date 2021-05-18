#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define REP(i,n) for(int i = 0; i < (n); i++)

const ll mod = 1e9+7;
ll n, m, k;
vector<int> a;
vector<vector<ll>> adj;

ll powmod(ll x, ll y){
    ll ret = 1;
    while (y > 0){
        if (y&1) ret = (ret * x) % mod;
        y /= 2; x = (x*x) % mod;
    }
    return ret;
}

struct Matrix {
	vector<vector<ll>> a = vector<vector<ll>>(n, vector<ll>(n));
	Matrix operator *(const Matrix& other) {
		Matrix product;
		REP(i,n)REP(j,n)REP(k,n) {
			product.a[i][k] = (product.a[i][k] + (long long) a[i][j] * other.a[j][k]) % mod;
		}
		return product;
	}
};
Matrix expo_power(Matrix a, long long k) {
	Matrix product;
	REP(i,n) product.a[i][i] = 1;
	while(k > 0) {
		if(k % 2) {
			product = product * a;
		}
		a = a * a;
		k /= 2;
	}
	return product;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    a.assign(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    adj.assign(n, vector<ll>(n, 0));
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b; a--; b--;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    ll m_inv = powmod(m, mod-2), two_inv = powmod(2ll, mod-2);
    Matrix M{adj};
    vector<int> d(n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) d[i] += adj[i][j];
    }
    ll my_const = (m_inv * two_inv) % mod;
    ll c_v;
    for (int i = 0; i < n; i++){
        c_v = (d[i] * my_const) % mod;
        for (int j = 0 ; j < n; j++){
            if (j == i){
                M.a[i][i] = (((c_v)% mod) + (((m-d[i])*m_inv)% mod)) % mod; 
            }
            else{
                if (M.a[i][j] == 1) M.a[i][j] = my_const;
            }
        }
    }
    Matrix M_pow = expo_power(M, k);
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            ans[i] = (ans[i] + ((M_pow.a[i][j] * a[j]) % mod)) % mod;
        }
        cout << ans[i] << "\n";
    }
}


// v[t+1] = d[v]/ m (v[t]*d[v] + sum)/ 2 + (m-d[v])/m * v[t]
// v[t+1] = 1/2 *4 + 5/2
// d[v]/2m (v[t]*d[v]) + 
// v[t+1] = d[v]/2m * sum + (m - d[v]/2) / m * v[t]
// v[t+1] = 3/4* 6 
// v[t+1] = 1/m (v[t] + v[i])/ 2
