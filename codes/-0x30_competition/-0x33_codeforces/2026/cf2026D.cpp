#include <bits/stdc++.h>

using i64 = long long;
int n;

inline i64 query_sum(std::vector<i64>& pre, int l, int r)
{
    return pre[r] - pre[l - 1];
}

inline i64 query_suf_sum_mul(std::vector<i64>& suf, std::vector<i64>& _, int l, int r)
{
    return suf[l] - suf[r + 1] - query_sum(_, l, r) * (n - r);
}

void solve()
{
    std::cin >> n;
    std::vector<i64> a(n), presum(n + 1), sufsmul(n + 2), pre(n + 1), cnt(n + 1);
    for (i64& x : a)
        std::cin >> x;
    for (int i = 1; i <= n; ++i)
    {
        presum[i] = presum[i - 1] + a[i - 1];
        cnt[i] = cnt[i - 1] + n - i + 1;
    }
    for (int i = n; i >= 1; --i)
    {
        sufsmul[i] = sufsmul[i + 1] + a[i - 1] * (n - i + 1);
    }
    for (int i = 1; i <= n; ++i)
    {
        pre[i] = pre[i - 1] + query_suf_sum_mul(sufsmul, presum, i, n);
    }
    // std::cout << query_suf_sum_mul(sufsmul, presum, 1, 1);
    // for (int x : cnt)
    //     std::cout << x << " ";
    auto query = [&](i64 x)
        {
            if (!x)
                return 0ll;
            i64 p = std::lower_bound(cnt.begin(), cnt.end(), x) - cnt.begin() - 1;
            i64 c = x - cnt[p];
            // if (x == 1)
            //     std::cout << x << " " << p + 1 << ' ' << p + c << '\n';
            // std::cout << x << ' ' << p + 1 << ' ' << p + c << '\n';
            i64 res = pre[p] + query_suf_sum_mul(sufsmul, presum, p + 1, p + c);
            return res;
        };
    int q;
    std::cin >> q;
    while (q--)
    {
        i64 l, r;
        std::cin >> l >> r;
        std::cout << query(r) - query(l - 1) << '\n';
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--)
    {
        solve();
        std::cout << '\n';
    }
    return 0;
}