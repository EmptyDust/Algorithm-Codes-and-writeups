#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;
//s*t<n
//(t-1)+(s-1)
int solve() {
    int n;std::cin >> n;
    if (n == 1)return 0;
    int m = std::sqrt(n - 1) + 1;
    if (m * (m - 1) >= n)return 2 * m - 3;
    return 2 * m - 2;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        std::cout << solve();
        std::cout << '\n';
    }
    return 0;
}