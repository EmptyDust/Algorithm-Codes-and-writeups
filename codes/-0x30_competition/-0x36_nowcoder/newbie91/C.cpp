#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, m;
    std::cin >> n >> m;
    int x = n / 2 + 1, y = m / 2 + 1;
    int time = std::max(n / 2, m / 2);
    int k;std::cin >> k;
    int cnt = 0;
    while (k--) {
        int i, j;std::cin >> i >> j;
        int len = std::abs(i - x) + std::abs(j - y);
        if (len <= time)cnt++;
    }
    std::cout << cnt;
    return 0;
}