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
    std::string s;std::cin >> s;
    i64 ans = 0;
    for (int i = n;i <= 3 * n;++i)if (i != 2 * n) {
        std::vector dp(4 * n + 1, std::vector<i64>(4 * n + 1));
        dp[i][2 * n] = 1;
        for (int j = 0;j < n;++j) {
            std::vector ndp(4 * n + 1, std::vector<i64>(4 * n + 1));
            for (int x = n - j;x <= 3 * n + j;++x) {
                for (int y = 2 * n - j;y <= 2 * n + j;++y) {
                    if (x < 4 * n) if (s[j + n] != 'L') {
                        if (y < 4 * n) if (s[j] != 'L') {
                            ndp[x + 1][y + 1] = (ndp[x + 1][y + 1] + dp[x][y]) % mod;
                        }
                        if (y > 0) if (s[j] != 'R') {
                            ndp[x + 1][y - 1] = (ndp[x + 1][y - 1] + dp[x][y]) % mod;
                        }
                    }
                    if (x > 0) if (s[j + n] != 'R') {
                        if (y < 4 * n) if (s[j] != 'L') {
                            ndp[x - 1][y + 1] = (ndp[x - 1][y + 1] + dp[x][y]) % mod;
                        }
                        if (y > 0) if (s[j] != 'R') {
                            ndp[x - 1][y - 1] = (ndp[x - 1][y - 1] + dp[x][y]) % mod;
                        }
                    }
                }
            }
            for (int x = 0;x <= 4 * n;++x) {
                ndp[x][x] = 0;
            }
            dp = ndp;
        }
        for (int x = 0;x <= 4 * n;x++) {
            ans = (ans + dp[x][i]) % mod;
        }
    }
    std::cout << ans;
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