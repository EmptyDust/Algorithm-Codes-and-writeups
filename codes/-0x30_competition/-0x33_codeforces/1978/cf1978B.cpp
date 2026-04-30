#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    i64 a, b, c;std::cin >> a >> b >> c;
    if (b >= c) {
        std::cout << a * b;
        return;
    }
    auto k = c - b;
    if (k >= a) {
        std::cout << (c + c - a + 1) * a / 2;
        return;
    }
    i64 ans = (c + b + 1) * k / 2 + b * (a - k);
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