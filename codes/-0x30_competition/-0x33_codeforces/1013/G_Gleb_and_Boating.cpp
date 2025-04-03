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

// 23   9        18 
//      1        10
//      8 15 22  17 24


void solve() {
    int s, k;std::cin >> s >> k;
    int m = std::min(s, k * k);
    std::vector<int> dp(m + 1);dp[0] = 1;
    for (int i = k;i >= 2;--i) {
        if (i % 2 == k % 2) {
            for (int j = m;j >= i;--j) {
                dp[j] = dp[j - i];
            }
            for (int j = 0;j < i;++j) {
                dp[j] = 0;
            }
            for (int j = i;j <= m - i;++j) if (dp[j]) {
                dp[j + i] = 1;
            }
            for (int j = s % i;j <= m;j += i) if (dp[j]) {
                std::cout << i;
                return;
            }
        }
        else {
            for (int j = 0;j <= m - i;++j) {
                dp[j] = dp[j + i];
            }
            for (int j = m;j > m - i;--j) {
                dp[j] = 0;
            }
            for (int j = m - i;j >= i;--j) if (dp[j]) {
                dp[j - i] = 1;
            }
        }
        // for (int j = 0;j <= m;++j)std::cout << dp[j] << ' ';
        // std::cout << '\n';
    }
    std::cout << 1;
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