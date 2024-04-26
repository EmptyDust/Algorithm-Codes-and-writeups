#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve() {
    int n, k;std::cin >> n >> k;
    int u = n;
    while (k--) { int r, c;std::cin >> r >> c; u -= r != c ? 2 : 1; }
    i64 pre = 1, cur = 1;
    for (int i = 2;i <= u;++i) {
        i64 tmp = (cur + 2 * (i - 1) * pre % mod) % mod;
        pre = cur;
        cur = tmp;
    }
    std::cout << cur;
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