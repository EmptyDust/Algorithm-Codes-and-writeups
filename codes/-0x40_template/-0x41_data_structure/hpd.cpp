#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;

using pii = std::pair<int, int>;
using a3 = std::array<i64, 3>;
using a4 = std::array<i64, 4>;

// template<class T>
struct HPD_tree
{
    int tree_size;
    bool is_hpd_init = false;
    std::vector<std::vector<std::pair<int, i64>>> adj;
    std::vector<int> Fa, size, hson, top, rank, dfn, depth;
    HPD_tree(int n = 0) {
        tree_size = n;
        adj.resize(tree_size + 1);
    }
    void add_edge(int u, int v, i64 w = 1) {
        adj[u].push_back({ v,w });
        adj[v].push_back({ u,w });
    }
    void HPD_init() {
        is_hpd_init = true;
        Fa.assign(tree_size + 1, 0);
        size.assign(tree_size + 1, 0);
        hson.assign(tree_size + 1, 0);
        rank.assign(tree_size + 1, 0);
        dfn.assign(tree_size + 1, 0);
        depth.assign(tree_size + 1, 0);
        std::function<void(int, int, int)> dfs1 = [&](int u, int p, int d)->void {
            hson[u] = 0;
            size[hson[u]] = 0;
            size[u] = 1;
            depth[u] = d;
            for (auto [v, w] : adj[u])if (v != p) {
                dfs1(v, u, d + 1);
                size[u] += size[v];
                Fa[v] = u;
                if (size[v] > size[hson[u]]) {
                    hson[u] = v;
                }
            }
            };
        dfs1(1, 0, 0);
        int tot = 0;
        std::function<void(int, int, int)> dfs2 = [&](int u, int p, int t)->void {
            top[u] = t;
            dfn[u] = ++tot;
            rank[tot] = u;
            if (hson[u]) {
                dfs2(hson[u], u, t);
                for (auto [v, w] : adj[u])if (v != p && v != hson[u]) {
                    dfs2(v, u, v);
                }
            }
            };
        dfs2(1, 0, 1);
    }
    int lca(int u, int v) {
        if (!is_hpd_init)HPD_init();
        while (top[u] != top[v]) {
            if (depth[top[u]] > depth[top[v]])
                u = Fa[top[u]];
            else
                v = Fa[top[v]];
        }
        return depth[u] > depth[v] ? v : u;
    }
    a3 get_diam() {
        i64 cur; int pos;
        std::function<void(int, int, i64)> dfs = [&](int u, int p, i64 d) {
            if (d > cur) {
                cur = d;
                pos = u;
            }
            for (auto [v, dis] : adj[u])if (v != p) {
                dfs(v, u, d + dis);
            }
            };
        cur = 0, pos = 1;
        dfs(pos, 0, cur);
        int u = pos;
        cur = 0;
        dfs(pos, 0, cur);
        int v = pos;
        return { u,v,cur };
    }
};


signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);

    return 0;
}
