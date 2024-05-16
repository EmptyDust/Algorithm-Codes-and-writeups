#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, m;
    std::cin >> n >> m;
    std::vector<int> adj(n, inf), cnt(n, 0);
    int u, v;
    while (m--) {
        std::cin >> u >> v;u--, v--;
        if (v < u)v += n;
        adj[u] = std::min(adj[u], v - u);
        cnt[u]++;
    }
    int mx = *std::max_element(cnt.begin(), cnt.end());
    for (int i = 0;i < n;++i) {
        int base = (mx - 1) * n, ans = base;
        for (int j = i;j < i + n;++j) {
            int t = j % n;
            if (adj[t] == inf)continue;
            int dis = j - i;
            if (cnt[t] == mx - 1) {
                ans = std::max(ans, base + adj[t] + dis - n);
            }
            if (cnt[t] == mx) {
                ans = std::max(ans, base + adj[t] + dis);
            }
        }
        std::cout << ans << ' ';
    }
    return 0;
}