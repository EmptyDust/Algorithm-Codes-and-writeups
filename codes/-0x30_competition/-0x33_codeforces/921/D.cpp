#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, mod = 1e9 + 7;
int nums[MAXN], n, m, k;
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
    std::cin >> n >> m >> k;
    i64 d = 1ll * n * (n - 1) % mod * inv(2) % mod;
    i64 sum = 0, cnt = 0;
    i64 u, v, w;
    for (int i = 0;i < m;++i) {
        std::cin >> u >> v >> w;
        sum = (sum + w) % mod;
        cnt++;
    }
    i64 ans = 1ll * k * sum % mod * inv(d) % mod;
    i64 res = 0, c;
    for (int x = 0;x <= k;++x) {
        if (x) c = c * (k - x + 1) % mod * inv(x) % mod;
        else c = 1;
        i64 tmp = 1ll * x * (x - 1) % mod * inv(2) % mod * c % mod * qpow(d - 1, k - x) % mod * inv(qpow(d, k)) % mod;
        res = (res + tmp) % mod;
    }
    ans = (ans + m * res % mod) % mod;
    std::cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}