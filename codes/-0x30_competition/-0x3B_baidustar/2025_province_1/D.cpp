// 6 8
// 24
// 3 5
// 3 6 9 12 15
// 8 11 14
// 13
// x * y - x - y
// 4 7

// l, r
// 2 * l, 2 * r
// (x - 1) * r == x * l
// x * (r - l) == r
// 3, 5
#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    i64 l, r;
    std::cin >> l >> r;
    if (l == 1)
    {
        std::cout << 0 << '\n';
        return;
    }
    if (l == r)
    {
        std::cout << "infty" << '\n';
        return;
    }
    // (x + 1) * (r - l) + 1 >= r
    // x = (r - 2) / (r - l)
    // y = r - (x * (r - l) + 1)
    // ans = (y + r - (r - l + 1)) * x / 2
    i64 x = (r - 2) / (r - l);
    i64 y = r - (x * (r - l) + 1);
    i64 ans = (y + r - (r - l + 1)) * x / 2;
    // std::cout << x << " " << y << '\n';
    std::cout << ans << '\n';
    // 1~5
    // 8 9 10 11
    // 15 16 17
    // 22 23
    // 29
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--)
        solve();
    return 0;
}