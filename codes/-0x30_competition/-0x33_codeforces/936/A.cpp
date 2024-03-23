#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    std::cin >> n;
    for (int i = 0;i < n;++i)std::cin >> nums[i];
    std::sort(nums, nums + n);
    int cnt = 1;
    nums[(n - 1) / 2]++;
    for (int i = (n - 1) / 2 + 1;i < n;++i) {
        if (nums[i] < nums[i - 1]) {
            cnt++;
            nums[i]++;
        }
        else break;
    }
    std::cout << cnt;
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