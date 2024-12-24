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
    int n, m;i64 k;std::cin >> n >> m >> k;
    std::vector<i64> dp(m, 1e18);//pos shift_cnt
    dp[0] = 0;
    for (int _ = 0;_ < n;++_) {
        std::vector<i64> a(m);
        std::vector ndp(m, std::vector<i64>(m));//pos shift_cnt
        for (auto& x : a)std::cin >> x;

        for (int i = 0;i < m;++i)
            for (int j = 0;j < m;++j) {
                ndp[i][j] = dp[i] + a[(i + j) % m] + j * k;
                if (i)ndp[i][j] = std::min(ndp[i][j], ndp[i - 1][j] + a[(i + j) % m]);
            }
        dp.assign(m, 1e18);

        for (int i = 0;i < m;++i)
            for (int j = 0;j < m;++j) {
                dp[i] = std::min(dp[i], ndp[i][j]);
            }
        // for (auto x : dp)std::cout << x << " ";std::cout << '\n';
    }
    std::cout << dp.back();
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