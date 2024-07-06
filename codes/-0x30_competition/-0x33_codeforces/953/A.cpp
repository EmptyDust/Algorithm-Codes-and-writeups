#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int n;
using pii = std::pair<int, int>;

void solve() {
    std::cin >> n;
    std::vector<int> nums(n);
    for (int i = 0;i < n;++i)std::cin >> nums[i];
    int ans = nums[n - 1];
    ans += *std::max_element(nums.begin(), nums.end() - 1);
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