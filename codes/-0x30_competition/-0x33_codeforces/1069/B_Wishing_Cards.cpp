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
    int n, K;std::cin >> n >> K;
    std::vector<int> b(n);
    for (auto& x : b)std::cin >> x;
    int now = 0;
    std::vector<a2> info(1, a2());
    for (int i = 0;i < n;++i) if (b[i] > now) {
        now = b[i];
        info.back()[1] = i - info.back()[1];
        info.push_back({ now, i });
    }
    info.back()[1] = n - info.back()[1];
    // for (auto [a, b] : info)std::cout << a << ' ' << b << '\n';
    // pos sum max 
    // 360 360 360
    n = info.size() - 1;
    std::vector dp(n + 1, std::vector(K + 1, std::vector<int>(K + 1, -1)));
    std::vector max(n + 1, std::vector<int>(K + 1, -1));
    dp[0][0][0] = 0; max[0][0] = 0;
    for (int i = 1;i <= n;++i) {
        for (int j = 0;j <= K;++j) {
            for (int k = 0;k <= K;++k) {
                if (dp[i - 1][j][k] != -1) {
                    dp[i][j][k] = std::max(dp[i][j][k], dp[i - 1][j][k] + k * info[i][1]);
                    // if (j + info[i][0] <= K)
                        // dp[i][j + info[i][0]][info[i][0]] = std::max(dp[i][j + info[i][0]][info[i][0]], dp[i - 1][j][k] + info[i][0] * info[i][1]);
                }
                if (k <= info[i][0] && j >= k && max[i - 1][j - k] != -1) {
                    dp[i][j][k] = std::max(dp[i][j][k], max[i - 1][j - k] + k * info[i][1]);
                }
                // if (i == 1 && j == 1) {
                //     std::cout << dp[i][j][k] << '\n';
                // }
                // std::cout << dp[i][j][k] << ' ';
                max[i][j] = std::max(max[i][j], dp[i][j][k]);
            }
        }
        // std::cout << '\n';
    }
    // dp[pos][sum][max] = max(dp[pos - 1][sum - max][?]) + max


    int ans = 0;
    for (int j = 0;j <= K;++j) {
        for (int k = 0;k <= K;++k) {
            ans = std::max(ans, dp[n][j][k]);
        }
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