#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
using pt = std::pair<int, int>;

struct dsu {
    std::vector<int> d;
    dsu(int n) { d.resize(n + 1); iota(d.begin(), d.end(), 0); }
    int get_root(int x) { return d[x] = (x == d[x] ? x : get_root(d[x])); };
    bool merge(int u, int v) {
        if (get_root(u) != get_root(v)) {
            d[get_root(u)] = get_root(v);
            return true;
        }
        else return false;
    }
};

std::vector<pt> adj[MAXN];
int depth[MAXN], lg[MAXN], p[MAXN][30], f[MAXN][30];
int lca(int x, int y) {
    if (depth[x] < depth[y])std::swap(x, y);
    int ret = 1e9;
    while (depth[x] > depth[y]) {
        ret = std::min(ret, f[x][lg[depth[x] - depth[y]] - 1]);
        x = p[x][lg[depth[x] - depth[y]] - 1];
    }
    if (x == y)return ret;
    for (int k = lg[depth[x]] - 1;k >= 0;--k)
        if (p[x][k] != p[y][k]) {
            ret = std::min({ ret, f[x][k],f[y][k] });
            x = p[x][k], y = p[y][k];
        }
    ret = std::min({ ret, f[x][0],f[y][0] });
    return ret;
}

void dfs(int x, int par, int w) {
    p[x][0] = par;
    f[x][0] = w;
    depth[x] = depth[par] + 1;
    for (int i = 1;i <= lg[depth[x]];++i) {
        p[x][i] = p[p[x][i - 1]][i - 1];
        f[x][i] = std::min(f[x][i - 1], f[p[x][i - 1]][i - 1]);
    }
    for (auto [nxt, w] : adj[x])if (nxt != par)dfs(nxt, x, w);
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, m, q;
    std::cin >> n >> m >> q;
    for (int i = 1;i <= n;++i)
        lg[i] = lg[i >> 1] + 1;
    dsu d = *new dsu(n);
    std::vector<std::array<int, 3>> edges(m);
    for (auto& [u, v, w] : edges)std::cin >> u >> v >> w;
    std::sort(edges.begin(), edges.end(), [&](auto a, auto b) {return a[2] > b[2];});
    for (auto& [u, v, w] : edges) {
        if (d.merge(u, v)) {
            adj[u].push_back({ v,w });
            adj[v].push_back({ u,w });
        }
    }
    dfs(1, 0, 0);
    int u, v;
    while (q--) {
        std::cin >> u >> v;
        if (d.get_root(u) != d.get_root(v))std::cout << -1 << '\n';
        else std::cout << lca(u, v) << '\n';
    }
    return 0;
}