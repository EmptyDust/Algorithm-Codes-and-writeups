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

i64 ceilDiv(i64 n, i64 m) {
    if (n >= 0) {
        return (n + m - 1) / m;
    }
    else {
        return n / m;
    }
}

i64 floorDiv(i64 n, i64 m) {
    if (n >= 0) {
        return n / m;
    }
    else {
        return (n - m + 1) / m;
    }
}

void exGCD(auto a, auto b, auto& x, auto& y) {
    if (!b) x = 1, y = 0;
    else exGCD(b, a % b, y, x), y -= a / b * x;
}

void solve() {
    i64 a, b, c;std::cin >> a >> b >> c;
    i64 g = std::__gcd(a, b);
    if (c % g) {
        std::cout << -1;
        return;
    }
    i64 dx = b / g, dy = a / g;
    i64 x0, y0;
    exGCD(a, b, x0, y0);
    i64 x1 = x0 * c / g, y1 = y0 * c / g;
    i64 liml = ceilDiv(-x1 + 1, dx);// (-x1 + 1) / dx
    i64 limr = floorDiv(y1 - 1, dy);
    // std::cout << x1 << " " << y1 << '\n';
    // std::cout << liml << " " << limr << "\n";
    if (liml > limr) {
        std::cout << x1 + liml * dx << ' ' << y1 - limr * dy;
        return;
    }
    std::cout
        << limr - liml + 1 << ' '
        << x1 + liml * dx << ' ' << y1 - limr * dy << ' '
        << x1 + limr * dx << ' ' << y1 - liml * dy << ' ';
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