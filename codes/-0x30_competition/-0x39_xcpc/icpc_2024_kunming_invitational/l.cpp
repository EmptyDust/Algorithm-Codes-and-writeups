#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pt = std::pair<i64, i64>;

void solve() {
    i64 n, p, q;
    std::cin >> n >> p >> q;
    std::vector<pt> pts(n);
    for (auto& [x, y] : pts)std::cin >> x >> y;
    std::sort(pts.begin(), pts.end(), [&](pt a, pt b) {
        if (a.first == b.first)return a.second > b.second;
        return a.first < b.first;
        });

    i64 ans = 0;
    {
        i64 sx = (0 + q) * (q + 1) / 2;
        i64 mx = (p + p + q) * (q + 1) / 2;
        ans = (sx + mx) * (p + 1) / 2;
    }

    std::vector<i64> f(n + 1, q);
    int len = 0;
    f[0] = 0;
    for (int i = 0;i < n;i++)
    {
        auto [x, y] = pts[i];
        if (x >= p || y >= q)continue;
        int l = 0, r = len, res = 0;
        while (l <= r)
        {
            int mid = l + r >> 1;
            if (f[mid] < y) {
                res = std::max(res, mid);
                l = mid + 1;
            }
            else r = mid - 1;
        }
        res++;
        len = std::max(len, res);
        ans -= (f[res] - y) * (p - x);
        f[res] = y;
    }
    std::cout << ans;
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