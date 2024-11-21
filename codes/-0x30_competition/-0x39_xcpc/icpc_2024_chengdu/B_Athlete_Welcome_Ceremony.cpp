#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<i64, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const int mod = 1e9 + 7;
// const int mod = 998244353;

const int M = 300;

i64 qpow(i64 x, i64 p) {
    i64 ret = 1;
    while (p) {
        if (p & 1)ret = ret * x % mod;
        p >>= 1;
        x = x * x % mod;
    }
    return ret;
}

std::vector dp(M + 1, std::vector<a3>(M + 1));
std::vector ndp(M + 1, std::vector<a3>(M + 1));

std::vector presum(M + 1, std::vector<i64>(M + 1));

#define inv(x) qpow(x,mod-2)

void solve() {
    // int cnt = 4590551 * 300 * 3;
    // int eps = 3e8;
    int n, Q;std::cin >> n >> Q;
    std::string s;//(300, '?');
    std::cin >> s;
    int cnt = std::count(s.begin(), s.end(), '?');
    s = '&' + s;
    if (s[1] == '?') {
        dp[1][0][0] = 1;
        dp[0][1][1] = 1;
        dp[0][0][2] = 1;
    }
    else if (s[1] == 'a') {
        dp[0][0][0] = 1;
    }
    else if (s[1] == 'b') {
        dp[0][0][1] = 1;
    }
    else if (s[1] == 'c') {
        dp[0][0][2] = 1;
    }
    for (int i = 2;i <= n;++i) {
        for (int a = 0;a <= M;++a) {
            for (int b = 0;a + b <= M;++b) {
                if (s[i] == '?') {
                    if (a)ndp[a][b][0] = (dp[a - 1][b][1] + dp[a - 1][b][2]) % mod;
                    if (b)ndp[a][b][1] = (dp[a][b - 1][0] + dp[a][b - 1][2]) % mod;
                    ndp[a][b][2] = (dp[a][b][0] + dp[a][b][1]) % mod;
                }
                if (s[i] == 'a') {
                    ndp[a][b][0] = (dp[a][b][1] + dp[a][b][2]) % mod;
                }
                if (s[i] == 'b') {
                    ndp[a][b][1] = (dp[a][b][0] + dp[a][b][2]) % mod;
                }
                if (s[i] == 'c') {
                    ndp[a][b][2] = (dp[a][b][0] + dp[a][b][1]) % mod;
                }
            }
        }
        for (int a = 0;a <= M;++a) {
            for (int b = 0;a + b <= M;++b) {
                dp[a][b][0] = ndp[a][b][0];
                dp[a][b][1] = ndp[a][b][1];
                dp[a][b][2] = ndp[a][b][2];
                ndp[a][b][0] = 0;
                ndp[a][b][1] = 0;
                ndp[a][b][2] = 0;
            }
        }
        // if (i == 1)std::cout << dp[1][0][0] << ' ';
    }


    for (int a = 0;a <= M;++a) {
        for (int b = 0;b <= M;++b) {
            presum[a][b] = (dp[a][b][0] + dp[a][b][1] + dp[a][b][2]) % mod;
            if (a) presum[a][b] = (presum[a][b] + presum[a - 1][b]) % mod;
            if (b) presum[a][b] = (presum[a][b] + presum[a][b - 1]) % mod;
            if (a && b) presum[a][b] = ((presum[a][b] - presum[a - 1][b - 1]) % mod + mod) % mod;
        }
    }

    // i64 inv2 = inv(2);

    while (Q--) {
        int a, b, c;std::cin >> a >> b >> c;
        int free = a + b - cnt + c;
        // std::cout << cnt << ' ' << free << '\n';
        i64 ans = presum[a][b];
        // std::cout << presum[a][b] << ' ';
        for (int x = a - free - 1, y = b;x <= a;++x, --y) {
            if (x >= 0 && y >= 0)
                ans = ((ans - presum[x][y]) % mod + mod) % mod;
        }
        for (int x = a - free - 1, y = b - 1;x < a;++x, --y) {
            if (x >= 0 && y >= 0)
                ans = (ans + presum[x][y]) % mod;
        }
        // ans = (ans * inv2) % mod;
        std::cout << ans << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    // std::cout << "end";
    return 0;
}