#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], f1[MAXN], f2[MAXN], n;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    for (int i = 1;i <= n;++i)std::cin >> nums[i];
    for (int i = 1;i <= n;++i)
        f1[i] = std::min(f1[i - 1] + 1, nums[i]);
    for (int i = n;i >= 1;--i)
        f2[i] = std::min(f2[i + 1] + 1, nums[i]);
    int ans = 0;
    for (int i = 1;i <= n;++i)
        ans = std::max(ans, std::min(f1[i], f2[i]));
    std::cout << ans;
    return 0;
}