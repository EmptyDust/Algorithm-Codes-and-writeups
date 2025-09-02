#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<int, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

std::vector<int> num{ 2,3,5,7 };

i64 cal(i64 x) {
    i64 res = 0;
    for (int i = 0;i < (1 << 4);++i) {
        i64 y = 1;
        for (int t = 0;t < 4;++t) if (i >> t & 1) {
            y *= num[t];
        }
        res += x / y * (std::__popcount(i) & 1 ? -1 : 1);
        // std::cout << y << ' ' << res << '\n';
    }
    return res;
}

void solve() {
    i64 l, r;std::cin >> l >> r;
    std::cout << cal(r) - cal(l - 1);
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