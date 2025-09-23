#include <bits/stdc++.h>

using pii = std::pair<int, int>;
using i64 = long long;
using a3 = std::array<int, 3>;
using ld = long double;

const int mod = 1e9 + 7;

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
}
void slove()
{
    std::cout << 123;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    // std::cin >> t;
    while (t--)
    {
        slove();
        std::cout << '\n';
    }
}