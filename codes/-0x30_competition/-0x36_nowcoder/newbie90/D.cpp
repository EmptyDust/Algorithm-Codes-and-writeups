#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, mod = 998244353;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, m;std::cin >> n >> m;
    std::vector<pt> pts(m);
    for (auto& [l, r] : pts)std::cin >> l >> r;
    std::sort(pts.begin(), pts.end());
    std::map<int, std::map<int, i64>> f;
    f[0][0] = 1;
    for (auto& [l, r] : pts) {
        std::map g = f;
        for (int i = l - 1;i <= n;++i) {
            if (!f.count(i))continue;
            for (auto& [j, cur] : f[i]) {
                g[std::max(i, std::min(j, r))][std::max(j, r)] += f[i][j];
                g[std::max(i, std::min(j, r))][std::max(j, r)] %= mod;
            }
        }
        f.swap(g);
    }
    std::cout << f[n][n];
    return 0;
}