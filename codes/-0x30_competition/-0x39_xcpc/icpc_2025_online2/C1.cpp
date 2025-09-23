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
    int S;
    std::cin >> S;
    std::vector<int> a(8);
    for (int i = 1; i <= 7; ++i)
        std::cin >> a[i];
    int l = 0, r = 700'000'001;
    auto check = [&](int x)
    {
        auto b(a);
        for (int i = 0; i < 3; ++i)
        {
            int cur = 0;
            for (int j = 1; j < 8; ++j)
            {
                if (j >> i & 1)
                {
                    int c = std::min(x - cur, b[j]);
                    cur += c;
                    b[j] -= c;
                }
            }
            if (cur < x)
                return true;
        }
        return false;
    };
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    std::cout << l - 1 << '\n';
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
    }
}