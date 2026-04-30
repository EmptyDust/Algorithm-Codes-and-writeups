#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], f[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    std::cin >> n;
    for (int i = 1;i <= n;++i)std::cin >> nums[i], f[i] = 0;
    int x = nums[1];
    for (int i = 1;i <= n;++i)if (nums[i] != x)
        f[i] = 1;
    f[0] = 1;
    int pre = 0, ans = 1e9;
    for (int i = 1;i <= n;++i) if (f[i]) {
        ans = std::min(ans, i - pre - 1);
        pre = i;
    }
    if (pre)ans = std::min(ans, n + 1 - pre - 1);
    std::cout << (ans == 1e9 ? -1 : ans);
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