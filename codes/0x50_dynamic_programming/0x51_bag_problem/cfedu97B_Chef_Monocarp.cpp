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
    int n;std::cin >> n;
    std::vector<int> t(n), vis(2 * n + 1);
    for (int& x : t)std::cin >> x;
    ranges::sort(t);
    std::vector<int> dp(n + 1, inf);
    dp[0] = 0;
    for (int i = 1;i <= 2 * n;++i) {
        std::vector<int> ndp(n + 1, inf);
        for (int j = 0;j <= n;++j) {
            ndp[j] = dp[j];
            if (j)ndp[j] = std::min(ndp[j], dp[j - 1] + std::abs(t[j - 1] - i));
        }
        dp = ndp;
    }
    std::cout << dp[n];
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