#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    std::vector<i64> nums(n * 2 - 1);
    int o = 0;
    for (auto& num : nums) {
        std::cin >> num;
        if (num < 0) {
            num = -num;
            o++;
        }
    }
    std::sort(nums.begin(), nums.end());
    i64 ans = std::accumulate(nums.begin(), nums.end(), 0);
    if (n % 2 == 0 && o % 2) {
        ans -= nums[0] * 2;
    }
    std::cout << ans << ' ';
    return 0;
}