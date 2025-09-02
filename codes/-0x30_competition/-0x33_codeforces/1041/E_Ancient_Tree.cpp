#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<int, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;



void solve() {
    int n, k;std::cin >> n >> k;
    std::vector<int> w(n), c(n);
    for (auto& x : w)std::cin >> x;
    for (auto& x : c)std::cin >> x;
    std::vector g(n, std::vector<int>());
    for (int i = 1;i < n;++i) {
        int u, v;std::cin >> u >> v;u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    std::vector<std::set<int>> cols(n);
    i64 ans = 0;
    auto dfs = [&](auto&& dfs, int u, int p) ->void {
        bool f = 1;
        for (auto& v : g[u]) if (v != p) {
            dfs(dfs, v, u);
            if (cols[u].size() < cols[v].size())std::swap(cols[u], cols[v]);
            while (cols[v].size()) {
                auto it = cols[v].begin();
                int x = *it;
                cols[v].erase(it);
                if (x != c[u] && cols[u].count(x)) {
                    if (c[u] == 0) c[u] = x;
                    else f = 0;
                }
                cols[u].insert(x);
            }
        }
        if (!f) ans += w[u];
        if (c[u]) cols[u].insert(c[u]);
        };
    dfs(dfs, 0, -1);
    std::cout << ans << '\n';
    auto dfs2 = [&](auto&& dfs, int u, int p)->void {
        if (!c[u]) c[u] = c[p];
        for (auto& v : g[u])if (v != p) {
            dfs(dfs, v, u);
        }
        };
    if (!c[0]) c[0] = 1;
    dfs2(dfs2, 0, -1);
    for (auto x : c)std::cout << x << ' ';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}