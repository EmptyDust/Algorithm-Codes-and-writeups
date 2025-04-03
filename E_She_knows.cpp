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
const int mod = 1e9 + 7;
// const int mod = 998244353;

i64 qpow(i64 x, i64 p) {
    i64 ret = 1;
    while (p) {
        if (p & 1)ret = ret * x % mod;
        p >>= 1;
        x = x * x % mod;
    }
    return ret;
}

void solve() {
    i64 n, m, k;std::cin >> n >> m >> k;
    i64 board = 2 * (n + m) - 8;
    i64 cnt = n * m - board;
    bool f = 0;
    for (int i = 0;i < k;++i) {
        int x, y, c;std::cin >> x >> y >> c;
        x--, y--;
        if (0 < x && x < n - 1 && 0 < y && y < m - 1 || (x == 0 || x == n - 1) && (y == 0 || y == m - 1)) {
            cnt -= 1;
        }
        else {
            if (c) {
                f ^= 1;
            }
            board -= 1;
        }
    }
    if (!board && f) {
        std::cout << 0;
        return;
    }
    i64 ans = qpow(2, cnt);
    if (board)ans = ans * qpow(2, board - 1) % mod;
    std::cout << ans;
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