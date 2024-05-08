#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
i64 n;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n;
    auto x = n / (i64)123456789;
    bool f = false;
    if (x) {
        f = true;
        std::cout << "123456789";
        for (int i = 1;i < x;++i)std::cout << 9;
    }

    return 0;
}