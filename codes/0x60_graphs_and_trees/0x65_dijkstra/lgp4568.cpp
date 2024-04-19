#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e4 + 10, inf = 1e9;
int n, m, k, s, t;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m >> k;
    std::cin >> s >> t;
    std::vector<pt> adj[n];
    int u, v, w;
    while (m--) {
        std::cin >> u >> v >> w;
        adj[u].push_back({ v,w });
        adj[v].push_back({ u,w });
    }
    std::vector<std::vector<int>> dis(k + 1, std::vector<int>(n, inf));
    std::priority_queue<pt, std::vector<pt>, std::greater<pt>> pq[k + 1];
    int res = inf;
    pq[0].push({ s,0 });
    for (int i = 0;i <= k;++i) {
        while (pq[i].size()) {
            auto [pos, d] = pq[i].top();
            pq[i].pop();
            if (dis[i][pos] <= d)continue;
            dis[i][pos] = d;
            for (auto& [nxt, w] : adj[pos]) {
                if (dis[i][nxt] > d + w)pq[i].push({ nxt, d + w });
                if (i < k && dis[i + 1][nxt] > d) pq[i + 1].push({ nxt ,d });
            }
        }
        res = std::min(dis[i][t], res);
    }
    std::cout << res;
    return 0;
}