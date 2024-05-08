#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 2e6 + 10, inf = 1e9, mod = 1e9 + 7;
i64 N, M;
using pt = std::pair<int, int>;

void solve() {
    std::cin >> N >> M;
    i64 ans = 0;
    for (i64 a0 = 1;a0 <= N;++a0) {
        for (i64 b0 = 1;(a0 + b0) * a0 <= N;++b0) {
            if (std::__gcd(a0, b0) == 1) {
                ans += std::min(M / ((a0 + b0) * b0), N / ((a0 + b0) * a0));
            }
        }
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