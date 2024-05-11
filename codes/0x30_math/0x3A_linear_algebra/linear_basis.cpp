#include <bits/stdc++.h>
using i64 = unsigned long long;
constexpr int N = 63, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pt = std::pair<i64, i64>;

std::vector<i64> get_linear_basis(std::vector<i64>& nums, int N = 63) {
    std::vector<i64> p(N + 1);
    auto insert = [&](i64 x) {
        for (int s = N;s >= 0;--s)if (x >> s & 1) {
            if (!p[s]) {
                p[s] = x;
                break;
            }
            x ^= p[s];
        }
        };
    for (auto x : nums)
        insert(x);
    return p;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;std::cin >> n;
    std::vector<i64> nums(n);
    for (auto& x : nums)std::cin >> x;
    auto p = get_linear_basis(nums, 63);
    i64 ans = 0;
    for (int s = N;s >= 0;--s)
        ans = std::max(ans, ans ^ p[s]);
    std::cout << ans;
    return 0;
}