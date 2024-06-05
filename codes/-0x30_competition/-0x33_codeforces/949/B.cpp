#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pt = std::pair<int, int>;

void solve() {
    i64 n, m;std::cin >> n >> m;
    i64 ans = 0;
    i64 x = n;
    for (int i = 0;i < 40;++i) {
        if (n >> i & 1) {
            ans |= (i64)1 << i;
            x -= (i64)1 << i;
            continue;
        }
        i64 up = x;
        i64 down = up - 1;
        up += (i64)1 << i;
        i64 min = up - n;
        if (down >= 0)
            min = std::min(min, n - down);
        if (min <= m)ans |= (i64)1 << i;
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