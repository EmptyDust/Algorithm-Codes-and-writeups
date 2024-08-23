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
    int n, m;std::cin >> n >> m;// n:black m:white
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));
    for (int i = 1;i <= n;++i)for (int j = 0;j <= m;++j) {
        dp[i][j] = 0;
        if (i && !dp[i - 1][j])dp[i][j] = 1;
        if (j && !dp[i][j - 1])dp[i][j] = 1;
    }
    std::cout << dp[n][m] << ' ';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}