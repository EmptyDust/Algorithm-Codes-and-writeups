#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
using pt = std::pair<int, int>;

void solve2(int n) {
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

void solve() {
    int n;
    std::cin >> n;
    if (n < 500) {
        solve2(n);
        return;
    }
    std::vector<i64> nums(n);
    for (int i = 0;i < n;++i)std::cin >> nums[i];
    while (1) {
        for (int i = 0;i < n;++i) {
            int j = i == n - 1 ? 0 : i + 1;
            nums[j] = std::max((i64)0, nums[j] - nums[i]);
        }
        bool ok = true;
        for (int i = 0;i < n;++i) {
            int j = i == n - 1 ? 0 : i + 1;
            int k = j == n - 1 ? 0 : j + 1;
            int l = k == n - 1 ? 0 : k + 1;
            if (nums[i] && nums[j] && nums[k] && nums[l]) {
                ok = false;
                break;
            }
        }
        if (ok)break;
    }
    if (nums[0] && nums[1])nums[1] -= nums[0];
    for (int i = 0;i < n;++i) {
        int j = i == n - 1 ? 0 : i + 1;
        int k = j == n - 1 ? 0 : j + 1;
        if (nums[i] && nums[j] && nums[k]) {
            int cnt = nums[j] / nums[i];
            i64 sum = (nums[j] - nums[i] + nums[j] - cnt * nums[i]) * cnt / 2;
            if (sum >= nums[k])nums[k] = nums[j] = 0;
            else nums[j] = 0;
        }
    }
    for (int i = 0;i < n;++i) {
        int j = i == n - 1 ? 0 : i + 1;
        if (nums[i] && nums[j])nums[j] = 0;
    }
    std::vector<int> ans;
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