#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, num;std::cin >> n;
    i64 xr = 0;
    for (int i = 0;i < n;++i)std::cin >> num, xr ^= num;
    i64 ans = 0;
    for (int i = 0;i < 31;++i) {
        auto lowbit = xr & 1;
        xr >>= 1;
        xr |= lowbit << 30;
        ans = std::max(ans, xr);
    }
    std::cout << ans;
    return 0;
}