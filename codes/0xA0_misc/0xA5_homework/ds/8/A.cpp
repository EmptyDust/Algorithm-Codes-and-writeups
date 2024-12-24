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

struct Graph
{
    std::vector<std::vector<pii>> adj;
    int n;
    Graph(int n) :n(n) {
        adj.assign(n, std::vector<pii>(n));
    }
    void editEdge(int u, int v, int w) {
        // adj[u][v] = w;
        adj[u].push_back({ v,w });
        adj[v].push_back({ u,w });
    }
    void dfs() {
        std::vector<int> vis(n);
        auto dfs1 = [&](auto&& self, int u)->void {
            if (vis[u])return;
            vis[u] = 1;
            std::cout << u << ' ';
            for (auto [v, w] : adj[u])
                self(self, v);
            };
        for (int i = 0;i < n;++i)
            if (!vis[i])
                dfs1(dfs1, i);
    }
    void bfs() {
        std::vector<int> vis(n);
        auto bfs1 = [&](int x) {
            std::queue<int> q;q.push(x);
            while (q.size()) {
                int c = q.front();
                q.pop();
                for (auto [v, w] : adj[c]) {
                    if (!vis[v]) {
                        vis[v] = 1;
                        q.push(v);
                    }
                }
            }
            };
        for (int i = 0;i < n;++i)
            if (!vis[i])
                bfs1(i);
    }
    std::vector<int> dijkstra(int root) {
        std::vector<int> res(n, -1);
        std::priority_queue<pii, std::vector<pii>, std::greater<int>> pq;
        pq.push({ 0,root });
        while (pq.size()) {
            auto [u, W] = pq.top();
            pq.pop();
            if (res[u] != W)continue;
            for (auto [v, w] : adj[u]) {
                if (res[v] == -1 || W + w < res[v]) {
                    res[v] = W + w;
                    pq.push({ W + w,v });
                }
            }
        }
        return res;
    }
};

void solve() {

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