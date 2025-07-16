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
    int n, m, k;std::cin >> n >> m >> k;
    std::vector adj(n, std::vector<int>(n, 1));
    std::vector<int> d(n, n), color(n, -1);
    for (int i = 0;i < m;++i) {
        int sz;std::cin >> sz;
        std::vector<int> a(sz);
        for (auto& x : a) {
            std::cin >> x;
            x--;
            color[x] = i;
        }
        for (auto x : a)for (auto y : a) {
            adj[x][y] = 0;
            d[x]--;
        }
    }
    if (ranges::min(d) < 2 * k) {
        std::cout << "No\n";
        return;
    }
    std::vector<int> circle, cur(n), ex_edge(n, -1), odd;
    for (int i = 0;i < n;++i)if (d[i] % 2)odd.push_back(i);
    // for (auto x : odd)std::cout << x << " ";
    for (int i = 0;i < odd.size();i += 2) {
        int u = odd[i];
        int v = odd[i + 1];
        ex_edge[u] = v;
        ex_edge[v] = u;
    }
    auto dfs = [&](auto&& dfs, int u)->void {
        for (;cur[u] < n;cur[u]++) {
            if (adj[u][cur[u]] && adj[cur[u]][u]) {
                adj[cur[u]][u] = 0;
                dfs(dfs, cur[u]);
            }
        }
        if (ex_edge[u] != -1) {
            int v = ex_edge[u];
            ex_edge[u] = -1;
            ex_edge[v] = -1;
            dfs(dfs, v);
        }
        circle.push_back(u);
        };
    dfs(dfs, 0);
    std::cout << "Yes\n";
    for (int i = 0;i < n;++i) {
        std::cout << std::accumulate(adj[i].begin(), adj[i].end(), 0) << ' ';
        for (int j = 0;j < n;++j)
            if (adj[i][j])
                std::cout << j + 1 << ' ';
        std::cout << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}