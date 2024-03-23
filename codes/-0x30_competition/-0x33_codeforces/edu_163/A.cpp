#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    std::cin >> n;
    if (n & 1) {
        std::cout << "NO";
        return;;
    }
    std::cout << "YES" << '\n';
    for (int i = 0;i < n;i += 2) {
        std::cout << (char)('A' + i / 2);
        std::cout << (char)('A' + i / 2);
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