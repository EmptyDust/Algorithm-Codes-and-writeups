#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, k;std::cin >> n >> k;
    std::vector<std::vector<int>> map(n + 1, std::vector<int>(n + 1));
    for (int i = 1;i <= n;++i)for (int j = 1;j <= n;++j) {
        std::cin >> map[i][j];
    }

    int l = 1, r = 1e9, ans;
    auto check = [&](auto x)->bool {
        std::vector<std::vector<int>> vis(n + 1, std::vector<int>(n + 1));
        std::vector<std::vector<int>> sum(n + 1, std::vector<int>(n + 1));
        for (int i = 1;i <= n;++i)for (int j = 1;j <= n;++j) {
            vis[i][j] = (map[i][j] >= x);
        }
        for (int i = 1;i <= n;++i)for (int j = 1;j <= n;++j) {
            sum[i][j] = vis[i][j];
            sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
        int cnt = 0;
        for (int i = k;i <= n;++i)for (int j = k;j <= n;++j) {
            int cur = sum[i][j] - sum[i - k][j] - sum[i][j - k] + sum[i - k][j - k];
            cnt += (cur >= k * k / 2 + 1);
        }
        return cnt == (n - k + 1) * (n - k + 1);
        };
    while (l <= r) {
        auto mid = l + r >> 1;
        // std::cout << mid << ' ' << check(mid) << '\n';
        if (check(mid))l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    std::cout << ans;
    return 0;
}