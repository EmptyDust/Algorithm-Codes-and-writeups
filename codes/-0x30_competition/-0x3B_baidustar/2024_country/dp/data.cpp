#include <bits/stdc++.h>

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

using i64 = long long;

void solve() {
    int n = rng() % 3 * 3 + 3;
    std::cout << n << '\n';
    int a[20][20];
    for (int i = 0;i < n;++i) {
        int a = rng() % 100 - 50;
        std::cout << a << ' ';
    }
    std::cout << '\n';
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < n;++j)a[i][j] = rng() % 100 - 50;
    }
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < n;++j) {
            if (i == j)a[i][j] = 0;
            a[i][j] = a[j][i];
        }
    }
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < n;++j)
            std::cout << a[i][j] << ' ';
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
