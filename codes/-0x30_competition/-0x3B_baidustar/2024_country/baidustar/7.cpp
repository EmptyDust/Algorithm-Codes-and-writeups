#include <bits/stdc++.h>

using i64 = long long;
using a4 = std::array<i64, 4>;

struct HPD {
    int tree_size;
    bool is_hpd_init = false;
    std::vector<std::vector<std::pair<int, i64>>> adj;
    std::vector<int> Fa, size, hson, top, rank, dfn, depth, edge_id, cf;
    HPD(int n = 0) {
        tree_size = n;
        adj.resize(tree_size + 1);
    }
    void add_edge(int u, int v, i64 id = 1) {
        adj[u].push_back({ v,id });
        adj[v].push_back({ u,id });
    }
    void init() {
        is_hpd_init = 1;
        Fa.assign(tree_size + 1, 0);
        size.assign(tree_size + 1, 0);
        hson.assign(tree_size + 1, 0);
        rank.assign(tree_size + 1, 0);
        dfn.assign(tree_size + 1, 0);
        depth.assign(tree_size + 1, 0);
        edge_id.assign(tree_size + 1, 0);
        top.assign(tree_size + 1, 0);
        cf.assign(tree_size + 2, 0);
        std::function<void(int, int, int)> dfs1 = [&](int u, int p, int d) {
            hson[u] = 0;
            size[hson[u]] = 0;
            size[u] = 1;
            depth[u] = d;
            for (auto [v, id] : adj[u])if (v != p) {
                dfs1(v, u, d + 1);
                size[u] += size[v];
                Fa[v] = u;
                if (size[v] > size[hson[u]]) {
                    hson[u] = v;
                }
            }
            };
        dfs1(1, 0, 0);
        // std::cout << hson[1] << ' ';
        int tot = 0;
        std::function<void(int, int, int, int)> dfs2 = [&](int u, int p, int t, int id) {
            // std::cout << top.size() << ' ';
            top[u] = t;
            dfn[u] = ++tot;
            rank[tot] = u;
            edge_id[tot] = id;
            if (hson[u]) {
                for (auto [v, id] : adj[u])if (v != p) {
                    if (v == hson[u]) {
                        dfs2(hson[u], u, t, id);
                        break;
                    }
                }
                for (auto [v, id] : adj[u])if (v != p) {
                    if (v != hson[u]) {
                        dfs2(v, u, v, id);
                    }
                }
            }
            };
        dfs2(1, 0, 1, 0);
    }
    void add(int l, int r) {
        cf[dfn[l]]++, cf[dfn[r] + 1]--;
        // std::cout << l << ' ' << r << '\n';
        // std::cout << dfn[l] << ' ' << dfn[r] + 1 << '\n';
    }
    void work(int u, int v) {
        if (!is_hpd_init)init();
        // std::cout << top[2] << ' ' << top[v] << '\n';
        while (top[u] != top[v]) {
            if (depth[top[u]] > depth[top[v]]) {
                add(top[u], u);
                u = Fa[top[u]];
            }
            else {
                add(top[v], v);
                v = Fa[top[v]];
            }
        }
        if (depth[v] > depth[u]) {
            cf[dfn[u] + 1]++, cf[dfn[v] + 1]--;
        }
        if (depth[u] > depth[v]) {
            cf[dfn[v] + 1]++, cf[dfn[u] + 1]--;
        }
    }
    auto ans() {
        for (int i = 1;i <= tree_size;++i) {
            cf[i] += cf[i - 1];
        }
        std::vector<i64> cnt(tree_size, 0);
        for (int i = 1;i <= tree_size;++i) {
            cnt[edge_id[i]] = cf[i];
        }
        return cnt;
    }
};

void solve() {
    int n, m, k;std::cin >> n >> m >> k;
    HPD hpd(n);
    std::vector<i64> wei(1, 0);
    for (int i = 1;i < n;++i) {
        int u, v, w;std::cin >> u >> v >> w;
        wei.push_back(w);
        hpd.add_edge(u, v, i);
    }
    std::vector path(1, 1);
    for (int i = 0;i < m;++i) {
        int x;std::cin >> x;
        path.push_back(x);
    }
    // hpd.work(1, 4);
    for (int i = 1;i < path.size();++i) {
        hpd.work(path[i - 1], path[i]);
    }
    auto cnt = hpd.ans();
    std::priority_queue<a4> pq;//value cnt cur
    for (int i = 1;i < n;++i) {
        pq.push({ (wei[i] - wei[i] / 2) * cnt[i],cnt[i] * wei[i],cnt[i],wei[i] });
    }
    while (k && pq.size()) {
        k--;
        auto [mi, value, cnt, cur] = pq.top();
        // std::cout << mi << ' ';
        pq.pop();
        cur /= 2;
        value = cur * cnt;
        if (value) {
            pq.push({ (cur - cur / 2) * cnt,value,cnt,cur });
        }
    }
    i64 ans = 0;
    while (pq.size()) {
        auto [mi, value, cnt, cur] = pq.top();
        pq.pop();
        ans += value;
    }
    std::cout << ans;
    // for (int x : res)std::cout << x << " ";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}