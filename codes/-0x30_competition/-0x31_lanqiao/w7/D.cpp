#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
i64 nums[MAXN];
int n;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    for (int i = 0;i < n;++i)std::cin >> nums[i];
    std::sort(nums, nums + n);
    std::map<i64, int> mp;
    i64 ans = 0;
    for (int i = 0;i < n;++i) {
        i64 x = (i64)1 << (std::__lg(nums[i]) + 1);
        x -= nums[i];
        ans += mp[x];
        mp[nums[i]]++;
    }
    std::cout << ans;
    return 0;
}