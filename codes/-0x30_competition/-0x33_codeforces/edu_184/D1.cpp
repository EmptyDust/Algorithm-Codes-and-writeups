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

// void jos() {
//     int64_t n, k, a{}, b{ 1 }; std::cin >> n >> k; --k;
//     while (b < n) {
//         auto s = a / k + 1, u = b / k + 1, v = min(k - a / s, (min(u * k, n) - b + u - 1) / u);
//         a += s * v, b += u * v;
//     }
//     cout << a + 1 << '\n';
// }

void solve() {
    i64 n = 1e12, k, T, a;std::cin >> T >> k >> a;k--;a--;
    if (k == 0) {
        std::cout << -1;
        return;
    }
    i64 t{ 0 };
    while (t < T) {
        auto s = a / k + 1, v = std::min(T - t, k - a / s);
        a += s * v;
        t += v;
        if (a >= n) {
            std::cout << -1;
            return;
        }
        std::cout << t << ' ' << a << '\n';
    }
    std::cout << a + 1;
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