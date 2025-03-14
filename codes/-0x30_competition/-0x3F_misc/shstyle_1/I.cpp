#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<i64, 3>;
using a4 = std::array<int, 4>;

const int N = 1e5;
const int MAXN = 1e6 + 50;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

a3 res[201] = {};

void solve() {
    int x;std::cin >> x;
    if (x == 0) {
        std::cout << "YES\n";
        std::cout << "0 0 0\n";
        return;
    }
    auto [a, b, c] = res[x];
    if (a == 0 && b == 0 && c == 0) {
        std::cout << "NO\n";
        return;
    }
    std::cout << "YES\n";
    std::cout << a << ' ' << b << ' ' << c << '\n';
}

int di(i64 x, i64 a) {
    i64 l = -5002, r = 5002;
    while (l < r) {
        auto mid = l + r >> 1;
        if (x <= a + mid * mid * mid)r = mid;
        else l = mid + 1;
    }
    return l;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    i64 x = di(200, 0);
    // std::cout << -5000ll * -5000ll * -5000ll * 2 << '\n';
    // std::cout << x << ' ';
    for (i64 a = -5000;a < 5000;++a) {
        for (i64 b = -5000;b < 5000;++b) {
            i64 x = a * a * a + b * b * b;
            // std::cout << x << ' ';
            i64 u = di(201, x), d = di(0, x);
            // std::cout << u << ' ' << d << ' ' << x << '\n';
            for (i64 c = std::max(-5000ll, d);c < std::min(5000ll, u);++c) {
                // return 0;
                i64 y = x + c * c * c;
                res[y] = { a,b,c };
            }
        }
    }
    // std::cout << "ok";
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}