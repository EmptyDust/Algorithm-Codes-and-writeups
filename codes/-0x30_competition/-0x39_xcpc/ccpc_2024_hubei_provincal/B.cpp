#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;
#define x first
#define y second

void solve() {
    std::cin >> n;
    std::vector<pt> pts(n);
    for (auto& [x, y] : pts)std::cin >> x >> y;
    double ans = 0;
    for (int i = 0;i < n;++i)for (int j = 0;j < n;++j)for (int k = 0;k < n;++k) {
        ans = (double)1 / 2 * (pts[i].x * pts[j].y + pts[j].x);
    }
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