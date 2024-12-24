#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n, m;
    std::cin >> n >> m;

    if (m >= 2 * n) {
        std::cout << "NO\n";
        return;
    }

    std::cout << "YES\n";
    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << (i - j + 2 * n) % (2 * n) / 2 + 1 << " \n"[j == m - 1];
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}