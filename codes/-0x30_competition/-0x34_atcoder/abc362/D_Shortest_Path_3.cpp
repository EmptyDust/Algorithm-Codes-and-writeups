#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<i64, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, m;std::cin >> n >> m;
    std::vector<int> a(n + 1);
    for (int i = 1;i <= n;++i)std::cin >> a[i];
    std::vector<pii> adj[n + 1];
    for (int i = 0;i < m;++i) {
        int u, v, b;std::cin >> u >> v >> b;
        adj[u].push_back({ v,b });
        adj[v].push_back({ u,b });
    }
    std::vector<i64> ans(n + 1, -1);
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
    pq.push({ a[1],1 });
    while (pq.size()) {
        auto [d, x] = pq.top();
        pq.pop();
        if (~ans[x])continue;
        ans[x] = d;
        for (auto [nxt, dis] : adj[x]) {
            pq.push({ d + dis + a[nxt],nxt });
        }
    }
    for (int i = 2;i <= n;++i)std::cout << ans[i] << ' ';
    return 0;
}