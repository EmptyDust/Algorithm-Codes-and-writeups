#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve()
{
    i64 a, b;
    std::cin >> a >> b;
    if (a == b)
    {
        std::cout << 0;
        return;
    }

    i64 gcd = std::__gcd(a, b);
    i64 ans = a * b / gcd;
    i64 x = b;
    for (i64 i = 2; i <= std::sqrt(b); ++i)
        if (b % i == 0)
        {
            x = i;
            break;
        }
    i64 y = a;
    for (i64 i = 2; i <= std::sqrt(a); ++i)
        if (a % i == 0)
        {
            y = i;
            break;
        }
    ans = std::min(ans, a * 2 + 2 * b);
    ans = std::min(ans, a * x + b);
    ans = std::min(ans, a + y * b);
    ans = std::min(ans, a + y * x + b);
    ans = std::min(ans, a + y * 2 + 2 * b);
    ans = std::min(ans, a * 2 + 2 * x + b);
    ans = std::min(ans, a + y * 2 + 2 * x + b);
    if (gcd == a)
        ans = std::min(ans, b);
    if (gcd > 1)
        ans = std::min(ans, a + b);
    std::cout << ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    i64 t;
    std::cin >> t;
    while (t--)
    {
        solve();
        std::cout << '\n';
    }
    return 0;
}