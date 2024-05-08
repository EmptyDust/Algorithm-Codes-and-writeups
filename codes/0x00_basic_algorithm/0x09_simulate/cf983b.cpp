#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;std::cin >> n;
    std::vector<int> nums(n);
    for (int i = 0;i < n;++i)std::cin >> nums[i];
    std::vector<std::vector<int>> dp(n, std::vector<int>(n));
    for (int j = 0;j < n;++j)
        for (int i = j;i < n;++i)
            dp[i][j] = j ? dp[i - 1][j - 1] ^ dp[i][j - 1] : nums[i];
    for (int i = 0;i < n;++i)
        for (int j = 0;j < n;++j)
            dp[i][j] = std::max({ dp[i][j],i && j ? dp[i - 1][j - 1] : 0,j ? dp[i][j - 1] : 0 });
    int q;std::cin >> q;
    int l, r;
    while (q--) {
        std::cin >> l >> r;
        std::cout << dp[r - 1][r - l] << '\n';
    }
    return 0;
}