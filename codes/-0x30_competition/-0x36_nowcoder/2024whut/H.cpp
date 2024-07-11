#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

i64 qpow(i64 x, i64 p) {
    i64 ret = 1;
    while (p) {
        if (p & 1)ret = ret * x;
        p >>= 1;
        x = x * x;
    }
    return ret;
}


signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    i64 a, b, c;std::cin >> a >> b >> c;
    if (c) {
        i64 ans = ((b * qpow(3, a + 2) - 1) / 100 + 1) * 100 * 3;
        std::cout << ans;
    }
    else {
        i64 ans = ((b * qpow(3, a + 2) * 4 - 1) / 100 + 1) * 100;
        std::cout << ans;
    }
    return 0;
}