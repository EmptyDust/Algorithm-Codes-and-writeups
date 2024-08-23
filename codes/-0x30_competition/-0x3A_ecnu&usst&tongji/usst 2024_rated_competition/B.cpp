#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, m;std::cin >> n >> m;
    std::vector<int> nums(n);
    std::vector<i64> a(m + 1);
    a[0] = 1;
    for (int& x : nums)std::cin >> x;
    for (int x : nums)for (int j = m - x;j >= 0;--j) {
        a[j + x] += a[j];
        a[j + x] %= mod;
    }
    std::cout << a[m];
    return 0;
}