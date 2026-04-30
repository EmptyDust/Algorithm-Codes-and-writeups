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

char score[5] = { 'n','a','r','e','k' };

void solve() {
    int n, m;std::cin >> n >> m;
    std::vector dp(5, -inf);
    std::vector check(26, 0);
    for (auto x : score)check[x - 'a'] = 1;
    dp[0] = 0;
    for (int _ = 0;_ < n;++_) {
        std::string s;std::cin >> s;
        std::vector ndp(dp);
        for (int i = 0;i < 5;++i) {
            if (dp[i] != -inf) {
                int ni = i;
                int res = dp[i];
                for (int k = 0;k < m;++k) {
                    if (s[k] == score[ni]) {
                        ni = (ni + 1) % 5;
                        res++;
                    }
                    else if (check[s[k] - 'a']) {
                        res--;
                    }
                }
                for (int j = ni;j >= 0;--j) {
                    ndp[j] = std::max(ndp[j], res);
                    res -= 2;
                }
            }
        }
        dp = ndp;
    }
    std::cout << dp[0];
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