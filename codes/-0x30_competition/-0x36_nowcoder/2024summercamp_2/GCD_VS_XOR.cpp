#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    i64 x;std::cin >> x;
    i64 y = x - (x & -x);
    // std::cout << (x ^ y) << ' ' << std::__gcd(x, y) << '\n';
    if (y == 0) {
        std::cout << -1;
    }
    else std::cout << y;
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