#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;
using a3 = std::array<int, 3>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m >> k;
    std::vector<a3> pts;
    for (int i = 0;i < k;++i) {
        auto& [x, y, a] = a3[i];
        std::cin >> x >> y >> a;
    }
    std::sort(pts.begin(), pts.end());
    dfs();
    return 0;
}