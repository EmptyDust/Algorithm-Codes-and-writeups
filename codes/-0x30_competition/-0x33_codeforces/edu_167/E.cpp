#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 2e5, MAXN = 2e5 + 10, inf = 1e9, mod = 998244353;
using pii = std::pair<int, int>;

i64 dp[MAXN][11], minus_s[MAXN];

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);

    i64 n;int k;std::cin >> n >> k;
    std::vector<i64> sums(k + 1);
    dp[0][0] = 1, sums[0] = 1;
    for (int i = 1;i <= n;++i) {
        for (int j = k;j >= 0;--j) {
            int nj = std::min(j + 1, k);
            dp[i][nj] = (dp[i][nj] + sums[j]) % mod;
            if (i > 2 && i != n) {
                dp[i][nj] = ((dp[i][nj] - dp[i - 2][j]) % mod + mod) % mod;
            }
        }
        for (int j = 0;j <= k;++j) {
            sums[j] = (sums[j] + dp[i][j]) % mod;
        }
    }
    std::cout << dp[n][k];
    return 0;
}