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
    set<int> ans;
    if (n == 3){
        cout << "6 10 15"; return 0;
    }
    for (int i = 6; i < 10000; i += 6){
        ans.insert(i);
    }
    for (int i = 10; i <= 10000; i += 10){
        ans.insert(i);
    }
    for (int i = 15; i <= 10000; i+= 15){
        ans.insert(i);
    }
    cout << ans.size() << endl;
    auto it= ans.begin();
    for (int i = 0; i < n; i++){
        cout << *it << " ";
        it++;
    }
}


