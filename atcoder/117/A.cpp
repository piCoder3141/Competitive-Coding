#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const ll MOD = 998244353;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b; cin >> a >> b;
    int n = a+b;
    int big = max(a, b), small = min(a, b);
    vector<int> pos(big), neg(small);
    for (int i = 0; i < big; i++){
        pos[i] = i+1;
    }
    for (int i = 0; i < small-1; i++){
        neg[i] = i+1;
    }
    int sum = 0;
    for (int i = small; i <= big; i++) sum += i;
    neg[small-1] = sum;
    if (a > b){
        for (auto x : pos) cout << x << " ";
        for (auto x : neg) cout << -x << " ";
    }
    else{
        for (auto x : neg) cout << x << " ";
        for (auto x : pos) cout << -x << " ";
    }

}


