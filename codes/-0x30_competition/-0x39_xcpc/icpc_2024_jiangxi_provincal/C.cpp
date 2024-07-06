#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, k;std::cin >> n >> k;
    std::vector<int> nums(n);
    for (int& x : nums)std::cin >> x;
    i64 sum = std::accumulate(nums.begin(), nums.end(), (i64)0);
    if (sum == k) {
        std::cout << n;
    }
    else std::cout << n - 1;
    return 0;
}