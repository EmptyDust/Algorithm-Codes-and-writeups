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
    int n, m, q;std::cin >> n >> m >> q;
    std::vector<int> adj[n];
    std::vector<int> edg(m), used(m);
    for (int i = 0;i < m;++i) {
        int u, v;std::cin >> u >> v;u--, v--;
        edg[i] = u ^ v;
        adj[u].push_back(i);
        adj[v].push_back(i);
    }
    std::vector<int> deg(n);
    std::queue<int> que;
    for (int i = 0;i < n;++i) {
        deg[i] = adj[i].size();
        if (deg[i] <= 10)que.push(i);
    }

    std::vector<i64> a(n), ans(n);
    for (int i = 0;i < n;++i)std::cin >> a[i];

    std::vector<int> g[n];
    while (que.size()) {
        int u = que.front();
        que.pop();
        for (auto id : adj[u]) {
            if (used[id])continue;
            int v = edg[id] ^ u;
            deg[u]--;
            deg[v]--;
            ans[v] += a[u];
            used[id] = 1;
            g[u].push_back(v);
            if (deg[v] <= 10)que.push(v);
        }
    }

    while (q--) {
        int op;std::cin >> op;
        if (op == 1) {
            int x, v;std::cin >> x >> v;x--;
            a[x] += v;
            for (auto t : g[x])ans[t] += v;
        }
        else {
            int x;std::cin >> x;x--;
            i64 res = ans[x];
            for (auto t : g[x])res += a[t];
            std::cout << res << '\n';
        }
    }
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