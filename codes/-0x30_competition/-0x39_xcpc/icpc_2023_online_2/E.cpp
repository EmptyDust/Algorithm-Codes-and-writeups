#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e5;
const int MAXN = 1e5 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

std::vector<int> g[MAXN];
std::vector<int> h[MAXN];
int n, m;

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

void dfs(int x, int par) {
    p[x][0] = par;
    depth[x] = depth[par] + 1;
    for (int i = 1;i <= lg[depth[x]];++i)
        p[x][i] = p[p[x][i - 1]][i - 1];

    for (int nxt : g[x])if (nxt != par)dfs(nxt, x);
}

int get_dis(int u, int v) {
    int c = lca(u, v);
    return depth[u] + depth[v] - depth[c] * 2;
}

int vis[MAXN], ans[MAXN];
std::vector<int> query(int x) {
    std::vector<int> ret;
    if (vis[x]) {
        return ret;
    }
    int _x = x;
    for (int k = lg[depth[x]];k >= 0;--k) {
        // if (_x == 3)std::cout << (vis[2]) << ' ';
        if (p[x][k] && !vis[p[x][k]]) {
            x = p[x][k];
        }
    }
    // if (_x == 3)std::cout << p[x][0] << ' ';
    // std::cout << x << " " << _x << "\n";
    vis[_x] = 1;
    ret.push_back(_x);
    while (_x != x) {
        _x = p[_x][0];
        vis[_x] = 1;
        ret.push_back(_x);
    }
    return ret;
}

void solve() {
    std::cin >> n >> m;
    for (int i = 1;i <= n;++i)
        lg[i] = lg[i >> 1] + 1;
    for (int i = 2;i <= n;++i) {
        int x;std::cin >> x;
        g[x].push_back(i);
    }
    dfs(1, 0);
    for (int i = 0;i < m;++i) {
        int u, v;std::cin >> u >> v;
        h[u].push_back(v);
        h[v].push_back(u);
    }
    std::queue<pii> q;
    q.push({ 1,0 });vis[1] = 1;
    while (q.size()) {
        auto [p, d] = q.front();
        q.pop();
        ans[p] = d;
        for (int x : h[p])if (!vis[x]) {
            for (auto y : query(x)) {
                q.push({ y,d + 1 });
            }
        }
    }
    // std::cout << lg[n] << " ";
    for (int i = 2;i <= n;++i)std::cout << ans[i] << ' ';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    memset(ans, -1, sizeof ans);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}