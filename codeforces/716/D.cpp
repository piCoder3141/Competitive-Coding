#include <bits/stdc++.h>

using namespace std;


int block_size, n, k, greatest = 0;
vector<int> a, answers;
int mp[300001], cnt[300001];

struct Query {
    int l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};
vector<Query> queries;

void remove(int idx){
    int x = a[idx];
    int c = mp[x];
    cnt[c]--;
    mp[x]--;
    if (c > 1) cnt[c-1]++;
    while(cnt[greatest] == 0) greatest--;
} 

void add(int idx){
    int x = a[idx];
    int c = mp[x];
    mp[x]++;
    cnt[c+1]++;
    if (c > 0) cnt[c]--;
    greatest = max(greatest, mp[x]);
}    
int get_answer(int sz){
    int left = sz - greatest;
    return max(1, greatest - left);
}
vector<int> mo_s_algorithm(vector<Query> queries) {
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end());

    // TODO: initialize data structure

    int cur_l = 0;
    int cur_r = -1;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        answers[q.idx] = get_answer(cur_r - cur_l + 1);
    }
    return answers;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(mp, 0, sizeof(mp));
    cin >> n >> k;
    block_size = (int) sqrt(n + .0) + 1;
    a.assign(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    queries.assign(k, {});
    for (int i = 0; i < k; i++){
        int l, r; cin >> l >> r; l--; r--;
        queries[i].idx = i;
        queries[i].l = l;
        queries[i].r = r;
    }
    vector<int> ans = mo_s_algorithm(queries);
    for (auto x : ans) cout << x << "\n";
}
