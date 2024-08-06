#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

struct dsu {
    std::vector<int> d;
    dsu(int n) { d.resize(n); iota(d.begin(), d.end(), 0); }
    int get_root(int x) { return d[x] = (x == d[x] ? x : get_root(d[x])); };
    bool merge(int u, int v) {
        if (get_root(u) != get_root(v)) {
            d[get_root(u)] = get_root(v);
            return true;
        }
        else return false;
    }
};

std::vector<pii> adj[MAXN];

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, m;std::cin >> n >> m;
    std::vector<pii> edg(m);
    for (int i = 0;i < m;++i) {
        int u, v;std::cin >> u >> v;
        u--, v--;
        edg[i] = { u,v };
        adj[u].push_back({ v,i });
        adj[v].push_back({ u,i });
    }
    int q;std::cin >> q;
    std::vector<int> cnt(n);
    std::vector<pii> qs(q);
    for (auto& [a, b] : qs) {
        std::cin >> a >> b;
        a--, b--;
        cnt[a]++;
        cnt[b]++;
    }
    int nc = 0;
    for (int i = 0;i < n;++i)if (cnt[i] % 2)nc++;
    if (nc) {
        std::cout << "NO\n";
        std::cout << nc / 2;
        return 0;
    }
    dsu d(n);
    std::vector<int> canu(m);
    for (int i = 0;i < m;++i) {
        auto [u, v] = edg[i];
        if (d.merge(u, v)) {
            canu[i] = 1;
        }
    }
    std::stack<int> que;
    std::function<bool(int, int, int)> dfs = [&](int u, int p, int f) {
        que.push(u);
        if (u == f)return true;
        for (auto [v, id] : adj[u])if (v != p && canu[id]) {
            if (dfs(v, u, f))return true;
        }
        que.pop();
        return false;
        };
    std::cout << "YES\n";
    for (int i = 0;i < q;++i) {
        auto [u, v] = qs[i];
        dfs(v, -1, u);
        std::vector<int> ans;
        while (que.size()) {
            ans.push_back(que.top());
            que.pop();
        }
        std::cout << ans.size() << '\n';
        for (int x : ans)std::cout << x + 1 << " ";
        std::cout << '\n';
    }
    return 0;
}