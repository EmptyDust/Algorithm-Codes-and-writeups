#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    std::cin >> n;
    int ans = 0, ansi = 0;
    for (int i = n - 1;i >= 1;i--) {
        if (std::__gcd(i, n) + i > ans) {
            ans = std::__gcd(i, n) + i;
            ansi = i;
        }
    }
    std::cout << ansi;
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