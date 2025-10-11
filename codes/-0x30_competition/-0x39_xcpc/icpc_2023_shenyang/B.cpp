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
const i64 inf = 2e18;
// const int mod = 1e9 + 7;
const int mod = 998244353;

i64 cal(std::vector<int> a, int n) {
    std::vector<int> b(n + 1);
    int f = -1;
    for (int i = 1;i <= n;++i) if (a[i]) {
        b[a[i]] = i;
        if (f == -1) f = a[i] % 2;
    }
    std::vector dp(n + 1, std::vector<i64>(n + 2));
    dp[0][0] = 1;
    for (int i = 1, t = 0;i <= n;++i) {
        if (b[i] != 0) {
            if (f == i % 2) {
                dp[i][0] += dp[i - 1][0];
            }
            else {
                if (i == 1 || (b[i - 1] && b[i] > b[i - 1])) {
                    dp[i][0] += dp[i - 1][0];
                }
            }
        }
        else {
            t++;
            if (f == i % 2) {
                if (i == 1) dp[1][1] = 1;
                for (int j = 1;j < t;++j) {
                    dp[i][j] += dp[i - 1][j];
                }
            }
            else {
                for (int j = 1;j <= t;++j) {
                    dp[i][j] += dp[i - 1][j - 1];
                }
            }
        }
        if (i < n) {
            if (f != i % 2) {
                for (int j = t;j >= 0;--j) {
                    dp[i][j] += dp[i][j + 1];
                }
            }
            else {
                for (int j = 1;j <= t + 1;++j) {
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }
        for (int j = 0;j <= t + 1;++j) {
            if (dp[i][j] >= 1e18) return 1e18;
        }
    }
    i64 ret = 0;
    for (auto x : dp[n]) {
        ret += x;
        ret = std::min(ret, (i64)1e18 + 10);
    }
    return ret;
}

void solve() {
    int n;i64 k;std::cin >> n >> k;
    std::vector<int> b(n + 2);
    std::vector<int> a(n + 1);
    for (int i = 1;i <= n;++i) {
        for (int j = 1;j <= n + 1;++j) if (!b[j]) {
            if (j == n + 1) {
                std::cout << -1;
                return;
            }
            a[i] = j;
            b[j] = 1;
            i64 res = cal(a, n);
            if (res >= k) break;
            k -= res;
            b[j] = 0;
        }
    }
    for (int i = 1;i <= n;++i)std::cout << a[i] << ' ';
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