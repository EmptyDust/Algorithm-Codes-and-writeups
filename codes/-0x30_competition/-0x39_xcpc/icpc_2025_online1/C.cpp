#include <bits/stdc++.h>

using i64 = long long;
using ld = long double;

using a2 = std::array<int, 2>;
using a3 = std::array<i64, 3>;
using pii = std::pair<int, int>;

const int N = 1e6;
const int inf = 1e9;
const i64 INF = 1e18;
const int mod = 1e9 + 7;

void sovle()
{
    int m, n;
    std::cin >> m >> n;
    std::vector<a2> info(m);
    std::map<int, int> last;
    for (auto &[x, y] : info)
    {
        std::cin >> x >> y;
        last[x] = x + 1;
    }
    std::ranges::sort(info.begin(), info.end(), [&](auto x, auto y)
                      { if (x[1] == y[1]) return x[0] < y[0]; return x[1] < y[1]; });
    int ans = n;
    for (auto [x, y] : info)
    {
        auto next = last.upper_bound(x);
        auto it = std::prev(next);
        // std::cout << x << ' ' << y << ' ' << (*it).first << ' ' << (*it).second << '\n';
        if (((*it).second) <= y)
        {
            if (next != last.end() && (*next).first == (*it).second)
            {
                (*it).second = (*next).second;
                last.erase(next);
            }
            else
            {
                (*it).second++;
            }
            ans--;
        }
        // std::cout << x << ' ' << y << ' ' << (*it).first << ' ' << (*it).second << '\n';
        // std::cout << last.size() << '\n';
    }
    std::cout << ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int t = 1;
    std::cin >> t;
    while (t--)
    {
        sovle();
        std::cout << '\n';
    }
}