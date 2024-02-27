#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n, c[MAXN];
using pt = pair<int, int>;
vector<int> adj[MAXN];

void solve() {
    int n;cin >> n;
    for (int i = 0;i < n;++i) {
        cin >> c[i];
        c[i]--;
        adj[i].clear();
    }
    int u, v;
    for (int i = 0;i < n - 1;++i) {
        cin >> u >> v;u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<map<int, int>> mp(n + 1);
    int ans = 0;
    auto dfs = [&](auto self, int x, int par) -> void {
        for (auto nxt : adj[x])if (nxt != par) {
            self(self, nxt, x);
            if (mp[nxt].count(c[x])) {
                ans += mp[nxt][c[x]];
                mp[nxt].erase(c[x]);
            }
            if (mp[nxt].size() > mp[x].size())
                swap(mp[nxt], mp[x]);
            for (auto [color, cnt] : mp[nxt]) {
                ans += cnt * mp[x][color];
                mp[x][color] += cnt;
            }
            mp[nxt].clear();
        }
        mp[x][c[x]]++;
        };
    dfs(dfs, 0, -1);
    cout << ans;
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