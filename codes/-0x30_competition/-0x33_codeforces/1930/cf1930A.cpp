#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    std::cin >> n;
    for (int i = 0;i < 2 * n;++i)std::cin >> nums[i];
    std::sort(nums, nums + 2 * n);
    int sum = 0;
    for (int i = 0;i < 2 * n;i += 2)sum += nums[i];
    std::cout << sum;
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