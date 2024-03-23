#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
using pt = std::pair<int, int>;

void solve() {
    int m, n;std::cin >> n >> m;
    std::vector<i64> a(n), b(n);
    for (int i = 0;i < n;++i)std::cin >> a[i];
    for (int i = 0;i < n;++i)std::cin >> b[i];
    i64 ans = 0;
    for (int i = m;i < n;++i)ans += std::min(a[i], b[i]);
    i64 ans2 = 1e18, sum = 0;
    for (int i = m - 1;~i;--i) {
        ans2 = std::min(ans2, a[i] + sum);
        sum += b[i];
    }
    std::cout << ans + ans2;
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