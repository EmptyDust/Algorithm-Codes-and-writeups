#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<i64, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const i64 inf = 1e16;
// const int mod = 1e9 + 7;
const int mod = 998244353;
// R or L | R -> L | R <- L
void solve() {
    int n;std::cin >> n;
    std::vector map(n, std::vector<int>(n));
    for (auto& vt : map)for (auto& x : vt)std::cin >> x;
    std::vector<int> a(n), b(n);
    for (auto& x : a)std::cin >> x;
    for (auto& x : b)std::cin >> x;
    i64 ans = 0;
    {
        std::vector<int> status(n);
        std::vector dp(n, a2());
        dp[0][1] = a[0];
        for (int i = 1;i < n;++i) {
            for (int j = 0;j < n;++j) {
                if (map[i][j] == map[i - 1][j]) status[i] |= 1 << 2;
                if (map[i][j] + 1 == map[i - 1][j]) status[i] |= 1 << 1;
                if (map[i][j] == map[i - 1][j] + 1) status[i] |= 1 << 0;
            }
            // std::cout << status[i] << ' ';
            if (status[i] == 7) {
                std::cout << -1;
                return;
            }
            if (status[i] == 0) {
                dp[i][0] = std::min(dp[i - 1][0], dp[i - 1][1]);
                dp[i][1] = std::min(dp[i - 1][0], dp[i - 1][1]);
            }
            if (status[i] == 1) {
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = std::min(dp[i - 1][0], dp[i - 1][1]);
            }
            if (status[i] == 2) {
                dp[i][0] = std::min(dp[i - 1][0], dp[i - 1][1]);
                dp[i][1] = dp[i - 1][1];
            }
            if (status[i] == 3) {
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = dp[i - 1][1];
            }
            if (status[i] == 4) {
                dp[i][0] = dp[i - 1][1];
                dp[i][1] = dp[i - 1][0];
            }
            if (status[i] == 5) {
                dp[i][0] = inf;
                dp[i][1] = dp[i - 1][0];
            }
            if (status[i] == 6) {
                dp[i][0] = dp[i - 1][1];
                dp[i][1] = inf;
            }
            dp[i][1] += a[i];
            dp[i][0] = std::min(dp[i][0], inf);
            dp[i][1] = std::min(dp[i][1], inf);
            // std::cout << status[i] << ' ' << dp[i][0] << ' ' << dp[i][1] << '\n';
        }
        ans += std::min(dp.back()[0], dp.back()[1]);
    }
    // std::cout << '\n';
    {
        std::vector<int> status(n);
        std::vector dp(n, a2());
        dp[0][1] = b[0];
        for (int j = 1;j < n;++j) {
            for (int i = 0;i < n;++i) {
                if (map[i][j] == map[i][j - 1]) status[j] |= 1 << 2;
                if (map[i][j] + 1 == map[i][j - 1]) status[j] |= 1 << 1;
                if (map[i][j] == map[i][j - 1] + 1) status[j] |= 1 << 0;
            }
            if (status[j] == 7) {
                std::cout << -1;
                return;
            }
            if (status[j] == 0) {
                dp[j][0] = std::min(dp[j - 1][0], dp[j - 1][1]);
                dp[j][1] = std::min(dp[j - 1][0], dp[j - 1][1]);
            }
            if (status[j] == 1) {
                dp[j][0] = dp[j - 1][0];
                dp[j][1] = std::min(dp[j - 1][0], dp[j - 1][1]);
            }
            if (status[j] == 2) {
                dp[j][0] = std::min(dp[j - 1][0], dp[j - 1][1]);
                dp[j][1] = dp[j - 1][1];
            }
            if (status[j] == 3) {
                dp[j][0] = dp[j - 1][0];
                dp[j][1] = dp[j - 1][1];
            }
            if (status[j] == 4) {
                dp[j][0] = dp[j - 1][1];
                dp[j][1] = dp[j - 1][0];
            }
            if (status[j] == 5) {
                dp[j][0] = inf;
                dp[j][1] = dp[j - 1][0];
            }
            if (status[j] == 6) {
                dp[j][0] = dp[j - 1][1];
                dp[j][1] = inf;
            }
            dp[j][1] += b[j];
            dp[j][0] = std::min(dp[j][0], inf);
            dp[j][1] = std::min(dp[j][1], inf);
            // std::cout << status[j] << ' ' << dp[j][0] << ' ' << dp[j][1] << '\n';
        }
        ans += std::min(dp.back()[0], dp.back()[1]);
    }
    if (ans >= inf)std::cout << -1;
    else std::cout << ans;
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