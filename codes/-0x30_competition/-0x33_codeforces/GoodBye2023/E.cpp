#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 6e6, mod = 1e9 + 7;
int p[MAXN], a[MAXN], cnts[MAXN];
vector<set<int>> vt[MAXN];int vti = 0;
map<int, set<int>*> mp;

void solve() {
    int n;cin >> n;
    for (int i = 1;i < n;++i) cin >> p[i], p[i]--;
    for (int i = 0;i < n;++i) cin >> a[i];
    for (int i = 0;i < n;++i) cnts[i] = 0, vt[i].clear();
    for (int num : p)cnts[num]++;
    vector<int> leaves;
    for (int i = 0;i < n;++i)if (cnts[i] == 0)leaves.push_back(i);
    for (int num : leaves) {
        if (mp.find(num) == mp.end())mp[num] = (set<int>*) & vt[vti++];
        mp[num]->insert(a[num]);
    }

}

signed main() {
    ios::sync_with_stdio(false);
    int t;cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}