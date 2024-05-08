#include <bits/stdc++.h>
using i64 = long long;
#define int long long
constexpr int MAXN = 3e5 + 10, inf = 1e18, mod = 1e9 + 7;
int nums[MAXN], pre[MAXN][12], suf[MAXN][12], n;
using pt = std::pair<int, int>;

void solve() {
    int n, k;
    std::cin >> n >> k;
    for (int i = 1;i <= n;++i)std::cin >> nums[i];
    for (int i = 1;i <= n + 9;++i)for (int x = 0;x < 12;++x) {
        pre[i][x] = suf[i][x] = 0;
    }
    std::vector<pt> ops;
    for (int s = 1;s <= k;++s) {
        for (int i = 1;i <= n;++i)for (int t = 1;t <= s + 1;++t) {
            int min = inf;
            int r = i + t;
            if (r > n + 1)continue;
            for (int j = i;j < i + t;++j) {
                min = std::min(nums[j], min);
            }
            int res = 0;
            for (int j = i;j < i + t;++j) {
                res += nums[j] - min;
            }
            //if (s == 1 && i == 3 && t == 2)std::cout << res << ' ';
            pre[r][s] = std::max(pre[r][s], res + pre[i][s - t + 1]);
        }
        for (int i = 1;i <= n + 1;++i) {
            pre[i][s] = std::max(pre[i][s], pre[i - 1][s]);
            pre[i][s] = std::max(pre[i][s], pre[i][s - 1]);
        }
    }
    //for (int i = 1;i <= n + 1;++i)std::cout << pre[i][2] << ' ';
    i64 ans = 0;
    for (int i = 1;i <= n + 1;++i) {
        ans = std::max(ans, pre[i][k]);
    }
    std::cout << std::accumulate(nums + 1, nums + n + 1, (i64)0) - ans;
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