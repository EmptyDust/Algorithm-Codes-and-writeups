#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
using pt = std::pair<int, int>;

void calc(i64 x) {
    i64 t = (i64)1 << std::__lg(x);
    std::cout << t << ' ' << (x ^ t) << std::endl;
}

void solve() {
    i64 n;std::cin >> n;
    bool parity = std::__popcount(n) % 2;
    std::string response = (parity ? "second" : "first");
    std::cout << response << std::endl;
    if (!parity)calc(n);
    i64 p1, p2;
    std::cin >> p1 >> p2;
    while (p1 && p2) {
        if (std::__popcount(p1) % 2 == 0)
            calc(p1);
        else
            calc(p2);
        std::cin >> p1 >> p2;
    }
}

signed main() {
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}