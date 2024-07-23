#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int r, g, b;std::cin >> r >> g >> b;
    std::string s;std::cin >> s;
    switch (s[0])
    {
    case 'R':
        std::cout << std::min(g, b);
        break;
    case 'G':
        std::cout << std::min(r, b);
        break;
    case 'B':
        std::cout << std::min(g, r);
    default:
        break;
    }
    return 0;
}