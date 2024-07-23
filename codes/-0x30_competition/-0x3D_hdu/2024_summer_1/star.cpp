#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n, k;std::cin >> n >> k;
    std::vector<i64> dp(k + 1, 1e18);
    dp[0] = 0;
    for (int i = 0;i < n;++i) {
        std::vector<i64> add(4);
        for (auto& x : add)std::cin >> x;
        for (int j = k;j >= 0;--j) {
            for (int t = 0;t < 4;++t) {
                int nj = j + t + 1;
                if (nj <= k) {
                    dp[nj] = std::min(dp[nj], dp[j] + add[t]);
                }
            }
        }
    }
    // for (int i = 0;i < k;++i) {
    //     std::cout << dp[i] << ' ';
    // }
    std::cout << dp[k];
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