
#include <bits/stdc++.h>

using i64 = long long;
const i64 inf = 1e18 + 100;

void solve()
{
    int n;
    std::cin >> n;
    std::vector<i64> a(n), pre(n), suf(n);
    for (auto& x : a)
        std::cin >> x;
    if (n % 2)
    {
        i64 max = 0;
        for (int i = 1; i < n; i += 2)
        {
            pre[i] = max = std::max(max, a[i] - a[i - 1]);
        }
        max = 0;
        for (int i = n - 2; i >= 0; i -= 2)
        {
            suf[i] = max = std::max(max, a[i + 1] - a[i]);
        }
        i64 ans = inf;
        for (int i = 0; i < n; i += 2)
        {
            ans = std::min(ans, std::max(i ? pre[i - 1] : 1, i == n - 1 ? 1 : suf[i + 1]));
        }
        std::cout << ans;
    }
    else
    {
        i64 ans = 0;
        for (int i = 0; i < n; i += 2)
        {
            ans = std::max(ans, a[i + 1] - a[i]);
        }
        std::cout << ans;
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--)
    {
        solve();
        std::cout << '\n';
    }
    return 0;
}