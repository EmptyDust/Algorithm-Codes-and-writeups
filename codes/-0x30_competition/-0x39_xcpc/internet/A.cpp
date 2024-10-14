#include <bits/stdc++.h>
using i64 = long long;
constexpr int mod = 1e9 + 7, MAXN = 1e6;

void solve()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string>> a(n, "");
    std::vector<std::vector<bool>> vis(n, std::vector<int>(m, false));
    std::vector<std::vector<int>> cal(n, std::vector<int>(m, 0));
    std::vector<int> ans(3);
    for(auto& s:a)
        std::cin >> s;
    auto check(int i, int j) -> bool
    {

    };
    auto add(int i, int j) -> void
    {

    };
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(a[i][j] == '.')
            {

            }
        }
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
    }
    return 0;
}