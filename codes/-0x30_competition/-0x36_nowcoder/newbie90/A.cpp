#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n, m;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m;
    int res = 0;
    for (int i = 0;i < n;++i)std::cin >> nums[i];
    int num;
    while (m--) {
        std::cin >> num;
        res += nums[num - 1];
    }
    std::cout << res;
    return 0;
}