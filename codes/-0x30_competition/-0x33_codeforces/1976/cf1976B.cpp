#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    std::cin >> n;
    std::vector<int> a(n), b(n + 1);
    for (int& x : a)std::cin >> x;
    for (int& x : b)std::cin >> x;
    int cz = inf;
    i64 ans = 0;
    for (int i = 0;i < n;++i) {
        ans += std::abs(a[i] - b[i]);
        cz = std::min({ cz, std::abs(a[i] - b[n]),std::abs(b[i] - b[n]) });
        if (a[i] >= b[n] && b[n] >= b[i] || a[i] <= b[n] && b[n] <= b[i])cz = 0;
    }
    std::cout << ans + cz + 1;
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