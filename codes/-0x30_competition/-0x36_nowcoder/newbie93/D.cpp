#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
i64 n, m, q;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m;
    while (m--) {
        std::cin >> q;
        i64 l = 0, r = ((i64)1 << n) - 1;
        i64 ans = 0, s = 0;
        while (l != r) {
            i64 mid = l + r >> 1;
            if (q > mid) {
                l = mid + 1;
                ans |= (i64)1 << s;
            }
            else {
                r = mid;
            }
            s++;
        }
        std::cout << ans << '\n';
    }
    return 0;
}