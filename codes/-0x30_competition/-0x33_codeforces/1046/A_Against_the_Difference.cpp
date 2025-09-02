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
    std::vector<int> a(n);
    std::vector g(n, std::vector<int>());
    std::vector<int> next(n, -1), dp(n + 1, 0);
    for (int i = 0;i < n;++i) {
        int& x = a[i];
        std::cin >> x, x--;
        g[x].push_back(i);
    }
    for (int i = 0;i < n;++i) {
        for (int j = i;j < g[i].size();++j) {
            next[g[i][j - i]] = g[i][j] + 1;
        }
    }
    for (int i = 0;i < n;++i) {
        if (i)dp[i] = std::max(dp[i - 1], dp[i]);
        if (next[i] != -1)dp[next[i]] = std::max(dp[next[i]], dp[i] + a[i] + 1);
    }
    dp[n] = std::max(dp[n], dp[n - 1]);
    std::cout << dp[n];
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