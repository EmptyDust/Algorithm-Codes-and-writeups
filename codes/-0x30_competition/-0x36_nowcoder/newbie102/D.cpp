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
    int n, m, k;std::cin >> n >> m >> k;
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    std::vector<int> dp(k + 1);
    for (int i = 0;i < n;++i) {
        std::vector<int> ndp(k + 1, inf);
        for (int j = 0;j <= k;++j) {
            ndp[0] = std::min(ndp[0], dp[j] + a[i]);
        }
        for (int j = 1;j <= k;++j) {
            ndp[j] = dp[j - 1] + 1;
        }
        dp = ndp;
        for (int j = 0;j <= k;++j)std::cout << dp[j] << ' ';std::cout << '\n';
    }
    std::cout << *std::min_element(dp.begin(), dp.end());
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