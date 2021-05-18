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
        int n; cin >> n;
        vector<string> inp(n);
        for (int i = 0; i < n; i++){
            cin >> inp[i];
        }
        int k = 0;
        pii pos[2], ins[2];
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (inp[i][j] == '*'){
                    pos[k++] = {i, j};
                }
            }
        }
        if (pos[0].first == pos[1].first){
            int r = (pos[0].first + 1) % n;
            ins[0] = {r, pos[0].second};
            ins[1] = {r, pos[1].second};
        }
        else if (pos[0].second == pos[1].second){
            int c = (pos[0].second + 1) % n;
            ins[0] = {pos[0].first, c};
            ins[1] = {pos[1].first, c};
        }
        else{
            ins[0] = {pos[1].first, pos[0].second};
            ins[1] = {pos[0].first, pos[1].second};
        }
        for (k = 0; k < 2; k++){
            int i = ins[k].first, j = ins[k].second;
            inp[i][j] = '*';
        }
        for (int i = 0; i < n; i++){
            cout << inp[i] << "\n";
        }
    }
}

