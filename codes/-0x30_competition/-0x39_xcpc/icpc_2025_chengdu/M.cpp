#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<i64, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const i64 inf = 1e18;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n, m, k;std::cin >> n >> m >> k;
    std::vector<i64> a(k);
    for (auto& x : a)std::cin >> x, x--;
    std::vector g(n, std::vector<a2>());
    std::vector<a3> edges(m);
    for (auto& [u, v, w] : edges) {
        std::cin >> u >> v >> w; u--, v--;
        g[u].push_back({ v, w });
        g[v].push_back({ u, w });
    }
    std::priority_queue<a2, std::vector<a2>, std::greater<a2>> pq;
    std::vector<i64> dis1(n, inf);
    // assert(0);
    dis1[0] = 0; pq.push({ 0, 0 });
    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (dis1[u] != d)continue;
        for (auto [v, w] : g[u]) if (dis1[u] + w < dis1[v]) {
            dis1[v] = dis1[u] + w;
            pq.push({ dis1[v], v });
        }
    }
    i64 tmeet = 0;
    std::vector<i64> disx(n, inf), color(n, -1);
    for (auto x : a) {
        tmeet = std::max(tmeet, dis1[x]);
        color[x] = x;
        disx[x] = 0;
        pq.push({ 0, x });
    }
    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (disx[u] != d)continue;
        for (auto [v, w] : g[u]) if (disx[u] + w < disx[v]) {
            disx[v] = disx[u] + w;
            color[v] = color[u];
            pq.push({ disx[v], v });
        }
    }
    std::vector<i64> ans(n);
    for (auto [u, v, w] : edges) {
        if (color[u] != color[v]) {
            i64 len = w + disx[u] + disx[v];
            if (std::max(disx[u] + w, disx[v]) + dis1[v] <= tmeet ||
                std::max(disx[u], disx[v] + w) + dis1[u] <= tmeet) {
                i64 res = tmeet * 2 - len;
                ans[color[u]] = std::max(ans[color[u]], res);
                ans[color[v]] = std::max(ans[color[v]], res);
            }
        }
    }
    for (auto x : a) {
        std::cout << ans[x] / 2 << (ans[x] % 2 ? ".5" : ".0") << ' ';
    }
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