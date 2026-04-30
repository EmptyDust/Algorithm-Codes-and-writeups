#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e8;
int nums[MAXN], n;
using pt = std::pair<int, int>;

int gt(int x) { return x >= 0 ? nums[x] + 1 : inf; }

void solve() {
    int ans = 0;
    std::cin >> n;
    int cnt = n / 30;
    ans += cnt * 2;
    n %= 30;
    ans += std::min(nums[n], n + 15 <= 30 && cnt ? nums[n + 15] - 1 : inf);
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    for (int i = 1;i <= 30;++i) {
        nums[i] = inf;
        nums[i] = std::min(nums[i], gt(i - 1));
        nums[i] = std::min(nums[i], gt(i - 3));
        nums[i] = std::min(nums[i], gt(i - 6));
        nums[i] = std::min(nums[i], gt(i - 10));
        nums[i] = std::min(nums[i], gt(i - 15));
    }
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}