#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n;
using pt = std::pair<int, int>;

void solve()
{
    int a, b;
    std::cin >> a >> b;
    if (a == b)
    {
        std::cout << 0;
        return;
    }

    int gcd = std::__gcd(a, b);
    if (gcd == a)
    {
        std::cout << b;
        return;
    }
    if (gcd > 1)
    {
        std::cout << a + b;
        return;
    }
    int ans = 1e9;
    int res = -1;
    for (int i = 2; i <= b; ++i)
    {
        if (i * a / std::__gcd(i, a) + i * b / std::__gcd(i, b) < ans)
            res = i;
        ans = std::min(ans, i * a / std::__gcd(i, a) + i * b / std::__gcd(i, b));
    }
    std::cout << res << ' ' << ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
        std::cout << '\n';
    }
    return 0;
}