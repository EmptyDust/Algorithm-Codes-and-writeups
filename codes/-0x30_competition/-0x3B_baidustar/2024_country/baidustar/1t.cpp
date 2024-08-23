#include <bits/stdc++.h>

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

using i64 = long long;

void solve() {
    int n = rng() % 7 * 3 + 3;
    std::cout << n << '\n';
    for (int i = 0;i < n;++i)std::cout << rng() % (int)1e5 << ' ';
    std::cout << '\n';
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < 21;++j)std::cout << rng() % (int)1e5 << ' ';
        std::cout << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}