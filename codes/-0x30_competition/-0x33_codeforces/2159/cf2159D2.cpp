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

const int MC = 128;

void solve() {
    int n;std::cin >> n;
    std::vector<i64> a(n + 1);
    for (int i = 0;i < n;++i) std::cin >> a[i];
    std::vector<i64> b;
    std::vector dp(n, std::vector<int>(MC + 1));
    i64 ans = 0;
    for (int i = 0;i < n;++i) {
        while (b.size() && a[b.back()] >= a[i]) b.pop_back();
        b.push_back(i);
        auto cmp = [&](int ii, int jj) {
            return a[ii] < a[jj];
            };
        for (int k = 0;k <= MC;++k) dp[i][k] = i;
        for (int j = 1;j <= 3;++j) {
            a[n] = (a[i] - 1) / j + 1;
            auto it = std::lower_bound(b.begin(), b.end(), n, cmp);
            if (it == b.begin()) {
                for (int k = j;k <= MC;++k) {
                    dp[i][k] = -1;
                }
                break;
            }
            int p = *(--it);
            dp[i][j] = std::min(dp[i][j], p);
            for (int k = j + 1;k <= MC;++k) {
                dp[i][k] = std::min(dp[i][k], dp[p][k - j]);
            }
        }
        for (int k = 1;k <= MC;++k) {
            ans += (dp[i][k - 1] - dp[i][k]) * k;
        }
    }
    std::cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}