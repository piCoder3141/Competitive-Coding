#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const ll MOD = 998244353;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n; cin >> n;
    long long rem, pow_3;
    bool found = false;
    int a = 1, b;

    for (pow_3 = 3; pow_3 < n; pow_3 *= 3){
        rem = n - pow_3;
        bool is_power = true;
        b = 0;
        while (rem > 1){
            if (rem % 5 != 0){
                is_power = false; break;
            }
            b++;
            rem /= 5;
        }
        if (is_power && b > 0){
            found = true;
            break;
        }
        a++;
    }
    if (found){
        cout << a << " " <<  b;
    }
    else{
        cout << -1;
    }
}

// Iterate A from 1 to log_3 N. Remainder = N - 3^a; Check if Remainder is a power of 5. 
