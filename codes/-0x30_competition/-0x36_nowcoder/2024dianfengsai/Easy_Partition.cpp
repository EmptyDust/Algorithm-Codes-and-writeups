#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a2 = std::array<i64, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n, k;std::cin >> n >> k;
    std::vector<i64> a(n);
    std::vector<a2> dp(n);
    for (i64& x : a)std::cin >> x;
    if (k == 1){
        std::cout << std::accumulate(a.begin(), a.end(), 0ll);
        return;
    }
    k--;
    for (int i = k;i < n;++i){
        dp[i][1] = std::max(dp[i - 1][1] + a[i], dp[i - k][0] + a[i]);
        dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1]);
    }
    // for (auto [x, y] : dp)std::cout << x << " " << y << '\n';
    i64 ans = std::max(dp.back()[0], dp.back()[1]);
    std::cout << ans;
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