#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    std::cin >> n;
    for (int i = 0;i < n;++i)std::cin >> nums[i];
    int sum = std::accumulate(nums, nums + n, 0);
    if (sum % 2) {
        int ans = 1e9;
        for (int i = 0;i < n;++i) {
            int y = nums[i], x = nums[i];
            int cnt = 0;
            while (x) {
                x /= 2;
                cnt++;
                if ((y - x) % 2) {
                    ans = std::min(ans, cnt);
                    break;
                }
            }
        }
        std::cout << ans;
    }
    else std::cout << 0;
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