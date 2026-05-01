#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, m;std::cin >> n >> m;
    std::vector<int> adj[n + 1];
    for (int i = 0;i < m;++i) {
        int u, v;std::cin >> u >> v;
        adj[u].push_back(v);
    }
    i64 ans = 0;
    for (int i = 1;i <= n;++i) {
        std::vector<int> cnt(n + 1);
        for (auto x : adj[i]) {
            for (auto nxt : adj[x]) if (nxt != i) {
                ans += cnt[nxt];
                cnt[nxt]++;
            }
        }
    }
    std::cout << ans;
    return 0;
}