#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const ll MOD = 998244353;

ll powmod(ll x, ll y, ll mod){
    ll ret = 1;
    while (y > 0){
        if (y&1) ret = (ret * x) % mod;
        x = (x*x) % mod; y /= 2;
    }
    return ret;
}
int nCrModpDP(int n, int r, int p)
{
    // The array C is going to store last row of
    // pascal triangle at the end. And last entry
    // of last row is nCr
    int C[r+1];
    memset(C, 0, sizeof(C));
 
    C[0] = 1; // Top row of Pascal Triangle
 
    // One by constructs remaining rows of Pascal
    // Triangle from top to bottom
    for (int i = 1; i <= n; i++)
    {
        // Fill entries of current row using previous
        // row values
        for (int j = min(i, r); j > 0; j--)
 
            // nCj = (n-1)Cj + (n-1)C(j-1);
            C[j] = (C[j] + C[j-1])%p;
    }
    return C[r];
}

int nCrModpLucas(int n, int r, int p)
{
   // Base case
   if (r==0)
      return 1;
 
   // Compute last digits of n and r in base p
   int ni = n%p, ri = r%p;
 
   // Compute result for last digits computed above, and
   // for remaining digits.  Multiply the two results and
   // compute the result of multiplication in modulo p.
   return (nCrModpLucas(n/p, r/p, p) * // Last digits of n and r
           nCrModpDP(ni, ri, p)) % p;  // Remaining digits
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    string s; cin >> s;
    vector<ll> a(n);
    for (int i = 0; i < n; i++){
        if (s[i] == 'B') a[i] = 0;
        else if (s[i] == 'W') a[i] = 1;
        else a[i] = 2;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++){
        ll add = (nCrModpLucas(n-1, i, 3) * a[i]) % 3;
        ans = (ans + add) % 3;
    }
    if(n%2 == 0) ans = (3 - ans) % 3;
    if (ans == 0) cout << "B";
    else if (ans == 1) cout << "W";
    else cout << "R";
}
