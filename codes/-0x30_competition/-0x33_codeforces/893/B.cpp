#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
using pt = std::pair<int, int>;

// k = 4
// 1 5 12 14
// 1 5 9 12 14
// 1 5 9 13 14

i64 cal(i64 x, int p) {
    return (x - 1) / p;
}

void solve() {
    int n, m, k;std::cin >> n >> m >> k;
    std::vector<i64> nums(m + 2);
    nums[0] = 1 - k, nums[m + 1] = n + 1;
    for (int i = 1;i <= m;++i)std::cin >> nums[i];
    int res = 0, ans = m, minus = 0;
    for (int i = 1;i <= m;++i) {
        int x = cal(nums[i] - nums[i - 1], k) + cal(nums[i + 1] - nums[i], k) + 1 - cal(nums[i + 1] - nums[i - 1], k);
        if (x >= minus) {
            if (x == minus)
                res++;
            else {
                minus = x;
                res = 1;
            }
        }
    }
    for (int i = 1;i <= m + 1;++i) {
        ans += cal(nums[i] - nums[i - 1], k);
    }
    ans -= minus;
    std::cout << ans << ' ' << res;
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
