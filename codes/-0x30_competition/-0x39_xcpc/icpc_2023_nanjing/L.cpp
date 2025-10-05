#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<i64, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    i64 n, k;std::cin >> n >> k;
    std::vector<a2> info(n);
    for (auto& [f, c] : info) {
        int w;
        std::cin >> c >> w >> f;
        if (w == 2)c *= 2;
    }
    ranges::sort(info, std::greater<a2>());
    i64 ans = 0, x = 0;
    for (auto [f, c] : info) {
        if (x) {
            i64 m = std::min(c, x);
            c -= m;
            x -= m;
        }
        i64 y = c / k;
        ans += 1ll * y * f;
        c %= k;
        if (c) {
            ans += f;
            x = k - c;
        }
    }
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