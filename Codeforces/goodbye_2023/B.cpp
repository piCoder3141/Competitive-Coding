#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++){
        long long a, b; cin >> a >> b;
        long long lcm = a * b / __gcd(a, b);
        if (lcm == max(a, b)){
            cout << lcm * lcm / min(a, b) << "\n";
        }
        else{
            cout << lcm << "\n";
        }
    }
}

