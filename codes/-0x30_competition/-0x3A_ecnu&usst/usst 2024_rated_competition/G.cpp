#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;
using a3 = std::array<i64, 3>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, m;std::cin >> n >> m;
    std::vector<std::vector<i64>> dp(n, std::vector<i64>(1 << n, 1e18));
    std::vector<std::vector<i64>> dis(n, std::vector<i64>(n, 1e18));
    while (m--) {
        int u, v;i64 w;
        std::cin >> u >> v >> w;u--, v--;
        dis[u][v] = std::min(dis[u][v], w);
    }
    for (int i = 0;i < n;++i)
        for (int j = 0;j < n;++j)
            for (int k = 0;k < n;++k)
                dis[j][k] = std::min(dis[j][k], dis[j][i] + dis[i][k]);

    for (int i = 0;i < n;++i)dp[i][1 << i] = 0;
    for (int k = 0;k < 1 << n;++k) {
        for (int u = 0;u < n;++u) {
            for (int v = 0;v < n;++v) {
                dp[v][k | 1 << v] = std::min(dp[v][k | 1 << v], dp[u][k] + dis[u][v]);
            }
        }
    }

    i64 min = 1e18;
    for (int i = 0;i < n;++i)min = std::min(min, dp[i][(1 << n) - 1]);
    if (min >= 1e16)std::cout << "No";
    else std::cout << min;
    return 0;
}