#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
i64 nums[MAXN], n;
using pt = std::pair<int, int>;
/*
42
14 21 6 sum = 41

*/
void solve() {
    std::cin >> n;
    for (int i = 0;i < n;++i)std::cin >> nums[i];
    i64 lcm = nums[0];
    for (int i = 1;i < n;++i) {
        lcm = lcm * nums[i] / std::__gcd(lcm, nums[i]);
    }
    i64 sum = 0;
    for (int i = 0;i < n;++i)sum += lcm / nums[i];
    if (sum < lcm) {
        for (int i = 0;i < n;++i)std::cout << lcm / nums[i] << ' ';
    }
    else std::cout << -1;
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