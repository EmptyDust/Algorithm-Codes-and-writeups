#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, k;std::cin >> n >> k;
    std::vector<pt> pts(n);
    for (auto& [h, w] : pts)std::cin >> h >> w;
    int l = 1, r = 1e5;
    auto check = [&](auto x)->bool {
        i64 res = 0;
        for (auto& [h, w] : pts)res += (h / x) * (w / x);
        return (res >= k);
        };
    while (l < r) {
        auto mid = l + r >> 1;
        if (check(mid))l = mid + 1;
        else r = mid;
    }
    std::cout << l - 1;
    return 0;
}