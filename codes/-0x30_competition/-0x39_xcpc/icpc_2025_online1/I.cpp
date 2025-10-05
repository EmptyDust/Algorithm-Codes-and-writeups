#include <bits/stdc++.h>

using i64 = long long;
using ld = long double;

using a2 = std::array<int, 2>;
using a3 = std::array<int, 3>;
using pii = std::pair<i64, i64>;
using ppi = std::pair<pii, i64>;

const int N = 1e6;
const int inf = 1e9;
const i64 INF = 1e18;
const int mod = 1e9 + 7;

i64 qpow(i64 x, i64 b)
{
    i64 ret = 1;
    while (b)
    {
        if (b & 1)
            ret = ret * x % mod;
        b >>= 1;
        x = x * x % mod;
    }
    return ret;
}

void sovle()
{
    i64 n, m, V, T;
    std::cin >> n >> m >> V >> T;
    std::vector adj(n + 1, std::vector<pii>());

    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    std::vector<pii> dis(n + 1, {1e18,0});
    std::priority_queue<ppi, std::vector<ppi>, std::greater<ppi>> q;

    q.push({{0,0},T});
    dis[T] = {0,0};
    std::vector<int> vis(n + 1);
    while (q.size())
    {
        auto [d, u] = q.top();
        q.pop();

        if (vis[u])
            continue;
        vis[u] = 1;

        for (auto [v, w] : adj[u])
        {
            pii now = d;
            if(w > V - d.second) now.first++,now.second = w;
            else now.second += w;

            if (dis[v] > now)
            {
                dis[v] = now;
                q.push({dis[v],v});
            }
        }
    }

    std::vector<i64> ans(n + 1,-1);
    for(int i = 1;i <= n;i++)
    if(dis[i].first != 1e18) ans[i] = std::max(1ll,dis[i].first + (dis[i].second > 0 ));

    for(int i = 1;i <= n;i++) std::cout << ans[i] << " ";
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
        std::cout << '\n';
    }
} 