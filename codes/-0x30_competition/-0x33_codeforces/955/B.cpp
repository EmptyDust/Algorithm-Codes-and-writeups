#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    i64 x, y, k;std::cin >> x >> y >> k;
    while (k) {
        int lst = y - x % y;
        if (lst > k) {
            std::cout << x + k;
            return;
        }
        k -= lst;
        x += lst;
        while (x % y == 0)x /= y;
        if (x == 1) {
            k = k % (y - 1);
        }
    }
    std::cout << x;
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