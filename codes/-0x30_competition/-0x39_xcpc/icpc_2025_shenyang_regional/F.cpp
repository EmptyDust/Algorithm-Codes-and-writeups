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

void solve() {
    int n, m, x, y;std::cin >> n >> m >> x >> y; x--, y--;
    if (x > y) std::swap(x, y);
    std::vector adj(n, std::vector<a2>());
    std::vector<a3> edges(m);
    bool f = 0;
    for (int i = 0;i < m;++i) {
        int u, v;std::cin >> u >> v; u--, v--;
        if (u > v) std::swap(u, v);
        edges[i] = { u, v, i };
        adj[u].push_back({ v, i });
        adj[v].push_back({ u, i });
        if (u == x && v == y) f = 1;
    }
    std::vector<a2> ans(m, { -1, -1 });
    std::set<int> set;
    set.insert(x);
    set.insert(y);
    if (f) {
        std::vector<int> fa(n, -1), fae(n, -1), depth(n, -1);
        std::deque<int> stk;
        stk.push_back(x);
        for (int i = 0;i < adj[x].size();++i) if (adj[x][i][0] == y) {
            std::swap(adj[x][0], adj[x][i]);
            break;
        }
        int spu = -1, spv = -1;
        while (stk.size()) {
            auto u = stk.front();
            stk.pop_front();
            if (u != x) ranges::sort(adj[u], [&](a2 x, a2 y) {return depth[x[0]] < depth[y[0]];});
            for (auto [v, id] : adj[u]) if (v != fa[u]) {
                if (fa[v] != -1 && spu == -1) {
                    spu = u;
                    spv = v;
                    ans[id] = { v, u };
                    continue;
                }
                if (fa[v] == -1) {
                    stk.push_back(v);
                    fa[v] = u;
                    fae[v] = id;
                    depth[v] = depth[u] + 1;
                    ans[id] = { v, u };
                }
            }
        }
        if (spu == -1) {
            std::cout << "No\n";
            return;
        }
        int cur = spv;
        while (cur != x) {
            ans[fae[cur]] = { fa[cur], cur };
            set.insert(cur);
            cur = fa[cur];
        }
        cur = spu;
        while (cur != x) {
            set.insert(cur);
            cur = fa[cur];
        }
    }
    for (auto u : set) {
        for (auto [v, id] : adj[u]) if (ans[id][0] == -1) {
            ans[id] = { v, u };
        }
    }
    std::cout << "Yes\n";
    for (int id = 0;id < m;++id) {
        if (ans[id][0] == -1) std::cout << edges[id][0] + 1 << ' ' << edges[id][1] + 1 << '\n';
        else std::cout << ans[id][0] + 1 << ' ' << ans[id][1] + 1 << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}