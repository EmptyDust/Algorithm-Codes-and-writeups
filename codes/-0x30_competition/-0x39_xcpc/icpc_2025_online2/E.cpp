#include <bits/stdc++.h>

using pii = std::pair<int, int>;
using i64 = long long;
using a3 = std::array<int, 3>;
using ld = long double;

const i64 mod = 998244353;

#define int i64

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
#define inv(x) qpow(x, mod - 2)
void slove()
{
    int N, M;
    std::cin >> N >> M;
    i64 q2_M = qpow(2, M);
    i64 q2_M_m1 = (mod * 2 + q2_M - 1) % mod;
    if (N == 1)
    {
        std::cout << 1;
        return;
    }
    else if (N == 2)
    {
        std::cout << 0;
        return;
    }
    i64 q = (mod * 2 - inv(q2_M_m1)) % mod;
    i64 m1_q = (mod * 2 + 1 - q) % mod;
    i64 a1 = q2_M * qpow(q2_M_m1, N - 2) % mod;
    // std::cout << a1 << '\n';
    int n = (N - 1) / 2;
    i64 m1_q_n = (mod * 2 + 1 - qpow(q, n)) % mod;
    i64 sum = a1 * m1_q_n % mod * inv(m1_q) % mod;
    // assert(sum >= 0);
    if (N % 2)
    {
        i64 mul = (n % 2) ? inv(mod - 1) : 1;
        assert(mul >= 0);
        sum = (sum + mul * qpow(q2_M_m1, n) % mod) % mod;
    }
    // assert(m1_q_n >= 0);
    // assert(sum >= 0);
    // std::cout << a1 << ' ' << q << '\n';
    std::cout << sum;
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