#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e3 + 10;
int map[MAXN][MAXN], n, m;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m;
    for (int i = 1;i <= n;++i)for (int j = 1;j <= n;++j) {
        std::cin >> map[i][j];
        map[i][j] += map[i - 1][j];
        map[i][j] += map[i][j - 1];
    }

    return 0;
}