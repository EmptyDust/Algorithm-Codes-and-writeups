#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 998244353;
int nums[MAXN], n;
using pt = std::pair<int, int>;

i64 qpow(i64 x, i64 p) {
    i64 ret = 1;
    while (p) {
        if (p & 1)ret = ret * x % mod;
        p >>= 1;
        x = x * x % mod;
    }
    return ret;
}

#define inv(x) qpow(x,mod-2)

void solve() {
    i64 m, a, b, c;
    std::cin >> m >> a >> b >> c;
    if (m == 1) {
        std::cout << c;
        return;
    }
    i64 res = inv(m) * inv(m) % mod * c % mod;//3
    res = (res + (m - 1) * (m - 2) % mod * inv(m) % mod * inv(m) % mod * a % mod) % mod;//1
    res = (res + ((1 - inv(m) * inv(m) % mod - (m - 1) * (m - 2) % mod * inv(m) % mod * inv(m) % mod) % mod + mod) * b % mod) % mod;//2;
    std::cout << res;
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