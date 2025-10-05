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

struct node
{
    i64 mx, mn, ans;
};

void sovle()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    std::vector adj(n + 1, std::vector<int>());
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<a3> f(n + 1);
    /*
    0: no from
    1: larger
    2: smaller
    */
    auto dfs = [&](auto &&self, int u, int fa) -> void
    {
        for (auto v : adj[u])
        {
            if (v == fa)
                continue;
            self(self, v, u);
            f[u][0] = std::max(f[u][0], f[v][0]);
            f[u][0] = std::max(f[u][0], f[v][1] + f[v][2]);
            if (a[u] > a[v])
            {
                f[u][1] = std::max(f[u][1], f[v][0] + a[u] - a[v]);
                f[u][1] = std::max(f[u][1], f[v][1] + a[u] - a[v]);
            }
            else if (a[u] < a[v])
            {
                f[u][2] = std::max(f[u][2], f[v][0] - a[u] + a[v]);
                f[u][2] = std::max(f[u][2], f[v][2] - a[u] + a[v]);
            }
        }
    };
    dfs(dfs, 1, 0);
    std::cout << std::ranges::max(f[1]);
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