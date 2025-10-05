#include <bits/stdc++.h>

using i64 = long long;
using ld = long double;

using a2 = std::array<int, 2>;
using a3 = std::array<int, 3>;
using pii = std::pair<int, int>;

const int N = 1e6;
const int inf = 1e9;
const i64 INF = 1e18;
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
    return ret;
}

void sovle()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<a2> a2s(m);
    std::vector<int> flag(n + 1);
    for (auto &[x, y] : a2s)
    {
        std::cin >> x >> y;
        if (x > y)
            std::swap(x, y);
        if (x == y - 1)
            flag[x] = 1;
    }
    if (std::accumulate(flag.begin(), flag.end(), 0ll) >= n - 1)
    {
        std::cout << "Yes";
    }
    else
        std::cout << "No";
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int t = 1;
    // std::cin >> t;
    while (t--)
    {
        sovle();
        std::cout << '\n';
    }
}