#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++){
        int n, a, b; cin >> n >> a >> b;
        string s; cin >> s;

        int x = 0, y = 0;
        bool poss = (x == a) && (y == b);

        const int K = 200;
        for (int itr = 0; itr < K; itr++){
            for (char &c: s){
                if (c == 'N') y++;
                else if (c == 'E') x++;
                else if (c == 'S') y--;
                else if (c == 'W') x--;

                if ((x == a) && (y == b)) poss = true;
                if (poss) break;
            }
            if (poss) break;
        }

        cout << (poss ? "YES\n": "NO\n");
    }
}


