#include <bits/stdc++.h>

using i64 = long long;

const int mod = 998244353;

i64 qpow(i64 x, i64 p)
{
    if (p < 0)
        return 0;
    i64 r = 1;
    while (p)
    {
        if (p & 1)
            r = r * x % mod;
        x = x * x % mod;
        p >>= 1;
    }
    return r;
}

#define inv(x) qpow(x, mod - 2)

void solve()
{
    int n;
    std::cin >> n;
    std::vector adj(n, std::vector<int>());
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    i64 ans = 1;
    std::vector<i64> fact(n + 1, 1);
    for (int i = 1; i <= n; ++i)
    {
        fact[i] = fact[i - 1] * i % mod;
    }
    for (int i = 0; i < n; ++i)
    {
        int sz = adj[i].size();
        int c = sz / 2;
        ans = ans * fact[sz] % mod;
        ans = ans * inv(qpow(2, c)) % mod;
        ans = ans * inv(fact[c]) % mod;
    }
    std::cout << ans << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--)
        solve();
    return 0;
}