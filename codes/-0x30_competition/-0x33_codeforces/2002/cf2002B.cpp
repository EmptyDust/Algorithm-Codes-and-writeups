#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n;std::cin >> n;
    std::vector<int> nums(n);
    for (int& x : nums)std::cin >> x;
    std::vector<int> use;
    for (int i = 1;i < n;++i) {
        if (nums[i] < nums[i - 1]) {
            use.push_back(nums[i - 1] - nums[i]);
            nums[i] = nums[i - 1];
        }
    }
    if (use.empty()) {
        std::cout << 0;
        return;
    }
    std::sort(use.begin(), use.end());

    i64 ans = use.back() + std::accumulate(use.begin(), use.end(), (i64)0);
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