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
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n;std::cin >> n;
    if (n == 1) {
        std::cout << "! " << std::endl;
        return;
    }
    std::vector g(2, std::vector<int>());
    g.reserve(7 * n);
    std::vector dis(n, std::map<int, int>());
    std::vector<int> color(n);
    for (int i = 0;i < n;++i) g[0].push_back(i);
    // ranges::shuffle(g[0], rng);
    auto ask = [&](int u) {
        int col = color[u];
        for (auto v : g[col]) if (v != u && !dis[u].count(v)) {
            std::cout << "? " << u + 1 << ' ' << v + 1 << std::endl;
            int x;std::cin >> x;
            dis[u][v] = x;
            dis[v][u] = x;
        }
        };
    int colc = 2;
    std::vector<a3> ans; ans.reserve(n);
    auto work = [&](this auto&& work, std::vector<int>& adj, int col) ->void {
        if (g[col].size() == 0) {
            // assert(adj.size() <= 2);
            if (adj.size() == 2) {
                int u = adj[0], v = adj[1];
                ans.push_back({ u, v, dis[u][v] });
            }
            return;
        }
        auto x = g[col][0];
        if (g[col].size() == 1) {
            for (auto u : adj)
                ans.push_back({ u, x, dis[u][x] });
            return;
        }
        ask(x);
        std::vector<int> r(adj.size());
        for (int i = 0;i < adj.size();++i) {
            int v = g[col][1];
            r[i] = dis[adj[i]][v] == dis[adj[i]][x] + dis[x][v];
        }
        int u = adj[0];
        std::vector<int> adj1, adj2;
        for (int i = 0;i < adj.size();++i) {
            if (r[i] == r[0]) adj1.push_back(adj[i]);
            else adj2.push_back(adj[i]);
        }
        g.push_back(std::vector<int>());
        g.push_back(std::vector<int>());
        adj1.push_back(x), adj2.push_back(x);
        // assert(colc + 1 < g.size());
        for (int v : g[col]) if (v != x) {
            g[colc + (dis[u][v] == dis[u][x] + dis[x][v])].push_back(v);
            color[v] = colc + (dis[u][v] == dis[u][x] + dis[x][v]);
        }
        // for (auto x : g[colc])std::cout << x << ' ';std::cout << '\n';
        // for (auto x : adj1)std::cout << x << ' ';std::cout << '\n';
        int tc = colc;
        colc += 2;
        work(adj1, tc);
        work(adj2, tc + 1);
        };

    int tmp = 0, u = 0, v = 0;
    ask(tmp);
    for (auto [x, d] : dis[tmp]) {
        if (dis[tmp][u] < d) u = x;
    }
    ask(u);
    for (auto [x, d] : dis[u]) {
        if (dis[u][v] < d) v = x;
    }
    ask(v);
    for (auto x : g[0]) if (x != u && x != v) {
        g[1].push_back(x), color[x] = 1;
    }
    std::vector<int> adj{ u, v };
    work(adj, 1);
    std::cout << "! ";
    for (auto [u, v, w] : ans) {
        std::cout << u + 1 << ' ' << v + 1 << ' ' << w << ' ';
    }
    std::cout << std::endl;
}

signed main() {
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}




/*
? 1 2 2
? 1 3 4
? 1 4 5
? 1 5 3
? 1 6 1
? 1 7 1
? 1 8 3
? 1 9 2
? 1 10 1
? 4 2 5
? 4 3 1
? 4 5 2
? 4 6 4
? 4 7 6
? 4 8 4
? 4 9 3
? 4 10 6
? 7 2 3
? 7 3 5
? 7 5 4
? 7 6 2
? 7 8 4
? 7 9 3
? 7 10 2
? 2 3 4
? 2 5 3
? 2 6 1
? 2 8 3
? 2 9 2
? 3 5 1
? 3 6 3
? 3 8 3
? 3 9 2
? 5 6 2
? 5 8 2
? 5 9 1
? 6 8 2
? 6 9 1
? 8 9 1
*/