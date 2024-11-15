#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++){
        int a, b; cin >> a >> b;
        cout << (((a+b)&1) ? "Alice": "Bob") << "\n";
    }
}

