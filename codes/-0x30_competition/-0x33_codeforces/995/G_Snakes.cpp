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
    int n, q;std::cin >> n >> q;
    std::vector adj(n, std::vector<int>(n));
    std::vector<pii> info(q);
    std::vector<int> len(n);
    for (auto& [a, b] : info) {
        char B;std::cin >> a >> B;a--;
        b = B == '+';
        if (b)len[a]++;
    }
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < n;++j) {
            if (i == j)continue;
            int Li = 0, Ri = 0;
            int Lj = 1, Rj = 1;
            adj[i][j]++;
            for (auto [a, b] : info) {
                if (a == i && b) {
                    Ri++;
                }
                if (a == j && !b) {
                    Lj++;
                }
                if (Ri == Lj) {
                    adj[i][j]++;
                    Lj++;
                }
            }
        }
    }
    std::vector dp(n, std::vector<i64>(1 << n, 1e18));
    for (int i = 0;i < n;++i) {
        dp[i][1 << i] = 1;
    }
    for (int i = 0; i < 1 << n; i++)
        for (int s = 0;s < n;++s)
            if (i >> s & 1)
                for (int t = 0; t < n; t++)
                    if (!(i >> t & 1))
                        dp[t][i | 1 << t] = std::min(dp[t][i | 1 << t], dp[s][i] + adj[s][t]);
    i64 ans = 1e18;
    for (int i = 0;i < n;++i) {
        ans = std::min(ans, dp[i][(1 << n) - 1] + len[i]);
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