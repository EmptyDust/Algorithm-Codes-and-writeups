#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 998244353;

using pii = std::pair<int, int>;
using a3 = std::array<i64, 3>;
using a4 = std::array<i64, 4>;

struct Mi64 {
    i64 value;
    Mi64() {}
    Mi64(i64 value) { this->value = value; }
    Mi64 operator * (const i64 w) {
        return value * w % mod;
    }
    Mi64 operator * (const Mi64 w) {
        return value * w.value % mod;
    }
    Mi64 operator + (const Mi64 w) {
        return (value + w.value) % mod;
    }
    Mi64 operator - (const Mi64 w) {
        return((value - w.value) % mod + mod) % mod;
    }
    bool operator == (const Mi64 w) {
        return value == w.value;
    }
};

struct Info2 {
    Mi64 a, b;
    Info2(Mi64 a = 1, Mi64 b = 0) :a(a), b(b) {}
    Info2 operator+ (const Info2& x) {
        Info2 res = Info2();
        res.a = a * x.a;
        res.b = a * x.b + b;
        return res;
    }
    Mi64 cal(Mi64 x) {
        return a * x + b;
    }
    void print() {
        std::cout << a.value << ' ' << b.value << '\n';
    }
};

struct Info1 {
    Mi64 a, b;
    Info1(Mi64 a = 1, Mi64 b = 0) :a(a), b(b) {}
    Info1 operator+ (const Info1& x) {
        Info1 res = Info1();
        res.a = a * x.a;
        res.b = b * x.a + x.b;
        return res;
    }
    Mi64 cal(Mi64 x) {
        return a * x + b;
    }
    void print() {
        std::cout << a.value << ' ' << b.value << '\n';
    }
};

template <class T>
struct segment_tree
{
    std::vector<T> tree;
    int size;
    segment_tree(int n) {
        size = n;
        tree.assign(n << 2, T());
    }
    void update(int p, T x) { update(p, x, 1, size, 1); };
    void update(int p, T x, int l, int r, int i) {
        if (l > r) return;
        if (p < l || r < p) return;
        if (l == r) {
            tree[i] = x;
            return;
        }
        int mid = l + r >> 1;
        update(p, x, l, mid, i << 1);
        update(p, x, mid + 1, r, i << 1 | 1);
        tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }

    T query(int ql, int qr) { return query(ql, qr, 1, size, 1); };
    T query(int ql, int qr, int l, int r, int i) {
        if (l > r) return T();
        if (qr < l || r < ql)return T();
        if (ql <= l && r <= qr)return tree[i];
        int mid = l + r >> 1;
        return query(ql, qr, l, mid, i << 1) + query(ql, qr, mid + 1, r, i << 1 | 1);
    }
};

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
    void HPD_init(segment_tree<Info1>& sgt1, segment_tree<Info2>& sgt2, std::vector<pii>& a) {
        is_hpd_init = true;
        Fa.assign(tree_size + 1, 0);
        size.assign(tree_size + 1, 0);
        hson.assign(tree_size + 1, 0);
        rank.assign(tree_size + 1, 0);
        dfn.assign(tree_size + 1, 0);
        depth.assign(tree_size + 1, 0);
        top.assign(tree_size + 1, 0);
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
        for (int i = 1;i <= tree_size;++i) {
            sgt1.update(i, Info1(a[rank[i]].first, a[rank[i]].second));
            sgt2.update(i, Info2(a[rank[i]].first, a[rank[i]].second));
        }
    }
    int lca(int u, int v) {
        while (top[u] != top[v]) {
            if (depth[top[u]] > depth[top[v]])
                u = Fa[top[u]];
            else
                v = Fa[top[v]];
        }
        return depth[u] > depth[v] ? v : u;
    }
    Info1 get_info(int u, int v, segment_tree<Info1>& sgt1, segment_tree<Info2>& sgt2) {
        Info1 res1 = Info1();
        Info2 res2 = Info2();
        while (top[u] != top[v]) {
            if (depth[top[u]] > depth[top[v]]) {
                res2 = sgt2.query(dfn[top[u]], dfn[u]) + res2;
                // std::cout << dfn[u] << ' ' << top[u] << ' ';
                u = Fa[top[u]];
            }
            else {
                res1 = sgt1.query(dfn[top[v]], dfn[v]) + res1;
                v = Fa[top[v]];
            }
        }
        if (depth[u] > depth[v]) {
            res2 = sgt2.query(dfn[v], dfn[u]) + res2;
        }
        else {
            res1 = sgt1.query(dfn[u], dfn[v]) + res1;
        }
        return Info1(res2.a, res2.b) + res1;
    }

    a3 diam() {
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
    int n, q;std::cin >> n >> q;
    std::vector<pii> a(n + 1);
    for (int i = 1;i <= n;++i)std::cin >> a[i].first >> a[i].second;
    HPD_tree tree(n);
    segment_tree<Info1> sgt1(n + 1);
    segment_tree<Info2> sgt2(n + 1);
    for (int i = 2;i <= n;++i) {
        int u, v;std::cin >> u >> v;u++, v++;
        tree.add_edge(u, v);
    }
    tree.HPD_init(sgt1, sgt2, a);

    while (q--) {
        int op;std::cin >> op;
        if (op) {
            int u, v, x;std::cin >> u >> v >> x;u++, v++;
            // std::cout << u << v << x << "\n";
            std::cout << tree.get_info(u, v, sgt1, sgt2).cal(x).value << '\n';
        }
        else {
            int p, c, d;std::cin >> p >> c >> d;p++;
            sgt1.update(tree.dfn[p], Info1(c, d));
            sgt2.update(tree.dfn[p], Info2(c, d));
        }
    }
    return 0;
}
