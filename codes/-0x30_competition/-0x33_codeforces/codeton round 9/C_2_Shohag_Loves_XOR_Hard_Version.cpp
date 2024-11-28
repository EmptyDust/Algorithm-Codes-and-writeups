#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

i64 x, m;

i64 cal(i64 y) {
    if (y < 0)return 0;
    return y / x;
}

i64 range(i64 l, i64 r) {
    // std::cout << l << ' ' << r << ' ';
    // std::cout << cal(r - 1) - cal(l - 1) << '\n';
    return cal(r - 1) - cal(l - 1);
}

void solve() {
    std::cin >> x >> m;
    i64 U = (1ll << std::__lg(x) + 1) - 1;
    i64 cnt = 0;
    for (int i = 1;i <= std::min(m, U);++i) {
        int y = i ^ x;
        if (y % i == 0 || y % x == 0)cnt++;
    }
    // std::cout << cnt << ' ';
    if (m > U) {
        cnt -= cal(U);
        i64 cur = 0;
        for (int i = std::__lg(m);i >= 0;--i) {
            if (m >> i & 1) {
                i64 nc = cur;
                if (x >> i & 1)nc |= 1ll << i;
                cnt += range(nc, nc + (1ll << i));
            }
            if ((m >> i & 1) ^ (x >> i & 1)) {
                cur |= 1ll << i;
            }
        }
        // std::cout << cur << '\n';
        cnt += cur % x == 0;
    }
    std::cout << cnt;
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