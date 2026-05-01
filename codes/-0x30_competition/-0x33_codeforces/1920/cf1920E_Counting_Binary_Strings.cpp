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
const int mod = 998244353;

void solve() {
    int n, k;std::cin >> n >> k;
    std::vector<std::vector<i64>> dp(n + 1, std::vector<i64>(k + 1));
    for (int i = 1;i <= k;++i)dp[0][i] = 1;
    for (int i = 0;i <= n;++i) {
        for (int j = 1;j <= k;++j) {
            for (int t = 1;j + t - 1 <= k && i + j * t <= n;++t) {
                dp[i + j * t][t] = (dp[i + j * t][t] + dp[i][j]) % mod;
            }
        }
    }
    i64 ans = 0;
    for (int i = 1;i <= k;++i) {
        ans = (ans + dp[n][i]) % mod;
    }
    std::cout << ans;
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