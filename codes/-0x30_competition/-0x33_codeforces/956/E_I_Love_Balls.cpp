#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

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
    int n, k;std::cin >> n >> k;
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    i64 sum1 = 0, sum2 = 0;
    for (int i = 0;i < k;++i)sum2 += a[i];sum2 %= mod;
    for (int i = k;i < n;++i)sum1 += a[i];sum1 %= mod;
    int x2 = (n - k) / 2, x1 = n - k - x2;
    int y2 = (n - k + 1) / 2, y1 = n - k + 1 - y2;
    i64 ans1 = (sum1 * x1 % mod * inv(n - k) % mod + sum2 * y1 % mod * inv(n - k + 1) % mod) % mod;
    i64 ans2 = (sum1 * x2 % mod * inv(n - k) % mod + sum2 * y2 % mod * inv(n - k + 1) % mod) % mod;
    std::cout << ans1 << ' ' << ans2;
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