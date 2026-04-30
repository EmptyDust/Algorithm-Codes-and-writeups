#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
i64 nums[MAXN];
using pt = std::pair<int, int>;

void solve() {
    i64 n, k;std::cin >> n >> k;
    for (int i = 0;i < n;++i)std::cin >> nums[i];
    std::sort(nums, nums + n);
    i64 cur = 0, yu = 0;
    for (int i = 0;i < n;++i) {
        i64 cost = (nums[i] - cur) * i;
        if (cost <= k) {
            k -= cost;
            cur = nums[i];
        }
        else {
            cur += k / i;
            yu = n - i + k % i;
            k = 0;
            break;
        }
    }
    if (k) {
        cur += k / n;
        yu = k % n;
    }
    i64 ans = cur * n + yu - (n - 1);
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