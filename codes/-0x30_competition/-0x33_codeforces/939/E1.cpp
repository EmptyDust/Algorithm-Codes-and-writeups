#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
using pt = std::pair<int, int>;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for (int i = 0;i < n;++i)std::cin >> nums[i];
    while (1) {
        for (int i = 0;i < n;++i) {
            int j = i == n - 1 ? 0 : i + 1;
            nums[j] = std::max(0, nums[j] - nums[i]);
        }
        bool ok = true;
        for (int i = 0;i < n;++i) {
            int j = i == n - 1 ? 0 : i + 1;
            int k = j == n - 1 ? 0 : j + 1;
            if (nums[i] && nums[j] && nums[k]) {
                ok = false;
                break;
            }
        }
        if (ok)break;
    }
    std::vector<int> ans;
    for (int i = 0;i < n;++i)if (nums[i] && nums[(i + 1) % n])nums[(i + 1) % n] = 0;
    for (int i = 0;i < n;++i)if (nums[i])ans.push_back(i + 1);
    std::cout << ans.size() << '\n';
    for (int x : ans)std::cout << x << ' ';
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