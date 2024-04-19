#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
using pt = std::pair<int, int>;

void solve() {
    i64 n, m, k;
    std::cin >> n >> m >> k;
    std::vector<i64> nums(n);
    for (auto& num : nums)std::cin >> num;
    std::sort(nums.begin(), nums.end());
    i64 ans = (k - k % m - m) * (k / m) / 2 * m + k % m * (k / m) * m;
    // 1ll * (k % m) * (k / m + 1)
    i64 sum = 0;
    for (int i = 0;i < k / m;++i) {
        sum += nums[i];
    }
    ans += sum * m;
    if (k % m)
        ans += k % m * nums[k / m];
    std::cout << ans;
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