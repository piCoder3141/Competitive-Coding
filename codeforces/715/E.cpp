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
        vector<string> s(3);
        for (int i = 0; i < n; i++){
            cin >> s[i];
        }
        vector<int> ones(3), zeroes(3);
        for (int i = 0; i < 3; i++){
            for (auto c : s[i]){
                if (c == '1') ones[i]++;
                else zeroes[i]++;
            }
        }
        string a, b;
        bool take_one;
        if (ones[0] >= n){
            a = s[0];
            take_one = true;
            if (ones[1] >= n){
                b = s[1];
            }
            else if(ones[2] >= n){
                b = s[2];
            }
            else{
                a = s[1], b = s[2];
                take_one = false;
            }
        }
        else{
            a = s[0];
            take_one = false;
            if (zeroes[1] >= n){
                b = s[1];
            }
            else if (zeroes[2] >= n){
                b = s[2];
            }
            else{
                a = s[1], b = s[2];
                take_one = true;
            }
        }
        string ans = "";
        if (take_one){
            int l1 = 0, l2 = 0;
            int c1 = 0, c2 = 0, c;
            for (auto c : a){
                if (c == '1') c1++;
            }
            for (auto c : b){
                if (c == '1') c2++;
            }
            c = min(c1, c2);
            while(a[l1] != '1'){
                ans += '0'; l1++;
            }
            while(b[l2] != '1'){
                ans += '0'; l2++;
            }
            l1++; l2++;
            for (int i = 0; i < c; i++){
                ans += '1';
                while (l1 < 2*n && a[l1] != '1'){
                    ans += '0'; l1++;
                }
                while (l2 < 2*n && b[l2] != '1'){
                    ans += '0'; l2++;
                }
                l1++; l2++;
            }
            for (int i = l1; i < 2*n; i++){
                ans += a[i];
            }
            for (int i = l2; i < 2*n; i++){
                ans += b[i];
            }
        }
        else{
            
            int l1 = 0, l2 = 0;
            int c1 = 0, c2 = 0, c;
            for (auto c : a){
                if (c == '0') c1++;
            }
            for (auto c : b){
                if (c == '0') c2++;
            }
            c = min(c1, c2);
            while(a[l1] != '0'){
                ans += '1'; l1++;
            }
            while(b[l2] != '0'){
                ans += '1'; l2++;
            }
            l1++; l2++;
            for (int i = 0; i < c; i++){
                ans += '0';
                while (l1 < 2*n && a[l1] != '0'){
                    ans += '1'; l1++;
                }
                while (l2 < 2*n && b[l2] != '0'){
                    ans += '1'; l2++;
                }
                l1++; l2++;
            }
            for (int i = l1; i < 2*n; i++){
                ans += a[i];
            }
            for (int i = l2; i < 2*n; i++){
                ans += b[i];
            }
        }
        cout << ans << "\n";
    }
}

