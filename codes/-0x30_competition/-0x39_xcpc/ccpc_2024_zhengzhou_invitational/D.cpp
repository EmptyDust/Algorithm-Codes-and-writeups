#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pt = std::pair<i64, i64>;
#define x first
#define y second

void solve() {
    int n;std::cin >> n;
    std::vector<pt> pts(n);
    for (auto& [x, y] : pts)std::cin >> x >> y;
    std::sort(pts.begin(), pts.end(), [&](auto a, auto b) {
        return a.x - a.y < b.x - b.y;
        });
    double ans = 1;
    for (int i = 0;i < n - 1;++i) {
        auto& [ax, ay] = pts[i];
        auto& [bx, by] = pts[i + 1];
        i64 mdis = std::abs(ax - bx) + std::abs(ay - by);
        i64 odis = (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
        ans = std::max(ans, mdis / std::sqrt(odis));
    }
    std::sort(pts.begin(), pts.end(), [&](auto a, auto b) {
        return a.x + a.y < b.x + b.y;
        });
    for (int i = 0;i < n - 1;++i) {
        auto& [ax, ay] = pts[i];
        auto& [bx, by] = pts[i + 1];
        i64 mdis = std::abs(ax - bx) + std::abs(ay - by);
        i64 odis = (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
        ans = std::max(ans, mdis / std::sqrt(odis));
    }
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cout.precision(15);
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}