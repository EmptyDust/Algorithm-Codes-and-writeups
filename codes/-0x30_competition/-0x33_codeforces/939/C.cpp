#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 501;
int nums[MAXN][MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    std::cin >> n;
    i64 sum = 0;
    for (int i = 1, j = 1;i <= n;++i, j += 2) {
        sum += i * j;
    }
    std::cout << sum << ' ' << 2 * n << '\n';
    for (int i = n;i;--i) {
        std::cout << 1 << ' ' << i << ' ';
        for (int j = 1;j <= n;++j)std::cout << j << ' ';
        std::cout << '\n';
        std::cout << 2 << ' ' << i << ' ';
        for (int j = 1;j <= n;++j)std::cout << j << ' ';
        std::cout << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}