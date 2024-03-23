#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    for (int i = 0;i < n;++i)std::cin >> nums[i];
    std::sort(nums, nums + n);
    i64 ans1 = 0, ans2 = 0, pre1 = nums[0], pre2 = nums[0];
    for (int i = 1;i < n;++i) {
        if (ans1 > ans2) {
            ans2 += 1LL * (pre2 - nums[i]) * (pre2 - nums[i]);
            pre2 = nums[i];
        }
        else {
            ans1 += 1LL * (pre1 - nums[i]) * (pre1 - nums[i]);
            pre1 = nums[i];
        }
    }
    i64 ans = ans1 + ans2 + (pre1 - pre2) * (pre1 - pre2);
    std::cout << ans;
    return 0;
}