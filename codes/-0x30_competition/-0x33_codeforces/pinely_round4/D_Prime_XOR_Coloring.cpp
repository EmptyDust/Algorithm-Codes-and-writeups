#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n;std::cin >> n;
    if (n == 3) {
        std::cout << "2\n1 2 2";
        return;
    }
    if (n == 4) {
        std::cout << "3\n1 2 2 3";
        return;
    }
    if (n == 5) {
        std::cout << "3\n1 2 2 3 3";
        return;
    }

    std::cout << 4 << "\n";
    for (int i = 0;i < n;++i) {
        int res = i % 4 + 1;
        std::cout << res << ' ';
    }
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