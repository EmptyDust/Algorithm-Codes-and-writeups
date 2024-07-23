#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, mod = 1e9 + 7;
using pii = std::pair<i64, i64>;
using a3 = std::array<i64, 3>;

const int M = 22;
const i64 inf = 4e18;
void solve() {
    int n;std::cin >> n;
    std::vector<i64> a(n + 1);
    for (int i = 1;i <= n;++i)std::cin >> a[i];
    std::vector<int> adj[n + 1];
    for (int i = 1;i < n;++i) {
        int u, v;std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::vector<std::vector<i64>> dp(n + 1, std::vector<i64>(M));
    std::function<void(int, int)> dfs = [&](int v, int p)->void {
        for (int i = 0;i < M;++i)
            dp[v][i] = a[v] * (i + 1);
        for (int nxt : adj[v])if (nxt != p) {
            dfs(nxt, v);

            for (int x = 0;x < M;++x) {
                i64 add = inf;
                for (int y = 0;y < M;++y)if (x != y) {
                    add = std::min(add, dp[nxt][y]);
                }
                dp[v][x] += add;
            }
        }
        };
    dfs(1, 0);
    std::cout << *std::min_element(dp[1].begin(), dp[1].end());
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