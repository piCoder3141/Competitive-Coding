#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>

const ll MOD = 998244353;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<int> P, G; 
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        if (x == 1) P.push_back(i);
        else G.push_back(i);
    }
    int ps = P.size(), gs= G.size();
    vector<pii> ans;
    for (int t = 1; t <= n; t++){
        bool ok = true;
        int pp = 0, gp = 0, setp = 0, setg = 0, last;
        while(pp < ps ||  gp < gs){
            int nxtp = n, nxtg = n;
            if(pp + t - 1 >= ps && gp + t - 1 >= gs){
                ok = false; break;
            }
            if (pp + t - 1 < ps) nxtp = P[pp + t - 1];
            if (gp + t - 1 < gs) nxtg = G[gp + t - 1];
            if (nxtp < nxtg){
                last = 0;
                setp++;
                pp += t;
                gp = upper_bound(G.begin(), G.end(), nxtp) - G.begin();
            }
            else{
                last = 1;
                setg++;
                gp += t;
                pp = upper_bound(P.begin(), P.end(), nxtg) - P.begin();
            }
        }
        if (last && setg <= setp) ok = false;
        if (!last && setp <= setg) ok = false;
        int sets = max(setp, setg);
        if (ok) ans.emplace_back(sets, t);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (auto x : ans){
        cout << x.first << " " << x.second << "\n";
    }
}


