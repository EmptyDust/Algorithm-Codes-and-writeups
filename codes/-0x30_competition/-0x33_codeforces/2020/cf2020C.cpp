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

// 0100
// 1010
// 0010

// a b c d s
// 0 0 0 0 0
//   0 0 1

void solve() {
    // a + b = a | b + a & b
    // a | b = d + a & c
    // a + b - d = a & c + a & b
    i64 b, c, d;std::cin >> b >> c >> d;
    i64 a = 0;
    for (int i = 0;i < 60;++i) {
        int x = b >> i & 1, y = c >> i & 1;
        bool ok = 0;
        for (int j = 0;j < 2;++j) {
            if ((x | j) - (y & j) == (d >> i & 1)) {
                if (j) a ^= 1ll << i;
                ok = 1;
                break;
            }
        }
        if (!ok) {
            std::cout << -1;
            return;
        }
    }
    std::cout << a;
    // std::cout << ' ' << ((a | b) - (a & c) == d ? "ok" : "no");
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