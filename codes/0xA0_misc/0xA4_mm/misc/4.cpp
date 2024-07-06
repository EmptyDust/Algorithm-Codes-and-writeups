#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e6 + 10;
using i64 = long long;
vector<int> g[MAXN];
int w[MAXN], p[MAXN];

void dfs(int u, int h) {
    if (w[u] <= h) return;
    w[u] = h;
    for (int v : g[u]) dfs(v, h);
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)cin >> w[i];
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    iota(p + 1, p + n + 1, 1);
    sort(p + 1, p + n + 1, [&](int i, int j) {
        return w[i] < w[j];
        });

    for (int i = 1; i <= n; i++) {
        int u = p[i];
        for (int v : g[u]) dfs(v, w[u]);
    }
    i64 ans = accumulate(w + 1, w + n + 1, (i64)0);
    cout << ans << '\n';
    for (int i = 1; i <= n; i++) cout << w[i] << " \n"[i == n];
    return 0;
}