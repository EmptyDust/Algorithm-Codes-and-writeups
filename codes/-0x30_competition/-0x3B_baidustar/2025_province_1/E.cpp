#include <bits/stdc++.h>

using i64 = long long;

bool f(int x)
{
    return x && (x & -x) != x;
}

void solve()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector<int> cnt(n + 1), vis(n + 1);
    for (auto &x : a)
    {
        std::cin >> x;
        cnt[x]++;
    }
    for (auto x : cnt)
    {
        if (f(x + 1))
        {
            std::cout << "No\n";
            return;
        }
    }
    vis[a[0]] = 1;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] != a[i - 1])
        {
            if (vis[a[i]])
            {
                std::cout << "No\n";
                return;
            }
            vis[a[i]] = 1;
        }
    }
    std::cout << "Yes\n";
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