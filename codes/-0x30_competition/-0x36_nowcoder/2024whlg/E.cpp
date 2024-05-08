#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    i64 n, L, R;std::cin >> n >> L >> R;
    for (int i = 1;i <= n;++i)std::cin >> nums[i];
    std::sort(nums + 1, nums + n + 1);
    i64 ans = 0;
    for (int i = 1, l = n, r = n;i <= n && i < r;++i) {
        while (r && nums[i] + nums[r] > R)r--;
        while (l && nums[i] + nums[l] >= L)l--;
        if (i >= r)break;
        ans += r - std::max(l, i);
    }
    std::cout << ans;
    return 0;
}