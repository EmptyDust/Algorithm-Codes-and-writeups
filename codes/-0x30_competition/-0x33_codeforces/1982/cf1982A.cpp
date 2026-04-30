#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int x1, y1;std::cin >> x1 >> y1;
    int x2, y2;std::cin >> x2 >> y2;
    if (x2 < y2)std::swap(x2, y2), std::swap(x1, y1);
    bool f = y2 > x1 && y1 > x1;
    std::cout << (f ? "NO" : "YES");
}
//x2 y2y1  x1 
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}