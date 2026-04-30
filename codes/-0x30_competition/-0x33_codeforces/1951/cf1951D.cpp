#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
using pt = std::pair<int, int>;

void solve() {
    i64 n, k;
    std::cin >> n >> k;
    if (n < k) {
        std::cout << "NO";
        return;
    }
    if (n == k) {
        std::cout << "YES\n";
        std::cout << "1\n1";
        return;
    }
    if (n - k + 1 >= k) {
        std::cout << "YES\n";
        std::cout << "2\n";
        std::cout << n - k + 1 << ' ' << 1;
        return;
    }
    std::cout << "NO";
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