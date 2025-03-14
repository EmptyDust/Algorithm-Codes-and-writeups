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

void solve() {
    i64 x = 0, y = 0;
    std::cout << 0 << std::endl;
    i64 m;std::cin >> m;
    i64 mask = 0;
    for (int i = 1;i < 30;i += 2) {
        mask |= 1ll << i;
    }
    std::cout << mask << std::endl;
    i64 n;std::cin >> n;
    n -= 2 * mask;
    // std::cout << n << ' ';
    for (int i = 0;i <= 30;i += 2) if (n >> i & 1) {
        x += 1ll << i;
    }
    for (int i = 1;i <= 30;i += 2) if (n >> i & 1) {
        x += 1ll << i - 1;
        y += 1ll << i - 1;
    }
    // std::cout << x << ' ' << y << '\n';
    i64 o = m - x - y;
    for (int i = 1;i <= 30;i += 2) if (o >> i & 1) {
        x += 1ll << i;
    }
    for (int i = 0;i <= 30;i += 2) if (o >> i & 1) {
        x += 1ll << i - 1;
        y += 1ll << i - 1;
    }

    // std::cout << x << ' ' << y << '\n';
    std::cout << "!" << std::endl;
    i64 q;std::cin >> q;
    std::cout << ((x | q) + (y | q)) << std::endl;
}
//1111 0001
//1100 0100
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}