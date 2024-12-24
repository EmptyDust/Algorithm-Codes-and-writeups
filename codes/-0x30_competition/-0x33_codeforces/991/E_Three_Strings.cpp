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
    std::string a, b, c;std::cin >> a >> b >> c;
    int n = a.length();
    int m = b.length();
    a = '*' + a;
    b = '*' + b;
    c = '*' + c;
    std::vector dp(n + 1, std::vector<int>(m + 1, inf));
    dp[0][0] = 0;
    for (int i = 0;i <= n;++i) {
        for (int j = 0;j <= m;++j) {
            if (i)dp[i][j] = std::min(dp[i][j], dp[i - 1][j] + (a[i] != c[i + j]));
            if (j)dp[i][j] = std::min(dp[i][j], dp[i][j - 1] + (b[j] != c[i + j]));
        }
    }
    std::cout << dp[n][m];
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