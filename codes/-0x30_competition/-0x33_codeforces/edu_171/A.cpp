#include <bits/stdc++.h>

void solve()
{
    int x, y, k;
    std::cin >> x >> y >> k;
    int a = std::min(x, y);
    std::cout << "0 0 " << a << ' ' << a << '\n';
    std::cout << a << " 0" << " 0 " << a;
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