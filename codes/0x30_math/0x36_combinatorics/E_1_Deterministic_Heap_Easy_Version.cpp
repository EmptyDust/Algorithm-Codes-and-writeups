#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
i64 mod;

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
    i64 n, k, p;std::cin >> n >> k >> p;
    mod = p;
    std::vector<std::vector<i64>> dp(n + 1, std::vector<i64>(k + 1));
    std::vector<i64> pow2(n);pow2[0] = 1;
    for (int i = 1;i < n;++i)pow2[i] = pow2[i - 1] * 2 % mod;
    for (int j = 0;j <= k;++j)dp[0][j] = 1;
    for (int i = 1;i < n;++i) {
        std::vector<i64> binom(k + 1, 1);
        for (int j = 1;j <= k;++j) {
            binom[j] = binom[j - 1] * (pow2[i] - 2 + j + mod) % mod;
            binom[j] = binom[j] * inv(j) % mod;
        }
        for (int j = 1;j <= k;++j) {
            dp[i][j] = dp[i][j - 1];
            for (int t = j;t > j - t;--t) {
                dp[i][j] = (dp[i][j] + dp[i - 1][t] * binom[j - t] % mod) % mod;
            }
        }
    }
    std::cout << dp[n - 1][k] * qpow(2, n - 1) % mod;
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