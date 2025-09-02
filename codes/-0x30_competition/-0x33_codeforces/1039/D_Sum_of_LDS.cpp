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
    int n;std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a)std::cin >> x;
    std::vector<i64> dp(n);
    dp[0] = 1; dp[1] = 2;
    for (int i = 0;i < n;++i) {
        if (i > 0 && a[i - 1] > a[i]) {
            dp[i] = std::max(dp[i], dp[i - 1] + i + 1);
        }
        if (i > 1 && a[i - 2] > a[i]) {
            dp[i] = std::max(dp[i], dp[i - 2] + i - 1 + 1 + 1);
        }
        // std::cout << dp[i] << '\n';
    }
    std::cout << std::accumulate(dp.begin(), dp.end(), 0ll);
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