#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    int x, y;
    std::cin >> x >> y;
    int ans = y / 2 + y % 2;
    x -= y / 2 * 7;
    if (y % 2)x -= 11;
    if (x > 0) {
        ans += x / 15 + (x % 15 > 0);
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