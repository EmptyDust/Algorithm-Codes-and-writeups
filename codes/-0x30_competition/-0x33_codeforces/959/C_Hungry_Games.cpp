#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n, x;std::cin >> n >> x;
    i64 ans = 1ll * n * (n + 1) / 2;
    std::vector<i64> a(n + 10), dp(n + 10), sum(n + 10);
    for (int i = 1;i <= n;++i)std::cin >> a[i];
    for (int r = 1, l = 0;r <= n;++r) {
        sum[r] = sum[r - 1] + a[r];
        i64 cnt = 0;
        while (sum[r] - sum[l] > x) {
            cnt += dp[l + 1] + 1;
            l++;
            // if (r == 3)std::cout << l << ' ' << cnt << '\n';
        }
        dp[r + 1] += cnt;
        ans -= cnt;
        // std::cout << r << ' ' << cnt << '\n';
    }
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