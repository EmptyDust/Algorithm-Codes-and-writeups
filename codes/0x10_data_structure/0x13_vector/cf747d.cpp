#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n, k;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> k;
    for (int i = 0;i < n;++i)std::cin >> nums[i];
    std::vector<int> use;
    for (int i = 0;i < n;++i)if (nums[i] < 0)
        use.push_back(i);
    if (use.empty()) {
        std::cout << 0;
        return 0;
    }
    if (use.size() > k) {
        std::cout << -1;
        return 0;
    }
    int ans = use.size() * 2;
    k -= use.size();
    std::vector<int> minus;
    for (int i = 1;i < use.size();++i) {
        minus.push_back(use[i] - use[i - 1] - 1);
    }
    std::sort(minus.begin(), minus.end());
    for (int i = 0;i < minus.size();++i) {
        if (minus[i] <= k) {
            k -= minus[i];
            ans -= 2;
        }
    }
    if (n - 1 - use[use.size() - 1] <= k) {
        ans--;
    }
    std::cout << ans;
    return 0;
}