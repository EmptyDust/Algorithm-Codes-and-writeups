#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    int n, k;std::cin >> n >> k;
    if (k == 1) {
        for (int i = 1;i <= n;++i)std::cout << i << ' ';
        return;
    }
    if (k == n) {
        for (int i = 1;i <= n;++i)std::cout << 1 << ' ';
        return;
    }
    std::cout << -1;
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