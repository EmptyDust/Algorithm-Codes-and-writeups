#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n, m, q;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m;
    for (int i = 1;i <= n;++i)std::cin >> nums[i];
    while (m--) {
        std::cin >> q;
        i64 l = 1, r = n;
        auto check = [&](auto x)->bool {
            return nums[x] >= q;
            };
        while (l < r) {
            auto mid = l + r >> 1;
            if (check(mid))r = mid;
            else l = mid + 1;
        }
        if (nums[l] == q)
            std::cout << l << ' ';
        else std::cout << -1 << ' ';
    }
    return 0;
}