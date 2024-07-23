#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int k, x, y;std::cin >> k >> x >> y;
    if (k % 2 == 0) {
        std::cout << (x + 2 * y) / k;
    }
    else {
        int ans = std::min(x, y / (k / 2));
        x -= ans, y -= (k / 2) * ans;
        if (x) {
            std::cout << (x + 2 * y) / k + ans;
        }
        else {
            std::cout << y / (k / 2 + 1) + ans;
        }
    }
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