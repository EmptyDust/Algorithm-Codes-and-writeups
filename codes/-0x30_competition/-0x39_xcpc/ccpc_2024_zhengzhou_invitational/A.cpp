#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pt = std::pair<int, int>;

void solve() {
    i64 n, d;
    std::cin >> n >> d;
    i64 x = 1234567890 + d;
    i64 tmp = n;
    while (tmp) {
        tmp /= 10;
        x *= 10;
    }
    x += n - x % n;
    i64 k = x / n;
    std::cout << k;
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
//123456789000000000