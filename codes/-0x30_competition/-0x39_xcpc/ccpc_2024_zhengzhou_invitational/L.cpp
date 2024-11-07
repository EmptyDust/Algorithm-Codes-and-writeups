#include <bits/stdc++.h>
using i64 = long long;
constexpr i64 MAXN = 1e6 + 10, inf = 1e18, mod = 1e9 + 7;
i64 nums[MAXN], n, m;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m;
    for (int i = 1;i <= m;++i)std::cin >> nums[i];
    std::vector<i64> dp(m + 1, inf);dp[0] = 0;
    for (int i = 1;i <= m;++i)for (int j = std::max(0, i - 400);j < i;++j) {
        i64 cnt = i - j;
        dp[i] = std::min(dp[i], dp[j] + nums[i] + cnt * cnt * cnt * cnt);
    }
    std::cout << dp[m];
    return 0;
}