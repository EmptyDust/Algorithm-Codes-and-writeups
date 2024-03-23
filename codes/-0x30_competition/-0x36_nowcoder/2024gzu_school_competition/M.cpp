#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int n;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    std::vector<std::array<int, 3>> pts(n);
    for (int i = 0;i < n;++i) {
        std::cin >> pts[i][0] >> pts[i][1];
        pts[i][2] = i + 1;
    }
    std::sort(pts.begin(), pts.end());
    std::cout << n / 2 << '\n';
    for (int i = 0;i < n;i += 2) {
        if (i + 1 < n)
            std::cout << pts[i][2] << ' ' << pts[i + 1][2] << '\n';
    }
    return 0;
}