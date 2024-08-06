#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    i64 n, k;std::cin >> n >> k;
    std::vector<i64> a(n), b(n);
    for (auto& x : a)std::cin >> x;
    for (auto& x : b)std::cin >> x;
    i64 l = 1, r = 1e9;
    auto check = [&](auto x)->i64 {
        i64 res = 0;
        for (int i = 0;i < n;++i) {
            if (a[i] >= x)
                res += (a[i] - x) / b[i] + 1;
        }
        return res;
        };
    int res = 0;
    while (l <= r) {
        auto mid = l + r >> 1;
        if (check(mid) >= k) {
            l = mid + 1;
            res = mid;
        }
        else r = mid - 1;
    }
    // std::cout << res << " ";
    i64 ans = 0;
    for (int i = 0;i < n; ++i) if (a[i] >= res) {
        i64 t = (a[i] - res) / b[i] + 1;
        ans += (a[i] + a[i] - (t - 1) * b[i]) * t / 2;
    }
    ans -= res * (check(res) - k);
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