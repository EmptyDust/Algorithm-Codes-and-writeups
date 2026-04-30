#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pt = std::pair<int, int>;

void solve() {
    int r;
    std::cin >> r;
    int ans = 0;
    for (int i = 0, u = r, d = r;i <= r;++i) {
        while (u > 0 && i * i + u * u >= (r + 1) * (r + 1))u--;
        while (d > 0 && i * i + d * d >= r * r)d--;
        if (u > 0)
            ans += u - d;
    }
    std::cout << ans * 4;
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