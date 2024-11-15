#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++){
        // --+++
        // minus = 2, plus = 3, n = 5
        int n; cin >> n;
        string s; cin >> s;
        int plus = 0, minus = 0;
        for (char c: s){
            if (c == '+') plus++;
            else minus++;
        }
        cout << n - 2 * min(plus, minus) << "\n";
    }
}

