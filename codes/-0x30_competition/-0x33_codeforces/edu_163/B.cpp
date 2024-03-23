#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    std::cin >> n;
    for (int i = 0;i < n;++i)std::cin >> nums[i];
    int pre = -1;
    for (int i = 0;i < n;++i) {
        int x = nums[i] / 10;
        int y = nums[i] % 10;
        if (y >= x && (!i || pre <= x)) {
            pre = y;
        }
        else if (pre <= nums[i]) {
            pre = nums[i];
        }
        else {
            std::cout << "NO";
            return;
        }
    }
    std::cout << "YES";
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