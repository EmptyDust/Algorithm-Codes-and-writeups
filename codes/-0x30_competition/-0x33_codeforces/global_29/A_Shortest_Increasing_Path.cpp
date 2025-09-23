#include<bits/stdc++.h>

void solve() {
    int x, y;std::cin >> x >> y;
    if (y == 1) {
        std::cout << -1;
    }
    else if (x < y) {
        std::cout << 2;
    }
    else if (x >= y + 2) {
        std::cout << 3;
    }
    else std::cout << -1;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;std::cin >> t;
    while (t--) {
        solve();
        std::cout << "\n";
    }
}