#include <bits/stdc++.h>
using i64 = long long;
constexpr int mod = 1e9 + 7, MAXN = 1e6;

i64 qpow(i64 num, i64 x)
{
    if (num == 1 || x == 0)
        return 1;
    i64 ans = 1;
    while (x)
    {
        if (x & 1)
            ans = (ans * num) % mod;
        num = (num * num) % mod;
        x >>= 1;
    }
    return ans;
}
#define inv(x) qpow(x, mod - 2)

void solve()
{
    i64 m, first = -1, ret = 0, digit;
    std::cin >> m;
    digit = m;

    std::vector<int> a(10);
    std::vector<int> ans(10);
    for (auto &num : a)
        std::cin >> num;
    if (m == 1)
    {
        for (int i = 0; i < 10; i++)
        {
            if (a[i] > 0)
            {
                std::cout << i;
                return;
            }
        }
    }
    for (int i = 1; i < 10; i++)
    {
        if (a[i] > 0)
        {
            first = i;
            a[i]--, m--;
            break;
        }
    }
    for (int i = 0; i < 10 && m; i++)
    {
        if (a[i] > 0)
        {
            int c = std::min((i64)a[i], m);
            m -= c;
            ans[i] += c;
        }
    }
    // std::cout << "a";
    ret = (ret + first * qpow(10, digit - 1) % mod) % mod;
    digit--;
    for (int i = 0; i < 10; i++)
    {
        std::cout << a[i] << " " << digit - ans[i] << ' ' << digit - 1 << '\n';
        if (ans[i] > 0)
        {
            // digit - 1 ...... (digit - 1 - ans[i] - 1)
            i64 l = digit - ans[i], r = digit - 1;
            i64 mul = qpow(10LL, l) * (qpow(10, ans[i]) - 1) % mod * inv(9LL) % mod;
            digit -= ans[i];
            ret = (ret + i * mul % mod) % mod;
        }
        std::cout << i << " ";
    }
    std::cout << ret;
}

signed main()
{
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--)
    {
        solve();
        std::cout << '\n';
    }
    return 0;
}