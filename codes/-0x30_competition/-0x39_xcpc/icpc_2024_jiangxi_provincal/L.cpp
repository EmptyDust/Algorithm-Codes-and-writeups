#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, m, k, T;std::cin >> n >> m >> k >> T;
    std::vector<std::vector<int>> diss(k, std::vector<int>(n, -1));
    std::vector<std::vector<pii>> adj(n);
    std::vector<i64> a(n);
    for (auto& x : a)std::cin >> x;
    std::vector<a3> gates(k);
    for (auto& [p, l, r] : gates)std::cin >> p >> l >> r, p--;
    while (m--) {
        int u, v, w;
        std::cin >> u >> v >> w;u--, v--;
        adj[u].push_back({ v,w });
        adj[v].push_back({ u,w });
    }
    for (int i = 0;i < k;++i) {
        auto& dis = diss[i];
        auto& [p, l, r] = gates[i];
        std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
        pq.push({ 0,p });
        while (pq.size()) {
            auto [dist, num] = pq.top();
            pq.pop();
            if (~dis[num])continue;
            dis[num] = dist;
            for (auto [nxt, nxtd] : adj[num])if (dis[nxt] == -1) {
                pq.push({ nxtd + dist ,nxt });
            }
        }
    }
    std::vector<std::multiset<int>> res(n);
    i64 ans = 0;int f = 0;
    for (int t = 1;t <= T;++t) {
        for (int i = 0;i < k;++i) {
            if (gates[i][1] == t) {
                auto& dis = diss[i];
                for (int j = 0;j < n;++j)if (~dis[j]) {
                    if (res[j].empty()) {
                        f++;
                        ans += a[j] * dis[j];
                    }
                    else {
                        int cur = *res[j].begin();
                        if (cur > dis[j])ans -= a[j] * (cur - dis[j]);
                    }
                    res[j].insert(dis[j]);
                }
            }
            if (gates[i][2] + 1 == t) {
                auto& dis = diss[i];
                for (int j = 0;j < n;++j)if (~dis[j]) {
                    res[j].extract(dis[j]);
                    if (res[j].empty()) {
                        ans -= a[j] * dis[j];
                        f--;
                    }
                    else {
                        int cur = *res[j].begin();
                        if (cur > dis[j])ans += a[j] * (cur - dis[j]);
                    }
                }
            }
        }
        if (f == n)std::cout << ans << '\n';
        else std::cout << -1 << '\n';
    }
    return 0;
}