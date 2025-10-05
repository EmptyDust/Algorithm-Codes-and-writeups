#include <bits/stdc++.h>

using i64 = long long;
using ld = long double;

using a2 = std::array<i64, 2>;
using a3 = std::array<i64, 3>;
using pii = std::pair<int, int>;

const int N = 1e6;
const int inf = 1e9;
const i64 INF = 1e18;
const int mod = 1e9 + 7;

void sovle()
{
    int n, m;
    std::cin >> n >> m;
    std::vector g(n, std::vector<a2>());
    std::vector h(n, std::vector<int>());
    for (int i = 1; i < n; ++i)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        h[u].push_back(v);
        h[v].push_back(u);
    }

    std::vector<i64> dis(n, INF);
    std::set<a2> pq;
    dis[0] = 0;
    for (int k = 0; k <= n; ++k)
    {
        for (int u = 0; u < n; ++u)
        {
            pq.insert({dis[u], u});
        }
        while (pq.size())
        {
            auto [d, u] = *pq.begin();
            pq.erase(pq.begin());
            assert(d >= 0);
            if (dis[u] != d)
                continue;
            for (auto &[v, w] : g[u])
            {
                if (dis[u] + w < dis[v])
                {
                    dis[v] = dis[u] + w;
                    pq.insert({dis[v], v});
                }
            }
        }
        std::cout << std::accumulate(dis.begin(), dis.end(), 0ll) << '\n';
        std::vector<i64> ndis(n, INF);
        for (int u = 0; u < n; ++u)
        {
            ndis[u] = std::min(ndis[u], dis[u]);
            for (auto v : h[u])
            {
                ndis[v] = std::min(ndis[v], dis[u]);
            }
        }
        dis = ndis;
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int t = 1;
    // std::cin >> t;
    while (t--)
    {
        sovle();
    }
}