#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n;std::cin >> n;
    std::vector<int> adj[n + 1];
    for (int i = 1;i < n;++i) {
        int u, v;std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int res = -1;
    std::vector<int> tag(n + 1);
    std::function<int(int, int, bool)> dfs = [&](int x, int p, bool f) ->int {
        int cnt = 1;
        for (int nxt : adj[x])if (nxt != p) {
            cnt += dfs(nxt, x, f);
        }
        if (f) {
            tag[x] = 1;
        }
        else if (cnt * 2 == n) {
            dfs(x, p, 1);
            res = x;
        }
        return cnt;
        };
    dfs(1, 0, 0);
    if (res == -1) {
        for (int i = 1;i <= n;++i)if (adj[i].size()) {
            std::cout << i << ' ' << adj[i][0] << '\n';
            std::cout << i << ' ' << adj[i][0] << '\n';
            return;
        }
    }
    for (int i = 1;i <= n;++i)if (adj[i].size() == 1 && !tag[i]) {
        std::cout << i << ' ' << adj[i][0] << '\n';
        std::cout << i << ' ' << res << '\n';
        return;
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}