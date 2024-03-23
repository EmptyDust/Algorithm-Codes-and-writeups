#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
std::vector<int> adj[MAXN];
using pt = std::pair<int, int>;

void solve() {
    int n;
    std::cin >> n;
    for (int i = 0;i <= n;++i)adj[i].clear();
    int u, v;
    for (int i = 1;i < n;++i) {
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::vector<int> f(n + 1);
    int d = -1, t = -1;
    std::function<void(int, int, int)> dfs = [&](int x, int par, int depth) {
        if (depth >= d) {
            d = depth;
            t = x;
        }
        f[x] = par;
        for (int nxt : adj[x])if (nxt != par) {
            dfs(nxt, x, depth + 1);
        }
        };
    dfs(1, -1, 0);
    dfs(t, -1, 0);
    for (int i = 0;i < d / 2;++i)
        t = f[t];
    if (d % 4 != 3) {
        std::cout << (d + 1) / 2 + 1 << '\n';
        for (int i = 0;i < (d + 1) / 2 + 1;++i) {
            std::cout << t << ' ' << i << '\n';
        }
    }
    else {
        std::cout << (d + 1) / 2 << '\n';
        for (int i = 1;i <= (d + 1) / 4;++i) {
            std::cout << t << ' ' << i * 2 - 1 << '\n';
            std::cout << f[t] << ' ' << i * 2 - 1 << '\n';
        }
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