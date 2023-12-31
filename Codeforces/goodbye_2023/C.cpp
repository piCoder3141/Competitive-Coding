#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++){
        int n; cin >> n;
        long long sum = 0, ocount = 0;
        for (int i = 0; i < n; i++){
            long long x; cin >> x;
            if (x & 1) ocount++;
            sum += x;
            if (i == 0){
                cout << sum << " ";
            }
            else if (i == 1){
                cout << sum - (ocount & 1) << " ";
            }
            else{
                if (ocount % 3 == 1){
                    cout << sum - (ocount / 3) - 1 << " ";
                }
                else{
                    cout << sum - (ocount / 3) << " ";
                }
            }
        }

        cout << "\n";
    }
}

