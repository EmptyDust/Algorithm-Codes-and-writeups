#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, k;std::cin >> n >> k;
    if (k >= 1ll * (n - 1) * n / 2) {
        std::cout << "no solution";
        return 0;
    }
    for (int i = 0;i < n;++i)std::cout << "0 " << i << '\n';
    return 0;
}