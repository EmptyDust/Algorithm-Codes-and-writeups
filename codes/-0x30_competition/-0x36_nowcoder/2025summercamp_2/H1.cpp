#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using d64 = long double;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<i64, 2>;
using a3 = std::array<i64, 3>;
using a4 = std::array<i64, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const i64 inf = 4e18;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n, m;std::cin >> n >> m;
    std::vector<a4> edges(m);
    std::vector g(n, std::vector<a2>());
    std::vector h(n, std::vector<a2>());
    for (auto& [u, v, t, w] : edges) {
        std::cin >> u >> v >> t >> w;
        u--, v--;
        g[u].push_back({ v, t });
        h[v].push_back({ u, t });
    }
    std::vector<i64> dis1(n, inf), disn(n, inf);
    std::priority_queue<a2, std::vector<a2>, std::greater<a2>> pq;
    pq.push({ 0, 0 }); dis1[0] = 0;
    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dis1[u]) continue;
        for (auto [v, dis] : g[u]) if (d + dis < dis1[v]) {
            dis1[v] = d + dis;
            pq.push({ dis1[v], v });
        }
    }
    pq.push({ 0, n - 1 }); disn[n - 1] = 0;
    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();
        // std::cout << d << ' ' << u << '\n';
        if (d != disn[u]) continue;
        for (auto [v, dis] : h[u]) if (d + dis < disn[v]) {
            disn[v] = d + dis;
            pq.push({ disn[v], v });
        }
    }

    std::vector<a2> a;
    std::vector<std::tuple<d64, a2>> b;
    for (auto& [u, v, t, w] : edges) {
        i64 x = dis1[u] + disn[v] + t;
        a.push_back({ x, w });
    }

    auto inter = [&](a2 a, a2 b) {
        d64 ret = (d64)(a[0] - b[0]) / (a[1] - b[1]);
        return ret;
        };

    ranges::sort(a);
    for (auto [x, k] : a) {
        if (b.size()) {
            auto [_, line] = b.back();
            if (k <= line[1]) continue;
        }
        while (b.size() && inter({ x, k }, get<1>(b.back())) <= get<0>(b.back())) {
            b.pop_back();
        }
        d64 pt = (b.empty() ? -INFINITY : inter({ x,k }, get<1>(b.back())));
        b.push_back({ pt, {x, k} });
    }
    // for (auto [pos, x, y] : b)std::cout << pos << ' ' << x << ' ' << y << '\n';
    int q;std::cin >> q;
    while (q--) {
        i64 k;std::cin >> k;
        std::tuple<d64, a2> w = { k, a2{ (i64)-1e9, (i64)-1e9 } };
        auto [p, l] = *std::prev(std::lower_bound(b.begin(), b.end(), w));
        auto [a, b] = l;
        std::cout << a - k * b << '\n';
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