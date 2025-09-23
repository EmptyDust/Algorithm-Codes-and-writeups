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
    a3 now;
    auto work = [&](int a, int b, int &x)
    {
        // std::cout << a << ' ' << b << ' ' << x << '\n';
        if (now[a] < now[b])
        {
            int c = std::min(x, now[b] - now[a]);
            x -= c;
            now[a] += c;
        }
        else
        {
            int c = std::min(x, now[a] - now[b]);
            x -= c;
            now[b] += c;
        }
        now[a] += x / 2;
        now[b] += x - x / 2;
    };
    std::vector<int> idx{0, 1, 2};
    auto check = [&](int x, int st02, int st12, int all) -> bool
    {
        int limit0 = std::max(x - now[idx[0]], 0);
        int limit1 = std::max(x - now[idx[1]], 0);
        int limit2 = std::max(x - now[idx[2]], 0);
        // std::cout << limit0 << ' ' << limit1 << ' ' << limit2 << '\n';
        return limit0 <= st02 + all && limit1 <= st12 + all && limit2 <= st02 + st12 + all - limit0 - limit1;
    };
    int ans = 0;
    do
    {
        auto b(a);
        now = {b[1], b[2], b[4]};
        int st01 = (1 << idx[0]) | (1 << idx[1]);
        int st02 = (1 << idx[0]) | (1 << idx[2]);
        int st12 = (1 << idx[1]) | (1 << idx[2]);
        work(idx[0], idx[1], b[st01]);
        int l = 0, r = S;
        // for (auto x : now)
        //     std::cout << x << ' ';
        // std::cout << "\n";
        // std::cout << check(1, b[st02], b[st12], b[7]) << '\n';
        while (l < r)
        {
            int mid = l + r >> 1;
            if (!check(mid, b[st02], b[st12], b[7]))
                r = mid;
            else
                l = mid + 1;
        }
        // std::cout << l << "\n";
        ans = std::max(ans, l - 1);
    } while (std::next_permutation(idx.begin(), idx.end()));
    std::cout << ans << "\n";
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