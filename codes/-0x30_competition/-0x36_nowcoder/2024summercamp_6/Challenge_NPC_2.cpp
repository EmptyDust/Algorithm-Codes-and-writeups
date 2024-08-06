#include <bits/stdc++.h>

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

void solve() {
    int n, m;std::cin >> n >> m;
    std::vector<int> g[n];
    for (int i = 0;i < m;++i) {
        int u, v;std::cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    std::vector<std::vector<std::vector<int>>> nodes(n);
    std::vector<int> vis(n);
    std::function<void(int, int, int, int)> dfs = [&](int u, int p, int d, int root) {
        vis[u] = 1;
        while (nodes[root].size() < d) {
            nodes[root].push_back(std::vector<int>());
        }
        nodes[root][d - 1].push_back(u);
        for (int v : g[u])if (v != p) {
            dfs(v, u, d + 1, root);
        }
        };
    std::vector<int> d23r, r;
    for (int i = 0;i < n;++i)if (!vis[i] && (g[i].empty() || g[i].size() == 1)) {//从叶子节点开始找
        dfs(i, -1, 1, i);
        if (nodes[i].size() == 2 || nodes[i].size() == 3)d23r.push_back(i);
        else r.push_back(i);
    }
    if (r.empty() && d23r.size() == 1) {
        std::cout << -1;
        return;
    }
    std::vector<int> ans;
    for (int x : d23r) {
        for (int i = 0;i < nodes[x].size();i += 2) {
            for (int y : nodes[x][i])
                ans.push_back(y);
        }
    }
    for (int x : r) {
        for (int i = 0;i < nodes[x].size();i += 2) {
            for (int y : nodes[x][i])
                ans.push_back(y);
        }
    }
    for (int x : r) {
        for (int i = 1;i < nodes[x].size();i += 2) {
            for (int y : nodes[x][i])
                ans.push_back(y);
        }
    }
    for (int x : d23r) {
        for (int i = 1;i < nodes[x].size();i += 2) {
            for (int y : nodes[x][i])
                ans.push_back(y);
        }
    }
    for (int x : ans)std::cout << x + 1 << ' ';
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