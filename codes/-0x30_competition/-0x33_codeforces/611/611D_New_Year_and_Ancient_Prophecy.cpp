#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

struct Mi64 {
    i64 value;
    Mi64() {}
    Mi64(i64 value) { this->value = value; }
    Mi64 operator * (const i64 w) {
        return value * w % mod;
    }
    Mi64 operator * (const Mi64 w) {
        return value * w.value % mod;
    }
    Mi64 operator + (const Mi64 w) {
        return (value + w.value) % mod;
    }
    Mi64 operator - (const Mi64 w) {
        return((value - w.value) % mod + mod) % mod;
    }
    bool operator == (const Mi64 w) {
        return value == w.value;
    }
};

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;std::cin >> n;
    std::string s;std::cin >> s;
    std::vector<std::vector<Mi64>> dp(n, std::vector<Mi64>(n + 2, 0));
    std::vector<std::vector<bool>> is_bigger(n, std::vector<bool>(n));
    for (int len = 1;len <= n;++len) {
        for (int i = 0;i < n;++i) {
            int j = i + len;
            int d = 0;
            while (j + d < n && s[i + d] == s[j + d])
                d++;
            if (j + d >= n)break;
            if (s[i + d] < s[j + d]) {
                for (int k = std::max(i, i + d - len + 1);k <= i + d;++k) {
                    is_bigger[k][len] = 1;
                    //if (i == 0 && j == 1)std::cout << k << ' ' << len << '\n';
                }
                //std::cout << i << ' ' << j << ' ' << d << '\n';
            }
            i += d;
        }
    }
    // for (int i = 0;i < n;++i) {
    //     for (int j = 0;j < n;++j) {
    //         std::cout << is_bigger[i][j] << ' ';
    //     }
    //     std::cout << std::endl;
    // }
    // std::cout << dp[n - 1][n].value << ' ';
    for (int i = n - 1;i >= 0;--i) {
        if (s[i] == '0')continue;
        for (int len = 1;len <= n;++len) {
            auto& cur = dp[i][len];
            int j = i + len;
            if (j == n) cur = 1;
            if (j + len > n)continue;
            if (is_bigger[i][len])cur = cur + dp[j][len];
            else cur = cur + dp[j][len + 1];
            // std::cout << i << ' ' << len << ' ' << cur.value << '\n';
        }
        for (int len = n;len >= 0;--len) {
            dp[i][len] = dp[i][len] + dp[i][len + 1];
        }
    }

    std::cout << dp[0][0].value;
    return 0;
}