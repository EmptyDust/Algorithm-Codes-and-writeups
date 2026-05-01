#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, mod = 1e9 + 7;
constexpr i64 inf = 1e18;
using pt = std::pair<i64, i64>;
using a3 = std::array<i64, 3>;
using a4 = std::array<i64, 4>;
std::vector<a3> adj[MAXN], adj2[MAXN];
int n, m, s, t;

std::vector<a3> edges;
std::vector<i64> ans;
i64 dijkstra(int s, int t, std::vector<i64>& f, std::vector<a3> adj[MAXN]) {
    std::vector<std::vector<pt>> p(n + 1);
    f.assign(n + 1, inf);
    std::priority_queue<a4> pq;
    pq.push({ 0,s,-2 });//-dis pos pid
    while (pq.size()) {
        auto [dis, pos, pid, par] = pq.top();
        pq.pop();
        if (-dis == f[pos])
            p[pos].push_back({ pid,par });
        if (-dis < f[pos]) {
            p[pos].clear();
            p[pos].push_back({ pid,par });
            f[pos] = -dis;
        }
        else continue;

        for (auto& [nxt, w, id] : adj[pos]) {
            pq.push({ dis - w,nxt,id,pos });
        }
    }
    std::set<pt> pq2;pq2.insert({ -f[t],t });
    while (pq2.size()) {
        auto [dis, pos] = *pq2.begin();
        pq2.erase(pq2.begin());
        if (pos == s)break;
        if (pq2.empty() && p[pos].size() == 1)
            ans[p[pos][0].first] = -1;
        for (auto [pid, nxt] : p[pos])
            pq2.insert({ -f[nxt],nxt });
    }
    return f[t];
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m >> s >> t;edges.resize(m + 1);
    int u, v, w;
    for (int i = 1;i <= m;++i) {
        std::cin >> u >> v >> w;
        adj[u].push_back({ v,w,i });
        adj2[v].push_back({ u,w,i });
        edges[i] = { u,v,w };
    }
    std::vector<i64> diss, dist;
    ans.assign(m + 1, inf);
    dijkstra(t, s, dist, adj2);
    auto time = dijkstra(s, t, diss, adj);
    for (int i = 1;i <= m;++i) {
        if (~ans[i]) {
            auto& [u, v, w] = edges[i];
            if (diss[u] != 1e18 && dist[v] != 1e18 && diss[u] + 1 + dist[v] < time)
                ans[i] = std::min(ans[i], w - (time - diss[u] - dist[v] - 1));
            if (ans[i] == inf)std::cout << "NO";
            else std::cout << "CAN " << ans[i];
        }
        else std::cout << "YES";
        std::cout << '\n';
    }
    return 0;
}