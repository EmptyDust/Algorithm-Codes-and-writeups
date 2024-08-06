#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int x = 100, n = 200;
    std::vector<int> a(n + 1);a[0] = 1;
    for (int i = 1;i <= x;++i) {
        for (int y = n;y >= i;--y) {
            a[y] += a[y - i];
        }
    }
    for (int i = 0;i <= n;++i)
        std::cout << a[i] << ' ';
    return 0;
}