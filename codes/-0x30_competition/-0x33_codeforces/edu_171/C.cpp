#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::deque<int> q;
    i64 ans = (1ll + n) * n / 2;
    for (int i = n - 1; i >= 0; --i)
    {
        if (s[i] == '1')
            q.push_back(i + 1);
        else if (q.size())
        {
            ans -= q.front();
            q.pop_front();
        }
    }
    while (q.size() > 1)
    {
        ans -= q.front();
        q.pop_front();
        q.pop_back();
    }
    std::cout << ans;
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