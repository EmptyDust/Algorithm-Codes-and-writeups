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
    int l, n, m;std::cin >> l >> n >> m;
    std::vector<int> a(l + 1);
    std::vector b(n + 1, std::vector<int>(m + 1));
    for (int i = 1;i <= l;++i)
        std::cin >> a[i];
    for (int i = 1;i <= n;++i)
        for (int j = 1;j <= m;++j)
            std::cin >> b[i][j];
    std::vector p(n * m + 1, std::vector<pii>());
    for (int j = 1;j <= m;++j) {
        std::map<int, int> mp;
        for (int i = 1;i <= n;++i) {
            mp[b[i][j]] = i;
        }
        for (auto [t, x] : mp) {
            p[t].push_back({ x,j });
        }
    }
    std::vector<int> dp(m + 1, -1);
    for (int i = l;i >= 1;--i) {
        std::vector<int> ndp(m + 1, -1);
        for (auto [x, y] : p[a[i]]) {
            if (x > dp[y]) {
                ndp[y - 1] = x - 1;
            }
        }
        for (int j = m - 1;j >= 0;--j) {
            ndp[j] = std::max(ndp[j], ndp[j + 1]);
        }
        dp = ndp;
    }
    std::cout << (dp[0] >= 0 ? "T" : "N");
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