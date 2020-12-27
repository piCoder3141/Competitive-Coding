/*
Problem Link:- https://www.hackerearth.com/problem/algorithm/sum-of-digits-8/
Author:- Aditya Prakash Singh
*/


#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
const int M = 17;
const int S = 150;
 
ll dp[M][S][2][2];
ll min_solution = -1;

// Call to digit dp function.
// up -> 1 : No upper bound; 0 : Can go up as high num[pos]
// down - > 1 : No lower bound; 0 : Has to be at least num[pos]
ll call(ll prefix, int pos, int sum, int up, int below, int K, vector<int> &small, vector<int> &big){
    if (pos == big.size()){
        if (sum == K){
            if (min_solution == -1 || prefix < min_solution) min_solution = prefix;
            return 1;
        }
        else return 0;
    }
    if (dp[pos][sum][up][below] != -1) return dp[pos][sum][up][below];
 
    ll ans = 0;
    int uplimit = (up) ? 9 : big[pos];
    int downlimit = (below) ? 0 : small[pos];
 
    for (int dig = downlimit; dig <= uplimit; dig++){
        ans += call(prefix*10ll + dig, pos+1, sum+dig, (up ||(dig < big[pos])), (below ||(dig > small[pos])), K, small, big);
    }
 
    return dp[pos][sum][up][below] = ans;
}
 
ll solve(ll low, ll high, int S){
    vector<int> small, big;

    // Creating vectors out of the numbers. 
    while(low){
        small.push_back(low%10);
        low /= 10;
    }
    while (high){
        big.push_back(high%10);
        high /= 10;
    }
    while(small.size() < big.size()) small.push_back(0);
    reverse(small.begin(), small.end());
    reverse(big.begin(), big.end());
 
    memset(dp, -1, sizeof(dp));
    return call(0, 0, 0, 0, 0, S, small, big);
}
 
int main(){
    int t=1; //cin >> t;
    while(t--){
        ll low, high; cin >> low >> high;
        int S; cin >> S;
        cout << solve(low, high, S) << endl;
        cout << min_solution;
    }
}