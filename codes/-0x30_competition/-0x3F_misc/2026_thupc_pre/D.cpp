#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<int, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
// const int mod = 1e9 + 7;
const int mod = 998244353;

constexpr int inf = 40 * 5000;
template<class T>
struct MaxFlow {
    struct _Edge {
        int to;
        T cap;
        _Edge(int to, T cap) : to(to), cap(cap) {}
    };

    int n;
    std::vector<_Edge> e;
    std::vector<std::vector<int>> g;
    std::vector<int> cur, h;

    MaxFlow() {}
    MaxFlow(int n) {
        init(n);
    }

    void init(int n) {
        this->n = n;
        e.clear();
        g.assign(n, {});
        cur.resize(n);
        h.resize(n);
    }

    bool bfs(int s, int t) {
        h.assign(n, -1);
        std::queue<int> que;
        h[s] = 0;
        que.push(s);
        while (!que.empty()) {
            const int u = que.front();
            que.pop();
            for (int i : g[u]) {
                auto [v, c] = e[i];
                if (c > 0 && h[v] == -1) {
                    h[v] = h[u] + 1;
                    if (v == t) {
                        return true;
                    }
                    que.push(v);
                }
            }
        }
        return false;
    }

    T dfs(int u, int t, T f) {
        if (u == t) {
            return f;
        }
        auto r = f;
        for (int& i = cur[u]; i < int(g[u].size()); ++i) {
            const int j = g[u][i];
            auto [v, c] = e[j];
            if (c > 0 && h[v] == h[u] + 1) {
                auto a = dfs(v, t, std::min(r, c));
                e[j].cap -= a;
                e[j ^ 1].cap += a;
                r -= a;
                if (r == 0) {
                    return f;
                }
            }
        }
        return f - r;
    }
    void addEdge(int u, int v, T c) {
        g[u].push_back(e.size());
        e.emplace_back(v, c);
        g[v].push_back(e.size());
        e.emplace_back(u, 0);
    }
    T flow(int s, int t) {
        T ans = 0;
        while (bfs(s, t)) {
            cur.assign(n, 0);
            ans += dfs(s, t, std::numeric_limits<T>::max());
        }
        return ans;
    }

    std::vector<bool> minCut() {
        std::vector<bool> c(n);
        for (int i = 0; i < n; i++) {
            c[i] = (h[i] != -1);
        }
        return c;
    }

    struct Edge {
        int from;
        int to;
        T cap;
        T flow;
    };
    std::vector<Edge> edges() {
        std::vector<Edge> a;
        for (int i = 0; i < e.size(); i += 2) {
            Edge x;
            x.from = e[i + 1].to;
            x.to = e[i].to;
            x.cap = e[i].cap + e[i + 1].cap;
            x.flow = e[i + 1].cap;
            a.push_back(x);
        }
        return a;
    }
};

void solve() {
    int n, m;std::cin >> n >> m;
    std::vector<int> d(n), a(n), du(n);
    for (auto& x : d) std::cin >> x;
    for (auto& x : a) std::cin >> x;
    MaxFlow<int> mf(4 * n + 2);
    int s = 4 * n, t = 4 * n + 1;
    for (int i = 0;i < n;++i) {
        if (d[i] == 0) {
            // mf.addEdge(0 * n + i, 1 * n + i, a[i]);
            mf.addEdge(s, 0 * n + i, 0);
            mf.addEdge(s, 1 * n + i, a[i]);
        }
        else if (d[i] == 1) {
            // mf.addEdge(1 * n + i, 0 * n + i, a[i]);
            mf.addEdge(s, 1 * n + i, 0);
            mf.addEdge(s, 0 * n + i, a[i]);
        }
        else {
            // mf.addEdge(0 * n + i, 3 * n + i, inf);
            // mf.addEdge(1 * n + i, 3 * n + i, inf);
            mf.addEdge(2 * n + i, 3 * n + i, a[i]);
            mf.addEdge(0 * n + i, 3 * n + i, 0);
            mf.addEdge(1 * n + i, 3 * n + i, 0);
        }
    }
    for (int i = 0;i < m;++i) {
        int u, v;std::cin >> u >> v;
        u--, v--;
        du[u]++;
        mf.addEdge(0 * n + u, 0 * n + v, 0);
        mf.addEdge(1 * n + u, 1 * n + v, 0);
        mf.addEdge(3 * n + u, 2 * n + v, 0);
        mf.addEdge(0 * n + u, 2 * n + v, 0);
        mf.addEdge(1 * n + u, 2 * n + v, 0);
    }
    for (int i = 0;i < n;++i) {
        if (du[i] == 0 && d[i] == -1) {
            mf.addEdge(0 * n + i, t, inf);
            mf.addEdge(1 * n + i, t, inf);
            mf.addEdge(3 * n + i, t, inf);
        }
    }
    std::cout << mf.flow(s, t);
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}