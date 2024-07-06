#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int n;
using pii = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::string s, t;
    std::cin >> s >> t;
    int x = s.length(), y = t.length();
    if (x > y)std::swap(x, y);
    if (y == 6) {
        std::cout << -1;
    }
    else std::cout << y - x + 1;
    return 0;
}