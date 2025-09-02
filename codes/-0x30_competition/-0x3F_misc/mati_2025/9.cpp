#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<int, 2>;
using a3 = std::array<i64, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const i64 inf = 1e18;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n, m, k, t;std::cin >> n >> m >> k >> t;
    std::vector g(n, std::vector<a2>());
    for (int i = 0;i < m;++i) {
        int u, v, w;std::cin >> u >> v >> w;
        u--, v--;
        g[u].push_back({ v, w });
        g[v].push_back({ u, w });
    }
    int mask = (1 << k) - 1;
    std::vector<int> rule(n, mask), id(n, k);
    for (int i = 0;i < k;++i) {
        int x;std::cin >> x, x--;
        id[x] = i;
    }
    for (int i = 0;i < t;++i) {
        int x, y;std::cin >> x >> y;
        x--, y--;
        rule[y] ^= 1 << id[x];
    }
    std::vector distance(mask + 1, std::vector<i64>(n, inf));
    std::priority_queue<a3, std::vector<a3>, std::greater<a3>> pq; // dis mask pos
    pq.push({ 0, 0, 0 });
    distance[0][0] = 0;
    while (pq.size()) {
        auto [dis, m, u] = pq.top();
        pq.pop();
        if (distance[m][u] != dis)continue;
        if (id[u] != k) {
            m |= 1 << id[u];
        }
        for (auto [v, w] : g[u]) {
            // std::cerr << u << ' ' << v << ' ' << m << ' ' << rule[v] << '\n';
            if ((m | rule[v]) != mask) continue;
            if (distance[m][v] > dis + w) {
                distance[m][v] = dis + w;
                pq.push({ dis + w, m, v });
            }
        }
    }
    i64 min = inf;
    for (int i = 0;i <= mask;++i) {
        min = std::min(min, distance[i][n - 1]);
    }
    if (min == inf) std::cout << "impossible";
    else std::cout << min;
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