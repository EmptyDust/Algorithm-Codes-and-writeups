#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9 + 100, mod = 1e9 + 7;
using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;

struct dsu {
    std::vector<int> d;
    dsu(int n) { d.resize(n); iota(d.begin(), d.end(), 0); }
    int get_root(int x) {
        int R = x;
        while (R != d[R]) {
            R = d[R];
        }
        int t = x;
        while (t != d[t]) {
            int p = t;
            t = d[t];
            d[p] = R;
        }
        return R;
    };
    bool merge(int u, int v) {
        if (get_root(u) != get_root(v)) {
            d[get_root(u)] = get_root(v);
            return true;
        }
        else return false;
    }
    void init(int x) { d[x] = x; }
};

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, m, q;std::cin >> n >> m >> q;


    int b = std::sqrt(n) + 1;
    std::vector<std::unordered_map<int, int>> g(n + 1);

    auto set = [&](int u, int v, int w) -> void {
        if (u > v)std::swap(u, v);
        if (g[u].count(v))g[u][v] = std::min(g[u][v], w);
        else g[u][v] = w;
        };
    auto get = [&](int u, int v) -> int {
        if (u > v)std::swap(u, v);
        if (g[u].count(v))return g[u][v];
        else return -1;
        };


    std::vector<a3> edges(m);
    for (int i = 0;i < m;++i) {
        int u, v, w;std::cin >> u >> v >> w;u--, v--;
        edges[i] = { w,u,v };
        set(u, v, w);
    }
    std::sort(edges.begin(), edges.end());

    std::vector<bool> points(n);
    dsu d(n);

    auto kruskal = [&]() {
        i64 res = 0;
        for (auto& [w, u, v] : edges) {
            if (!points[u] || !points[v])continue;
            if (d.merge(u, v)) {
                res += w;
            }
        }
        return res;
        };

    auto prim = [&](std::vector<int>& ps, int k)->i64 {
        std::vector<int> dis(k, inf);
        std::vector<bool> vis(k);
        int cur = 0;
        i64 ans = 0;
        for (int i = 0;i < k - 1;++i) {
            vis[cur] = 1;
            int min = inf, min_p = -1;
            for (int j = 0;j < k;++j)if (!vis[j]) {
                int d = get(ps[cur], ps[j]);
                if (d != -1) {
                    dis[j] = std::min(dis[j], d);
                }
                if (dis[j] < min) {
                    min = dis[j];
                    min_p = j;
                }
            }
            if (min_p == -1)return -1;
            cur = min_p;
            ans += min;
        }
        return ans;
        };

    while (q--) {
        int k;std::cin >> k;
        std::vector<int> ps(k);
        for (int& x : ps)std::cin >> x, x--;
        if (k < b) {
            std::cout << prim(ps, k);
        }
        else {
            for (int& x : ps) {
                points[x] = 1;
            }
            i64 res = kruskal();
            int F = d.get_root(ps[0]);
            bool f = true;
            for (int& x : ps) {
                if (d.get_root(x) != F)f = false;
                points[x] = 0;
            }
            for (int x : ps)
                d.init(x);
            if (f)std::cout << res;
            else std::cout << -1;
        }
        std::cout << '\n';
    }

    return 0;
}