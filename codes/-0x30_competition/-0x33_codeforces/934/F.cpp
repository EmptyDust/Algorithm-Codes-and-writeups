#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    int n, k, p;std::cin >> n >> k >> p;
    //a b c 
    //a + c >= b
    //c >= b - a
    //a is too max to handle $a+c>=b$
    std::vector<std::vector<i64>> dp(n + 2, std::vector<i64>(k + 1, 0)), sum(n + 2, std::vector<i64>(k + 1, 0)), ssum(n + 2, std::vector<i64>(k + 1, 0));
    dp[0][0] = 1;
    for (int j = 0;j <= k;++j)dp[1][j] = 1;
    for (int i = 0;i <= n + 1;++i) {
        if (i > 1) {
            for (int j = 0;j <= k;++j) {
                dp[i][j] = sum[i - 1][k];
                dp[i][j] -= sum[i - 2][k - j] * (k - j) - ssum[i - 2][k - j];
                dp[i][j] = (dp[i][j] % p + p) % p;
            }
        }
        sum[i][0] = dp[i][0];
        for (int j = 1;j <= k;++j) {
            sum[i][j] = (sum[i][j - 1] + dp[i][j]) % p;
            ssum[i][j] = (ssum[i][j - 1] + dp[i][j] * j % p) % p;
        }
    }
    std::cout << dp[n + 1][0];
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