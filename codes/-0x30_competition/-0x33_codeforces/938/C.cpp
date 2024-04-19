#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
i64 nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    i64 n, k;std::cin >> n >> k;
    for (int i = 0;i < n;++i)std::cin >> nums[i];
    i64 ans = 0;
    int l = 0, r = n - 1;
    while (1) {
        int x = std::min(nums[l], nums[r]);
        if (l == r) {
            ans += (k >= x);
            std::cout << ans;
            return;
        }
        if (nums[l] <= nums[r]) {
            if (x * 2 - 1 <= k) {
                k -= x * 2;
                nums[r] -= x;
                ans++;
                l++;
            }
            else {
                std::cout << ans;
                return;
            }
        }
        else {
            if (x * 2 <= k) {
                k -= x * 2;
                nums[l] -= x;
                ans++;
                r--;
            }
            else {
                std::cout << ans;
                return;
            }
        }
    }
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