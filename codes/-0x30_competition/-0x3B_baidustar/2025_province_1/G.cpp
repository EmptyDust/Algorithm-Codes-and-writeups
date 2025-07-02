// 6 8
// 24
// 3 5
// 3 6 9 12 15
// 8 11 14
// 13
// x * y - x - y
// 4 7

#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n, s;
    std::cin >> n >> s;
    std::vector<int> p(n);
    for (auto &x : p)
    {
        std::cin >> x;
        if ((x + s + 1) / 2 > s)
            s = (x + s + 1) / 2;
    }
    std::cout << s << '\n';
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