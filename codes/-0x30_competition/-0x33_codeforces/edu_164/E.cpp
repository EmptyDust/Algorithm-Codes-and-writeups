#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;std::cin >> n;
    std::vector<i64> nums(n + 1);
    for (int i = 1;i <= n;++i)std::cin >> nums[i];
    int max = *std::max_element(nums.begin(), nums.end());
    std::vector<i64> f(max + 1), f2(max + 2);
    int sqrt = std::sqrt(max);
    auto cal = [&](int x, int p) {
        if (x == 0)return 0;
        if (p == 0)return max + 1;
        return (x - 1) / p + 1;
        };
    for (int i = 1;i <= sqrt;++i) {
        for (int j = 1;j <= n;++j)if (nums[j] > nums[j - 1]) {
            f[i] += cal(nums[j], i) - cal(nums[j - 1], i);
        }
    }
    for (int j = 1;j <= n;++j)if (nums[j] > nums[j - 1]) {
        for (int i = 1;i <= sqrt + 1;++i) {
            int l = cal(nums[j], i), r = cal(nums[j], i - 1);
            f2[l] += i;
            f2[r] -= i;
        }
        for (int i = 1;i <= sqrt + 1;++i) {
            int l = cal(nums[j - 1], i), r = cal(nums[j - 1], i - 1);
            f2[l] -= i;
            f2[r] += i;
        }
    }
    for (int i = 1;i <= max;++i) {
        f2[i] += f2[i - 1];
        if (i > sqrt)f[i] = f2[i];
        std::cout << f[i] << ' ';
    }
    return 0;
}