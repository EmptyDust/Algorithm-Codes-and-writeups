#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n, m;std::cin >> n >> m;
    std::vector<int> deg(n);
    std::vector<pii> edg(m);
    for (int i = 0;i < m;++i) {
        int u, v;std::cin >> u >> v;u--, v--;
        edg[i] = { u,v };
        deg[u]++;
        deg[v]++;
    }
    std::vector<int> g[n];
    for (auto [u, v] : edg) {
        if (deg[u] > deg[v]) {
            g[v].push_back(u);
        }
        else if (deg[u] < deg[v]) {
            g[u].push_back(v);
        }
        else {
            if (u < v)g[u].push_back(v);
            else g[v].push_back(u);
        }
    }
    std::vector<int> vis(n);
    int ans = 0;
    for (int u = 0;u < n;++u) {
        for (auto v : g[u]) vis[v] = 1;
        for (auto v : g[u]) {
            for (auto w : g[v]) {
                if (vis[w])ans++;
            }
        }
        for (auto v : g[u]) vis[v] = 0;
    }
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}