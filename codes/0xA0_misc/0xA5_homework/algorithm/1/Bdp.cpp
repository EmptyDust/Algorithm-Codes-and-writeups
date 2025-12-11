#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;
using d64 = long double;

using a2 = std::array<int, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;
using a10 = std::array<int, 10>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n, m, d;std::cin >> n >> m >> d;
    a10 cur = a10();
    a10 base = a10();
    for (int i = 0;i < n;++i) std::cin >> cur[i];
    for (int i = 5;i < 5 + m;++i) std::cin >> cur[i];
    int sta = 0;
    base[0] = 1;
    for (int i = 0;i < 10;++i) {
        if (i) base[i] = base[i - 1] * 6;
        sta += base[i] * cur[i];
    }
    std::vector<d64> dp(base.back());
    dp[sta] = 1;
    for (int i = sta - 1; i >= 0;--i) {
        for (int j = 0;j < 10;++j) {
            if (i / (j ? base[j - 1] : 1) % 6 != 5) {
                dp[i] += dp[i + base[j]];
            }
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}