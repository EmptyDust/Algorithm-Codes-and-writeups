#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pt = std::pair<int, int>;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for (int& x : nums)std::cin >> x;
    int ans = 1e9;
    for (int i = 1;i < n;++i) {
        ans = std::min(ans, std::max(nums[i], nums[i - 1]));
    }
    std::cout << ans - 1;
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