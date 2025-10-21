#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

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
    std::vector<int> find_nodes(int s, bool b){
        int n = g.size();
        std::vector<int> vis(n), res;
        std::queue<int> q;q.push(s);vis[s] = 1;
        while (q.size()){
            auto u = q.front();
            q.pop();
            res.push_back(u);
            for (auto& p : g[u]){
                auto& [v, c] = e[p ^ b];
                if (c > 0){
                    if (b){
                        if (!vis[e[p].to]){
                            q.push(e[p].to);
                            vis[e[p].to] = 1;
                        }
                    }
                    else {
                        if (!vis[v]){
                            q.push(v);
                            vis[v] = 1;
                        }
                    }
                }
            }
        }
        return res;
    }
};


void solve() {
    int n, m;std::cin >> n >> m;
    MaxFlow<int> mf(n * 2 + 2);
    for (int i = 1;i <= n;++i){
        mf.addEdge(0, i, 1);
        mf.addEdge(i + n, 2 * n + 1, 1);
    }
    std::set<pii> st;
    for (int i = 0;i < m;++i){
        int u, v;std::cin >> u >> v;
        mf.addEdge(u, v + n, 1);
    }
    mf.flow(0, 2 * n + 1);
    auto node1 = mf.find_nodes(0, 0);
    auto node2 = mf.find_nodes(2 * n + 1, 1);
    i64 cnt1 = 0, cnt2 = 0;
    for (auto x : node1)if (0 < x && x <= n)cnt1++;
    for (auto x : node2)if (n < x && x <= 2 * n)cnt2++;
    std::cout << cnt1 * cnt2;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}