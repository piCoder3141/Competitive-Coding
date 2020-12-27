/*
Problem Link:- https://www.spoj.com/problems/CPCRC1C/
Author:- Aditya Prakash Singh
*/



#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
const int M = 11;
const int S = 100;
 
ll dp[M][S][2];
 
// Call to digit dp function.
// up -> 1: No upper bound; 0: At most as high as num[pos]
ll call(int pos, int sum, int up, vector<int> &num){
    if (pos == num.size()) return 1ll*sum;
    if (dp[pos][sum][up] != -1) return dp[pos][sum][up];
 
    ll ans = 0;
    int limit = (up) ? 9 : num[pos];
 
    for (int dig = 0; dig <= limit; dig++){
        ans += call(pos+1, sum+dig, (up ||(dig < num[pos])), num);
    }
 
    return dp[pos][sum][up] = ans;
}
 
ll solve(ll x){
    vector<int> num;
    
    // convert x to a vector of digits.
    while(x){
        num.push_back(x%10);
        x /= 10;
    }
    reverse(num.begin(), num.end());
    memset(dp, -1, sizeof(dp));
    return call(0, 0, 0, num);
}
 
int main(){
    while(true){
        ll low, high; cin >> low >> high;
        if (low == -1 && high == -1) break;
        cout << solve(high) - solve(low-1) << endl;
    }
}