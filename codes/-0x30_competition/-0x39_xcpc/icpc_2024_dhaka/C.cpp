#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

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
    int n, q;std::cin >> n >> q;
    std::vector adj(n, std::vector<pii>());
    std::vector fa(30, std::vector<int>(n));
    for (int i = 1;i < n;++i) {
        int u, v, w;std::cin >> u >> v >> w;u--, v--;
        adj[u].push_back({ v,w });
        adj[v].push_back({ u,w });
    }
    std::vector<i64> depth(n);
    auto dfs = [&](auto&& self, int u, int p, i64 dep)->void {
        depth[u] = dep;
        fa[0][u] = p;
        for (int i = 1;i < 30;++i) {
            if (fa[i - 1][u] != -1) {
                fa[i][u] = fa[i - 1][fa[i - 1][u]];
            }
            else break;
        }
        for (auto [v, w] : adj[u])if (v != p) {
            self(self, v, u, dep + w);
        }
        };
    dfs(dfs, 0, -1, 0);
    auto dis = [&](int u, int v) {return std::abs(depth[u] - depth[v]);};
    auto lca = [&](int u, int v) {
        if (depth[u] < depth[v])std::swap(u, v);
        while (depth[u] > depth[v])
            u = fa[u][std::__lg(depth[u] - depth[v]) - 1];
        if (u == v)return u;
        for (int k = std::__lg(depth[u]) - 1;k >= 0;--k)
            if (fa[u][k] != fa[v][k])
                u = fa[u][k], v = fa[v][k];
        return fa[u][0];
        };
    while (q--) {
        int a1, b1, a2, b2;
        std::cin >> a1 >> b1 >> a2 >> b2;
        
    }
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