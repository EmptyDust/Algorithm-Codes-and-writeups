#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
using pt = std::pair<int, int>;

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> nums(n);
    int min = 1e9;
    for (int& num : nums)std::cin >> num, min = std::min(min, num);
    while (q--) {
        int x;std::cin >> x;
        std::cout << std::min(x, min - 1) << ' ';
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