#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<i64, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<i64, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const i64 inf = 4e18;
// const int mod = 1e9 + 7;
const int mod = 998244353;

using Line = std::pair<long long, long long>;

long double inter(Line a, Line b) {
    auto& [w1, k1] = a;
    auto& [w2, k2] = b;
    return -1.0L * (w2 - w1) / (k2 - k1);
}

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
    std::vector<std::pair<i64, i64>> a;
    for (auto& [u, v, t, w] : edges) {
        i64 x = dis1[u] + disn[v] + t;
        a.push_back({ x,-w });
        // if (u == 0 && v == 1)std::cout << dis1[u] << ' ' << disn[v] << '\n';
        // std::cout << u << ' ' << v << ' ' << x << ' ' << w << '\n';
    }

    std::vector<std::tuple<long double, Line>> H;
    std::sort(a.begin(), a.end(), [&](auto a, auto b) {
        return a.second == b.second ? a.first > b.first : a.second > b.second;
        });

    for (auto& [w, k] : a) {
        while (H.size() >= 1) {
            auto& [p1, l1] = H[H.size() - 1];
            if (l1.second == k) {
                H.pop_back();
            }
            else break;
        }
        while (H.size() >= 2) {
            auto& [p1, l1] = H[H.size() - 1];
            auto& [p2, l2] = H[H.size() - 2];

            auto u1 = inter({ w, k }, l1);
            auto u2 = inter({ w, k }, l2);
            if (u1 < u2) {
                H.pop_back();
            }
            else {
                break;
            }
        }

        long double pt = (H.empty() ? -INFINITY : inter({ w, k }, get<1>(H.back())));

        // cerr << "add " << pt << " " << w << " " << k << endl;
        H.push_back({ pt, {w, k} });
    }

    int q;
    std::cin >> q;
    for (int i = 1;i <= q;++i) {
        long long k;
        std::cin >> k;
        std::tuple<long double, Line> w = { k, Line{ -1e9, -1e9 } };
        auto [p, l] = *prev(lower_bound(H.begin(), H.end(), w));
        auto [a, b] = l;
        // cerr << "!! " << a << " " << b << endl;
        std::cout << a + b * k << "\n";
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