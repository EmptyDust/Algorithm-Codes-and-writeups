#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

void solve() {
    int n;std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0;i < n;++i)std::cin >> a[i];
    std::vector<int> adj[n];
    for (int i = 1;i < n;++i) {
        int v;std::cin >> v;v--;
        adj[v].push_back(i);
    }
    std::function<int(int)> dfs = [&](int u)->int {
        if (adj[u].empty())return a[u];
        int min = inf;
        for (int v : adj[u]) {
            min = std::min(min, dfs(v));
        }
        if (u == 0)return min + a[u];
        if (a[u] > min)return min;
        return (a[u] + min) / 2;
        };
    std::cout << dfs(0);
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