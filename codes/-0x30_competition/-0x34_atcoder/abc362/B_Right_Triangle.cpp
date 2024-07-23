#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

int point(pii a, pii b, pii c) {
    pii x = { a.first - b.first,a.second - b.second };
    pii y = { b.first - c.first,b.second - c.second };
    return x.first * y.first + x.second * y.second;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::vector<pii> ps(3);
    for (auto& [x, y] : ps)std::cin >> x >> y;
    std::ranges::sort(ps);
    do {
        if (point(ps[0], ps[1], ps[2]) == 0) {
            std::cout << "Yes";
            return 0;
        }
    } while (std::next_permutation(ps.begin(), ps.end()));
    std::cout << "No";
    return 0;
}