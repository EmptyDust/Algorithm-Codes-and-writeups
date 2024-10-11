#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a2 = std::array<i64, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n, p;std::cin >> n >> p;
    std::vector dp(n + 1, std::vector<a2>(n + 1));
    for (int l = 1;l <= n;++l) {
        for (int r = n;r >= l;--r) {
            if (l == 1 && r == n)dp[l][r][1] = 1;
            else {
                int len = r - l + 1;
                if (r != n)
                    dp[l][r][1] = (dp[l][r][1] + dp[l][r + 1][1] * (n - len) % p + dp[l][r + 1][0]) % p;
                if (l != 1)
                    dp[l][r][0] = (dp[l][r][0] + (dp[l - 1][r][0] + dp[l - 1][r][1]) * (n - len) % p) % p;
            }
        }
    }
    std::vector<i64> g(n + 1, 1);
    for (int k = 0;k < n;++k) {
        for (int i = 0;i <= k;++i) {
            g[k] = g[k] * (n - k + std::min(i, k - i)) % p;
        }
    }
    std::vector<i64> ans(n + 1);
    for (int l = 1;l <= n;++l) {
        for (int r = l;r <= n;++r) {
            int len = r - l + 1;
            ans[len] = (ans[len] + g[r - l] * (dp[l][r][0] + dp[l][r][1]) % p) % p;
        }
    }
    for (int i = n;i >= 1;--i) {
        for (int j = i - 1;j >= 1;--j) {
            ans[j] = ((ans[j] - ans[i] * (i - j + 1) % p) % p + p) % p;
        }
    }
    i64 ans0 = 1;
    for (int i = 1;i <= n;++i) {
        ans0 = ans0 * n % p;
    }
    for (int i = 1;i <= n;++i) {
        ans0 = ((ans0 - ans[i]) % p + p) % p;
    }
    ans[0] = ans0;
    for (int i = 0;i <= n;++i) {
        std::cout << ans[i] << " ";
    }
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