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

// std::vector dp(M + 1, std::vector<std::vector<a3>>(M + 1, std::vector<a3>(M + 1, { 1,1,1 })));
// std::vector ndp(M + 1, std::vector<std::vector<a3>>(M + 1, std::vector<a3>(M + 1)));

#define inv(x) qpow(x,mod-2)

std::vector<a3> a3s;

std::vector<a3> dp(4590551, { 1,1,1 }), ndp(4590551);

std::vector pos(M + 1, std::vector<int>(M + 1));


std::vector<int> _pos;
int ys(int a, int b, int c) {
    return pos[a][b] + c;
}


void solve() {
    // int cnt = 4590551 * 300 * 3;
    // int eps = 3e8;
    // std::cout << (eps - cnt);
    int n, Q;std::cin >> n >> Q;
    std::string s;//(300, '?');
    std::cin >> s;
    s = '&' + s;
    // int cnt = 0;
    for (int i = 1;i <= n;++i) {
        for (int j = 0;j < 4590551;++j) {
            auto& [a, b, c] = a3s[j];
            if (s[i] == '?') {
                if (a)ndp[j][0] = (ndp[j][0] + dp[ys(a - 1, b, c)][1] + dp[ys(a - 1, b, c)][2]) % mod;
                if (b)ndp[j][1] = (ndp[j][1] + dp[ys(a, b - 1, c)][0] + dp[ys(a, b - 1, c)][2]) % mod;
                if (c)ndp[j][2] = (ndp[j][2] + dp[ys(a, b, c - 1)][0] + dp[ys(a, b, c - 1)][1]) % mod;
            }
            if (s[i] == 'a') {
                ndp[j][0] = (ndp[j][0] + dp[j][1] + dp[j][2]) % mod;
            }
            if (s[i] == 'b') {
                ndp[j][1] = (ndp[j][1] + dp[j][0] + dp[j][2]) % mod;
            }
            if (s[i] == 'c') {
                ndp[j][2] = (ndp[j][2] + dp[j][0] + dp[j][1]) % mod;
            }
        }

        for (int j = 0;j < 4590551;++j) {
            dp[j][0] = ndp[j][0];
            dp[j][1] = ndp[j][1];
            dp[j][2] = ndp[j][2];
            ndp[j][0] = 0;
            ndp[j][1] = 0;
            ndp[j][2] = 0;
        }
    }
    // std::cout << cnt;
    i64 inv2 = inv(2);
    while (Q--) {
        int x, y, z;std::cin >> x >> y >> z;
        int id = ys(x, y, z);
        i64 ans = (dp[id][0] + dp[id][1] + dp[id][2]) % mod * inv2 % mod;
        std::cout << ans << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;

    // int cnt = 0;
    for (int a = 0;a <= M;++a) {
        for (int b = 0;a + b <= M;++b) {
            pos[a][b] = a3s.size();
            for (int c = 0;a + b + c <= M;++c) {
                a3s.push_back({ a,b,c });
                // cnt++;
            }
        }
    }
    // std::cout << cnt;

    while (t--) {
        solve();
    }
    // std::cout << "end";
    return 0;
}