#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    std::vector<int> a(3);
    for (int& x : a)std::cin >> x;
    std::ranges::sort(a);
    for (int i = 0;i < 5;++i) {
        a[0]++;
        std::ranges::sort(a);
    }
    std::cout << a[0] * a[1] * a[2];
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