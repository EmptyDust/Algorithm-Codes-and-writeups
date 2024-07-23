#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;
using a3 = std::array <int, 3>;

void solve() {
    int n;std::cin >> n;
    std::vector<a3> a3s(n);
    for (auto& [l, r, y] : a3s)std::cin >> l >> r >> y;
    std::sort(a3s.begin(), a3s.end(), [&](auto a, auto b) {
        if (a[2] != b[2])return a[2] > b[2];
        return a < b;
        });
    int sx, sy;std::cin >> sx >> sy;
    for (int i = 0;i < n;++i) {
        auto [l, r, y] = a3s[i];
        if (y > sy)continue;
        if (r <= sx || sx <= l)continue;
        sx = r;
        sy = y;
    }
    std::cout << sx;
}

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