#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n;std::cin >> n;
    if (n <= 5) {
        for (int i = 2;i <= n + 1;++i) {
            std::cout << 1 << " " << i << '\n';
        }
        return;
    }
    int m = n / 3;
    int x = m + 2 + n % 3;
    std::vector<pii> ans;
    for (int i = 2;i <= x + 1;++i) {
        ans.push_back({ 1,i });
    }
    if (m >= 2) {
        int y = m;
        for (int i = 3;i <= y + 2;++i) {
            ans.push_back({ 2,i });
        }
    }
    if (m >= 3) {
        int z = m - 2;
        for (int i = 4;i <= z + 3;++i) {
            ans.push_back({ 3,i });
        }
    }

    std::ranges::sort(ans);
    for (auto [x, y] : ans)std::cout << x << " " << y << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
        // std::cout << '\n';
    }
    return 0;
}