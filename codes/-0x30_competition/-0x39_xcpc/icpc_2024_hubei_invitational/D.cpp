#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e4 + 10, inf = 1e9, mod = 1e9 + 7;
i64 nums[MAXN], sums[MAXN], n;
i64 ans[MAXN][MAXN];
using pt = std::pair<int, int>;
using a3 = std::array<int, 3>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    for (i64 i = 1;i <= n;++i) {
        std::cin >> nums[i];
        ans[i][0] = nums[i];//pos time
    }
    for (i64 i = 1;i <= n;++i)sums[i] = sums[i - 1] + nums[i];
    for (i64 t = 1;t <= 2 * n;++t) {
        for (i64 i = 1;i <= n;++i) {
            ans[i][t] = std::max(
                {
                    ans[i - 1][t - 1],
                    ans[i + 1][t - 1],
                    sums[std::min(i + t, n)] - sums[i - 1],
                    sums[i] - sums[std::max((i64)0,i - t - 1)]
                });
        }
    }
    i64 res = 0;
    for (i64 i = 1;i <= n;++i) {
        i64 tmp = 0;
        for (i64 t = 1;t <= 2 * n;++t) {
            tmp ^= t * ans[i][t];
            //std::cout << ans[i][t] << ' ';
        }
        res ^= tmp + i;
        //std::cout << '\n';
    }
    std::cout << res;
    return 0;
}

