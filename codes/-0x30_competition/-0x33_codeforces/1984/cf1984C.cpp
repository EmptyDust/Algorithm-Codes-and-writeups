#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 998244353;
i64 nums[MAXN], dp[MAXN][2], sums[MAXN], n;
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

void solve() {
    std::cin >> n;
    for (int i = 1;i <= n;++i)std::cin >> nums[i];
    int cnt = 0, cnt2 = 0;
    for (int i = 1;i <= n;++i) {
        sums[i] = sums[i - 1] + nums[i];
        if (sums[i] >= 0)cnt2++;
    }
    i64 min = *std::min_element(sums + 1, sums + n + 1);
    if (min >= 0) {
        std::cout << qpow(2, n);
        return;
    }
    i64 ans = 0, cur = 1;
    for (int i = 1;i <= n;++i) {
        if (sums[i] >= 0)cur = cur * 2 % mod;
        else if (sums[i] == min) {
            ans = (ans + cur * qpow(2, n - i) % mod) % mod;
        }
    }
    std::cout << ans;
}

/*
void solve() {
    std::cin >> n;
    for (int i = 1;i <= n;++i)std::cin >> nums[i];
    for (int i = 1;i <= n;++i) {
        dp[i][0] = std::max({
            dp[i - 1][0] + nums[i],
            std::abs(dp[i - 1][0] + nums[i]),
            std::abs(dp[i - 1][1] + nums[i])
            });
        dp[i][1] = dp[i - 1][1] + nums[i];
    }
    std::cout << dp[n][0];
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

*/

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