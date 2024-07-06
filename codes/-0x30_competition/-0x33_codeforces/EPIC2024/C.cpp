#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n;std::cin >> n;
    std::vector<i64> nums(n + 1), b(n + 2);b[n] = 0;
    for (int i = 1;i <= n;++i)std::cin >> nums[i];
    i64 ans = nums.back();
    for (int i = n - 1;i >= 1;--i) {
        i64 c = nums[i + 1] - nums[i];
        b[i] = std::max((i64)0, b[i + 1] + c + 1);
        ans = std::max(ans, b[i] + nums[i]);
    }
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
