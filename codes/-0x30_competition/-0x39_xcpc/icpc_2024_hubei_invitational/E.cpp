#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int color[MAXN], n;
using pt = std::pair<int, int>;
std::vector<int> adj[MAXN];

std::queue<int> q;
void dfs1(int x, int p, int t) {
    color[x] = 1;
    if (!t) {
        q.push(x);
        return;
    }
    for (int nxt : adj[x])if (nxt != p) {
        dfs1(nxt, x, t - 1);
    }
}

int dpest = -1, dpest_p = 0;
int dfs2(int x, int p, int depth) {
    if (depth > dpest_p) {
        dpest_p = depth;
        dpest = x;
    }
    for (int nxt : adj[x])if (nxt != p && color[nxt]) {
        dfs2(nxt, x, depth + 1);
    }
    return dpest;
}

int depth[MAXN], lg[MAXN], p[MAXN][30];
int lca(int x, int y) {
    if (depth[x] < depth[y])std::swap(x, y);
    while (depth[x] > depth[y])
        x = p[x][lg[depth[x] - depth[y]] - 1];
    if (x == y)return x;
    for (int k = lg[depth[x]] - 1;k >= 0;--k)
        if (p[x][k] != p[y][k])
            x = p[x][k], y = p[y][k];
    return p[x][0];
}

int get_dis(int u, int v) {
    int c = lca(u, v);
    return depth[u] + depth[v] - depth[c] * 2;
}

void bfs(int& dis, int& u, int& v) {
    std::queue<int> new_q;
    while (q.size()) {
        int& x = q.front();
        for (int nxt : adj[x])if (!color[nxt]) {
            color[nxt] = 1;
            if (dis < get_dis(u, nxt)) {
                v = nxt;
                dis = get_dis(u, v);
            }
            if (dis < get_dis(nxt, v)) {
                u = nxt;
                dis = get_dis(u, v);
            }
            new_q.push(nxt);
        }
        q.pop();
    }
    q = new_q;
}

void dfs(int x, int par) {
    p[x][0] = par;
    depth[x] = depth[par] + 1;
    for (int i = 1;i <= lg[depth[x]];++i)
        p[x][i] = p[p[x][i - 1]][i - 1];

    for (int nxt : adj[x])if (nxt != par)dfs(nxt, x);
}

void init() {
    for (int i = 1;i <= n;++i)
        lg[i] = lg[i >> 1] + 1;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int u, v;
    std::cin >> n;
    init();
    for (int i = 1;i < n;++i) {
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int r, t0;
    std::cin >> r >> t0;
    dfs(r, 0);
    dfs1(r, 0, t0);
    dpest = -1, dpest_p = 0;
    u = dfs2(r, 0, 0);
    dpest = -1, dpest_p = 0;
    v = dfs2(u, 0, 0);
    int length = get_dis(u, v), t = t0, ansi = n;
    std::vector<int> ans(n + 1);
    while (ansi) {
        //std::cout << 1ll * ansi * (t - t0) << ' ' << 1ll * (length + 1) / 2 << '\n';
        while (ansi && 1ll * ansi * (t - t0) >= 1ll * (length + 1) / 2) {
            ans[ansi] = t;
            ansi--;
        }
        t++;
        bfs(length, u, v);
    }
    for (int i = 1;i <= n;++i)std::cout << ans[i] << ' ';
    return 0;
}