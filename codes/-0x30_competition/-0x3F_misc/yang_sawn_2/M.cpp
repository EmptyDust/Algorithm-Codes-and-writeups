#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using ld = long double;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const int mod = 1e9 + 7;

const ld Pi = 3.14159265358;




void solve()
{
    ld n, r, h, x0, y0, vx, vy;
    std::cin >> n >> r >> h >> x0 >> y0 >> vx >> vy;

    ld a, b;
    a = std::atan(vy / vx);
    b = std::atan(-y0 / x0);

    ld c = std::asin(std::sin(a + b) * std::sqrt(x0 * x0 + y0 * y0) / r);

    ld s = (r * std::sin(Pi - c - a - b) / std::sin(a + b));
    ld s1 = (2 * r * std::cos(c));

    ld v = (std::sqrt(vx * vx + vy * vy));
    ld t2 = (n * s1 + s) / v;
    ld t1 = ((n - 1) * s1 + s) / v;

    ld ans1 = h / t2, ans2 = h / t1;
    // ld 
    std::cout << v << ' ' << a << ' ' << b << ' ' << c << '\n';
    std::cout << ans1 << ' ' << ans2 << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    // int t;
    // std::cin >> t;
    // while (t--)
    solve();
}