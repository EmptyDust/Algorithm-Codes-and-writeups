#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<int, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> p(n + 1), q(n + 1);

    for (int i = 1; i <= n; i++) std::cin >> p[i];
    for (int i = 0; i <= n; i++) std::cin >> q[i];

    std::vector<std::vector<i64>> dp(n + 2, std::vector<i64>(n + 1, 0));
    std::vector<std::vector<i64>> w(n + 2, std::vector<i64>(n + 1, 0));

    for (int i = 0; i <= n; i++) {
        w[i + 1][i] = q[i];
        dp[i + 1][i] = 0;
    }

    for (int len = 1; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;

            w[i][j] = w[i][j - 1] + p[j] + q[j];

            dp[i][j] = LLONG_MAX;
            for (int r = i; r <= j; r++) {
                i64 cost = dp[i][r - 1] + dp[r + 1][j] + w[i][j];
                dp[i][j] = std::min(dp[i][j], cost);
            }
        }
    }

    std::cout << dp[1][n] << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}