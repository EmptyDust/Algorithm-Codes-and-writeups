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
const int mod = 1e9 + 7;
// const int mod = 998244353;

std::vector<i64> dp(1e7 + 10);
void init() {
    dp[0] = dp[1] = 1;
    for (int i = 2;i <= 1e7;++i) {
        dp[i] = (1 + dp[i - 2] * (i * (i - 1) / 2)) % mod;
    }
}

// void solve() {
//     int n;std::cin >> n;
// }

// f(k) = k * (k - 1) / 2;
// g(k, x) = C(f(k), 2) * C(f(k - 1), 2) * ... * C(f(k - x), 2)
// 1 + g(k, 0) / 1! + g(k, 1) / 2! + g(k, x) / x!

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    init();
    for (int i = 1;i <= 10;++i)std::cout << dp[i] << ' ';
    // int t;std::cin >> t;
    // while (t--) {
    //     solve();
    //     std::cout << '\n';
    // }
    return 0;
}