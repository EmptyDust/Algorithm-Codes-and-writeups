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
    std::sort(nums, nums + n, [&](int a, int b) {
        if (a % 2 == 0 && b % 2 == 1)return false;
        if (a % 2 == 1 && b % 2 == 0)return true;
        return a < b;
        });
    for (int i = 0;i < n;++i)std::cout << nums[i] << ' ';
    return 0;
}