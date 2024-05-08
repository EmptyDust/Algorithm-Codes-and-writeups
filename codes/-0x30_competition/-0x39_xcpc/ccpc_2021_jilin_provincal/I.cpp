#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    for (int i = 0;i < n;++i)std::cin >> nums[i];
    int sum = 0;
    for (int i = 0;i < n;++i)sum ^= nums[i];
    std::cout << sum << '\n';
    for (int i = 0;i < n;++i)nums[i] += 1;
    sum = 0;
    for (int i = 0;i < n;++i)sum ^= nums[i];
    std::cout << sum;
    return 0;
}