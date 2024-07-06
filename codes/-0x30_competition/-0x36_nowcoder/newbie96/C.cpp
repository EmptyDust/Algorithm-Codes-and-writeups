#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    i64 n;std::cin >> n;
    std::vector<i64> nums(n + 2, 0), pre(n + 2, 0), suf(n + 2, 0);
    for (int i = 1;i <= n;++i)
        std::cin >> nums[i];
    for (int i = n;i;--i)
        suf[i] = suf[i + 1] + nums[i];
    for (int i = 1;i <= n;++i)
        pre[i] = pre[i - 1] + nums[i];
    i64 ans = 0;
    for (int j = 2, i = 0;j < n;++j) {
        while (pre[i + 1] < (pre[j] + 1) / 2 && suf[j + 1] < pre[j] - pre[i + 1])i++;
        ans += i;
        //std::cout << i << ' ' << j << ' ' << ans << '\n';
    }
    std::cout << ans;
    return 0;
}