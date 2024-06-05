#include <bits/stdc++.h>
using i64 = long long;
constexpr i64 MAXN = 1e6 + 10, inf = 1e18, mod = 1e9 + 7;
using pt = std::pair<int, int>;

void solve() {
    int n;std::cin >> n;
    std::vector<pt> pts(n);
    for (auto& [t, c] : pts)std::cin >> t >> c;
    for (int i = 2;i < n;++i)if (pts[i].first == pts[i - 1].first && pts[i].first == pts[i - 2].first) {
        std::cout << -1;
        return;
    }
    auto check = [&](auto x)->bool {
        auto [t, c] = pts[0];
        i64 l = -inf, r = inf;
        for (int i = 1;i < n;++i) {
            i64 newl = inf, newr = -inf;
            auto [newt, newc] = pts[i];
            i64 w = (newt - t) * x;
            if (c - w <= newc && newc <= c + w) {
                newl = std::min(newl, l - w);
                newr = std::max(newr, r + w);
            }
            if (l - w <= newc && newc <= r + w) {
                newl = std::min(newl, c - w);
                newr = std::max(newr, c + w);
            }
            l = newl;
            r = newr;
            if (r < l)return false;
            t = newt;
            c = newc;
        }
        return true;
        };
    i64 l = 0, r = 1e9;
    i64 ans = inf;
    while (l <= r) {
        auto mid = l + r >> 1;
        if (check(mid)) {
            ans = std::min(ans, mid);
            r = mid - 1;
        }
        else l = mid + 1;
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