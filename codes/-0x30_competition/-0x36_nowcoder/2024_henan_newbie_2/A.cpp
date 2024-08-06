#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, m, q;std::cin >> n >> m >> q;
    std::vector<pii> res(n);
    for (int i = 0;i < n; ++i)std::cin >> res[i].second;
    for (int i = 0;i < m;++i) {
        int u, v;std::cin >> u >> v;
        u--, v--;
        res[u].first += res[v].second;
        res[v].first += res[u].second;
    }
    std::sort(res.begin(), res.end());
    while (q--) {
        int x; std::cin >> x;
        std::cout << res[x - 1].second << '\n';
    }
    return 0;
}