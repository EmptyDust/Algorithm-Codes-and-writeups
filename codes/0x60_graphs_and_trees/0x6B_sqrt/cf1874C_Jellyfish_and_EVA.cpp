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

std::vector<std::vector<double>> possible(5010, std::vector<double>(5010));

void solve() {
    int n, m;std::cin >> n >> m;
    std::vector<int> adj[n + 1];
    for (int i = 0;i < m;++i) {
        int u, v;std::cin >> u >> v;
        adj[u].push_back(v);
    }
    std::vector<double> p(n + 1, 0);
    std::vector<bool> vis(n + 1);
    std::function<void(int)> dfs = [&](int u) {
        vis[u] = 1;
        if (u == n) {
            p[u] = 1;
            return;
        }
        for (int v : adj[u])if (!vis[v]) {
            dfs(v);
        }
        int k = adj[u].size();
        std::vector<double> d;
        for (int v : adj[u]) {
            d.push_back(p[v]);
        }
        std::ranges::sort(d, std::greater<double>());
        for (int i = 1;i <= k;++i) {
            p[u] += d[i - 1] * possible[k][i];
        }
        };
    dfs(1);
    std::cout << p[1] << ' ';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cout.precision(12);
    possible[1][1] = 1;
    for (int i = 2;i <= 5000;++i) {
        possible[i][1] = 1.0 / i;
        for (int j = 2;j <= i;++j) {
            possible[i][j] = possible[i - 2][j - 2] * (j - 2) / i + possible[i - 2][j - 1] * (i - j) / i;
        }
    }
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}