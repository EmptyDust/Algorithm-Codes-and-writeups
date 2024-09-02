#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6 + 10;
int p[MAXN][32], n, depth[MAXN], lg[MAXN];
using pt = pair<int, int>;
vector<int> adj[MAXN];

int lca(int x, int y) {
    if (depth[x] < depth[y])swap(x, y);
    while (depth[x] > depth[y])
        x = p[x][lg[depth[x] - depth[y]] - 1];
    if (x == y)return x;
    for (int k = lg[depth[x]] - 1;k >= 0;--k)
        if (p[x][k] != p[y][k])
            x = p[x][k], y = p[y][k];
    return p[x][0];
}

void dfs(int x, int par) {
    p[x][0] = par;
    depth[x] = depth[par] + 1;
    for (int i = 1;i <= lg[depth[x]];++i)
        p[x][i] = p[p[x][i - 1]][i - 1];

    for (int nxt : adj[x])if (nxt != par)dfs(nxt, x);
}

signed main() {
    ios::sync_with_stdio(false);
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 1;i <= n;++i)
        lg[i] = lg[i >> 1] + 1;
    int u, v;
    for (int i = 1;i < n;++i) {
        int u, v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(s, 0);
    int x, y;
    while (m--) {
        cin >> x >> y;
        cout << lca(x, y) << '\n';
    }
    return 0;
}