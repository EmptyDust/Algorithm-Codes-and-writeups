#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
i64 n, m;
using pt = std::pair<int, int>;

void solve() {
    std::cin >> n >> m;
    i64 res = -1;
    for (i64 i = 1;i <= m;++i) {
        if (i * i - i <= n) {
            res += (n + i) / (i * i);
        }
        else break;
    }
    std::cout << res;
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