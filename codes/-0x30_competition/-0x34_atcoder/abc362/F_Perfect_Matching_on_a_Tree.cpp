#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;std::cin >> n;
    std::vector<int> adj[n];
    for (int i = 1;i < n;++i) {
        int u, v;std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = 0;
    std::function<int(int, int)> dfs = [&](int x, int p) {
        int cnt = 1;
        for (int nxt : adj[x]) if (nxt != p) {
            cnt += dfs(nxt, x);
        }
        ans += std::min(cnt, n - cnt);
        return cnt;
        };
    dfs(1, 0);
    std::cout << ans;
    return 0;
}