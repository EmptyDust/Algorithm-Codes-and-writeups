#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

std::vector<int> adj[MAXN];

int height[MAXN], f[MAXN], clen[MAXN];

void dfs(int u, int p) {
    height[u] = 1;
    std::vector<pii> child_max(2, { 0,0 });
    for (int v : adj[u])if (v != p) {
        dfs(v, u);
        height[u] = std::max(height[u], height[v] + 1);
        pii x = { height[v],v };
        for (int i = 0;i < 2;++i)if (child_max[i].first < x.first)std::swap(child_max[i], x);
        clen[u] = std::max(clen[u], clen[v]);
    }
    clen[u] = std::max(clen[u], child_max[0].first + child_max[1].first + 1);
}

void dfs2(int u, int p, int len, int ulen) {
    // std::cout << u << ' ' << p << ' ' << len << ' ' << ulen << '\n';
    f[u] = len;
    std::vector<pii> cheight_max(3, { 1,0 });
    for (int v : adj[u])if (v != p) {
        f[u] = std::max(f[u], clen[v]);
        pii x = { height[v] + 1,v };
        for (int i = 0;i < 3;++i)if (cheight_max[i].first < x.first)std::swap(cheight_max[i], x);
    }
    // std::cout << cheight_max[0].first << ' ' << height[u] << '\n';
    for (int v : adj[u])if (v != p) {
        if (v == cheight_max[0].second)
            dfs2(v, u, std::max({ len, ulen + cheight_max[1].first,cheight_max[1].first + cheight_max[2].first - 1 }), std::max(ulen + 1, cheight_max[1].first));
        else if (v == cheight_max[1].second)
            dfs2(v, u, std::max({ len, ulen + cheight_max[0].first,cheight_max[0].first + cheight_max[2].first - 1 }), std::max(ulen + 1, cheight_max[0].first));
        else
            dfs2(v, u, std::max({ len, ulen + cheight_max[0].first,cheight_max[0].first + cheight_max[1].first - 1 }), std::max(ulen + 1, cheight_max[0].first));
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;std::cin >> n;
    for (int i = 1;i < n;++i) {
        int u, v;std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    dfs2(1, 0, 0, 0);
    for (int i = 1;i <= n;++i) {
        std::cout << f[i] - 1 << '\n';
    }
    return 0;
}