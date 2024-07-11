#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;std::cin >> n;
    std::set<pii> a, b;
    for (int i = 1;i <= n;++i) {
        int x, y;
        bool c, d;
        std::cin >> x >> y >> c >> d;
        if (c && d) {
            if (x > y)b.insert({ y,i });
            else a.insert({ x,i });
        }
        else if (c) {
            a.insert({ x,i });
        }
        else b.insert({ y,i });
    }
    std::cout << a.size() << ' ';
    for (auto [_, x] : a)std::cout << x << " ";
    std::cout << std::endl;
    std::cout << b.size() << ' ';
    for (auto [_, x] : b)std::cout << x << " ";
    return 0;
}