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
    int n, m;std::cin >> n >> m;
    std::vector<a3> edges(m);
    std::vector g(n, std::vector<a2>());
    for (auto& [u, v, w] : edges) {
        std::cin >> u >> v >> w;
        u--, v--;
        g[u].push_back({ v, w });
        g[v].push_back({ u, w });
    }
    std::vector<a2> max1(n);
    std::vector<int> vis(n);
    std::priority_queue<a3, std::vector<a3>, std::greater<a3>> pq1;
    pq1.push({ 0, 0, 0 });
    while (pq1.size()) {
        auto [first, second, u] = pq1.top();
        pq1.pop();
        if (vis[u]) continue;
        // std::cout << first << ' ' << second << ' ' << u << '\n';
        vis[u] = 1;
        max1[u] = { first, second };
        for (auto [v, w] : g[u]) {
            int f = first, s = second;
            if (w > f) std::swap(w, f);
            if (w > s) std::swap(w, s);
            pq1.push({ f, s, v });
            // if (u == 1)std::cout << f << " " << s << " " << v << '\n';
        }
    }
    vis.assign(n, 0);
    std::vector<a2> max2(n);
    std::priority_queue<a3, std::vector<a3>, std::greater<a3>> pq2;
    pq2.push({ 0, 0, n - 1 });
    while (pq2.size()) {
        auto [first, second, u] = pq2.top();
        pq2.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        max2[u] = { first, second };
        for (auto [v, w] : g[u]) {
            int f = first, s = second;
            if (w > f) std::swap(w, f);
            if (w > s) std::swap(w, s);
            pq2.push({ f, s, v });
        }
    }
    // for (auto [f, s] : max1)std::cout << f << ' ' << s << '\n';
    // for (auto [f, s] : max2)std::cout << f << ' ' << s << '\n';
    int ans = inf * 2;
    for (auto [u, v, w] : edges) {
        // std::cout << u << ' ' << v << '\n';
        std::array<int, 5> info = { max1[u][0], max1[u][1], max2[v][0], max2[v][1], w };
        ranges::sort(info, std::greater<int>());
        // for (auto x : info)std::cout << x << " ";std::cout << '\n';
        ans = std::min(ans, info[0] + info[1]);
        info = { max2[u][0], max2[u][1], max1[v][0], max1[v][1], w };
        ranges::sort(info, std::greater<int>());
        // for (auto x : info)std::cout << x << " ";std::cout << '\n';
        ans = std::min(ans, info[0] + info[1]);
    }
    std::cout << ans;
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