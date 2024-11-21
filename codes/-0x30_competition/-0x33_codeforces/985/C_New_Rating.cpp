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

int cmp(int x, int a) {
    if (x == -1)return 0;
    if (x > a)return -1;
    return x < a;
}

void solve() {
    int n;std::cin >> n;
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    std::vector<a3> dp(n + 1, { -1,-1,-1 });
    dp[0][0] = 0;
    for (int i = 1;i <= n;++i) {
        dp[i][0] = dp[i - 1][0] + cmp(dp[i - 1][0], a[i - 1]);
        dp[i][1] = dp[i - 1][1];
        dp[i][2] = dp[i - 1][2];
        for (int j = 1;j < 3;++j)
            dp[i][j] = std::max(dp[i][j], dp[i - 1][j - 1]);
        dp[i][2] = dp[i][2] + cmp(dp[i][2], a[i - 1]);
        // for (int j = 0;j < 3;++j)
        //     std::cout << dp[i][j] << " ";std::cout << std::endl;
    }
    std::cout << ranges::max(dp[n][1], dp[n][2]);
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