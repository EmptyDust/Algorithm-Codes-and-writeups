#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n, m;std::cin >> n >> m;
    std::vector<std::vector<int>> black(n), adj(n);
    std::vector<int> edg(m);
    for (int i = 0;i < m;++i) {
        int u, v, c;std::cin >> u >> v >> c;
        u--, v--;
        edg[i] = u ^ v;
        adj[u].push_back(i);
        adj[v].push_back(i);
        if (c == 0) {
            black[u].push_back(i);
            black[v].push_back(i);
        }
    }
    std::vector<int> deg(n);
    for (int i = 0;i < n;++i)deg[i] = adj[i].size() & 1;
    std::vector<bool> del(m), used(n);
    std::function<void(int)> dfs = [&](int u)->void {
        used[u] = true;
        for (auto id : black[u]) {
            int v = edg[id] ^ u;
            if (used[v])continue;
            dfs(v);
            if (deg[v]) {
                del[id] = true;
                deg[v] ^= 1;
                deg[u] ^= 1;
            }
        }
        };
    bool ok = true;
    for (int i = 0;i < n;++i) {
        if (used[i])continue;;
        dfs(i);
        ok &= !deg[i];
    }
    if (!ok) {
        std::cout << "NO\n";
        return;
    }
    std::function<void(int)> euler = [&](int u)->void {
        while (!adj[u].empty()) {
            int id = adj[u].back();
            adj[u].pop_back();
            int v = edg[id] ^ u;
            if (del[id])continue;
            del[id] = true;
            euler(v);
        }
        std::cout << u + 1 << ' ';
        };
    std::cout << "YES\n";
    std::cout << m - std::accumulate(del.begin(), del.end(), 0) << '\n';
    euler(0);
    std::cout << '\n';
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