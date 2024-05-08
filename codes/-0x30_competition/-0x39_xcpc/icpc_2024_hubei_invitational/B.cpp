#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
i64 nums[MAXN], n;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    for (int i = 0;i < n;++i)std::cin >> nums[i];
    i64 sum = std::accumulate(nums, nums + n, (i64)0);
    //std::cout << sum << ' ';
    i64 ans = 0;
    for (int s = 29;s >= 0;--s)if (sum >= ((i64)1 << s) * n) {
        ans |= (i64)1 << s;
        sum -= ((i64)1 << s) * n;
    }
    if (sum > 0) {
        for (int s = 0;s < 30;s++)if (!(ans >> s & 1)) {
            if ((n - sum) % ((i64)1 << s)) {
                ans++;
            }
            break;
        }
        ans++;
    }
    std::cout << ans;
    return 0;
}