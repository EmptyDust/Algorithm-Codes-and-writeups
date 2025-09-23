#include <bits/stdc++.h>

using pii = std::pair<int, int>;
using i64 = long long;
using a3 = std::array<int, 3>;
using ld = long double;

const int mod = 998244353;

i64 qpow(i64 x, i64 b)
{
    i64 ret = 1;
    while (b)
    {
        if (b & 1)
            ret = ret * x % mod;
        b >>= 1;
        x = x * x % mod;
    }
    return ret;
}
void slove()
{
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    for (auto &x : a)
        std::cin >> x;
    std::ranges::sort(a);
    i64 ans = 0, p = 1;
    for (int i = 0; i < n; ++i)
    {
        i64 res = p * a[i] % mod * qpow(2, n - 1 - i) % mod;
        // std::cout << res << '\n';
        p = (p * 3 - 1) % mod;
        ans = (ans + res) % mod;
    }
    std::cout << ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--)
    {
        slove();
        std::cout << '\n';
    }
}