#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, m;std::cin >> n >> m;
    std::vector<pii> pts(m);
    for (auto& [l, r] : pts)std::cin >> l >> r;
    int ans = inf;
    for (auto& [l, r] : pts)ans = std::min(ans, r - l + 1);
    std::cout << ans << '\n';
    int cur = 0;
    for (int i = 0;i < n;++i) {
        std::cout << cur << ' ';
        cur = (cur + 1) % ans;
    }
    return 0;
}