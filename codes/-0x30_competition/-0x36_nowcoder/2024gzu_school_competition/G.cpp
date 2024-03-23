#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
i64 nums[MAXN], n;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    for (int i = 0;i < n;++i)std::cin >> nums[i];
    i64 def = 0, res = 0, cur = 0;
    for (int i = 0;i < n;++i) {
        if (cur <= nums[i] + def) {
            res += nums[i] + def - cur + 1;
            cur += nums[i] + def - cur + 1;
        }
        def = (nums[i] + 1) / 2;
        cur += nums[i] / 2;
    }
    std::cout << res;
    return 0;
}