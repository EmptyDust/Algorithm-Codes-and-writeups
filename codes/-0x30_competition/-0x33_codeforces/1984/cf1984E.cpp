#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pt = std::pair<int, int>;
std::vector<int> adj[MAXN];//u| v id

void solve() {
    int n;std::cin >> n;
    for (int i = 0;i < n;++i)adj[i].clear();
    std::vector<bool> point(n, false);
    std::vector<int> nodes(n);

    for (int i = 1;i < n;++i) {
        int u, v;std::cin >> u >> v;u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        nodes[u]++, nodes[v]++;
    }

    i64 ans = 0;
    for (int i = 0;i < n;++i)if (nodes[i] == 1 && nodes[adj[i][0]] == 2) {
        ans++;
        nodes[i]--;
        nodes[adj[i][0]]--;
        break;
    }

    std::priority_queue<pt> pq;//adjcnt id

    for (int i = 0;i < n;++i)if (nodes[i]) {
        pq.push({ nodes[i],i });
    }

    while (pq.size()) {
        auto [adjcnt, id] = pq.top();
        pq.pop();
        if (point[id] || nodes[id] != adjcnt)continue;
        if (!nodes[id])ans++;
        nodes[id]--;
        point[id] = 1;
        for (int nxt : adj[id]) if (!point[nxt]) {
            nodes[nxt]--;
            pq.push({ nodes[nxt], nxt });
        }
    }

    std::cout << ans;
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