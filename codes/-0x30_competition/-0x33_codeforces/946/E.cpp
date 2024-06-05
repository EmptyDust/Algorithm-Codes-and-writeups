#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<i64, i64>;

void solve() {
    i64 m, x;std::cin >> m >> x;
    std::vector<pt> pts(m);
    i64 sum = 0;
    for (auto& [c, h] : pts)std::cin >> c >> h, sum += h;
    std::vector<i64> value(sum + 1, 1e18);
    value[0] = 0;
    int t = 0;
    for (auto& [c, h] : pts) {
        for (i64 i = sum;i >= h;--i) {
            if (value[i - h] + c <= x * t)
                value[i] = std::min(value[i], value[i - h] + c);
        }
        t++;
    }
    for (int i = sum;i >= 0;--i)if (value[i] != 1e18) {
        std::cout << i;
        return;
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