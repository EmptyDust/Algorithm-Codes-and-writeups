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
    std::vector<int> dp(5001, inf);
    int gcd = 0;
    for (auto& x : a) {
        std::cin >> x;
        gcd = std::__gcd(x, gcd);
        dp[x] = 0;
    }
    if (dp[gcd] == 0) {
        std::cout << n - std::count(a.begin(), a.end(), gcd);
        return;
    }
    std::vector<int> cur;
    for (int i = 5000;i >= 1;--i)if (dp[i] != inf) {
        for (int j : cur) {
            int g = std::__gcd(i, j);
            dp[g] = std::min(dp[g], dp[i] + 1);
            // if (g == 2)std::cout << i << " " << j << '\n';
        }
        if (dp[i] == 0) cur.push_back(i);
    }
    // for (int i = 1;i <= 50;++i)std::cout << dp[i] << ' ';
    std::cout << n - 1 + dp[gcd];
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