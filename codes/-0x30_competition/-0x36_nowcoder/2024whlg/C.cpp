#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pt = std::pair<int, int>;
int n, k, nums[MAXN];
std::vector<int> adj[MAXN];
i64 res[MAXN];

std::vector<int> q;
void dfs(int x, int par) {
    q.push_back(x);
    int y = q[std::max(0, (int)q.size() - k - 1)];
    std::cout << x << " " << y << '\n';
    res[y] += nums[x];
    res[x] -= nums[par];
    for (int nxt : adj[x])if (nxt != par)
        dfs(nxt, x);
    q.pop_back();
}

void dfs2(int x, int par) {
    res[x] += res[par];
    for (int nxt : adj[x])if (nxt != par)
        dfs2(nxt, x);
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> k;
    for (int i = 1;i <= n;++i)std::cin >> nums[i];
    int u, v;
    for (int i = 1;i < n;++i) {
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    dfs2(1, 0);
    for (int i = 1;i <= n;++i)std::cout << res[i] << ' ';
    return 0;
}