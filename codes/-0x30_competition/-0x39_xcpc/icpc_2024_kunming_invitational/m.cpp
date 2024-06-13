#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pt = std::pair<i64, i64>;
using vec = std::pair<i64, i64>;
i64 n, x, y, dis;

bool check(pt a, pt b, pt pos, int dis) {
    if (a == b)return true;
    // 判断距离

    // 判断倾角
    vec ab = { b.first - a.first,b.second - a.second };
    vec oa = a;
    i64 abXoa = ab.first * oa.second - ab.second * oa.first;
    if (abXoa <= 0)return false;//在右侧

    return true;
}

i64 cal(pt a, pt b, pt c) {
    if (a == b || b == c || a == c)return 0;
    return
        a.first * b.second - a.first * c.second
        + b.first * c.second - b.first * a.second
        + c.first * a.second - c.first * b.second;
}

void solve() {
    std::cin >> n;
    std::cin >> x >> y >> dis;
    std::vector<pt> pts(n);
    for (auto& [x, y] : pts)std::cin >> x >> y;
    pt cir = { x,y };
    i64 area = 0, ans = 0;
    for (int l = 0, r = 0;r < n;l++) {
        while (r < n && check(pts[l], pts[r], cir, dis)) {
            r++;
            area += cal(pts[l], pts[r], pts[r - 1]);
        }
        ans = std::max(ans, area);
        area -= cal(pts[l], pts[l + 1], pts[r]);
    }
    std::cout << area;
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