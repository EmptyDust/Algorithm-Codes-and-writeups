#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<int, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

std::vector<int> adj[MAXN];
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

void dfslca(int x, int par) {
    p[x][0] = par;
    depth[x] = depth[par] + 1;
    for (int i = 1;i <= lg[depth[x]];++i)
        p[x][i] = p[p[x][i - 1]][i - 1];

    for (int nxt : adj[x])if (nxt != par)dfslca(nxt, x);
}

int get_dis(int u, int v) {
    int c = lca(u, v);
    return depth[u] + depth[v] - depth[c] * 2;
}

void solve() {
    int n;std::cin >> n;
    for (int i = 0;i <= n;++i) {
        adj[i].clear();
        depth[i] = 0;
        lg[i] = 0;
        for (int j = 0;j < 30;++j)
            p[i][j] = 0;
    }
    for (int i = 1;i <= n;++i)
        lg[i] = lg[i >> 1] + 1;
    for (int i = 1;i < n;++i) {
        int u, v;std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfslca(1, -1);
    std::vector<int> del(n + 1), vis(n + 1), now;
    auto dfs = [&](this auto&& dfs, int u, int p, int d, int& maxpos, int& maxlen)->void {
        if (d > maxlen) {
            maxlen = d;
            maxpos = u;
        }
        for (auto v : adj[u])if (v != p && !del[v]) {
            dfs(v, u, d + 1, maxpos, maxlen);
        }
        };
    std::stack<int> stk;
    auto find_path = [&](this auto&& fps, int u, int p, int& res) ->bool {
        stk.push(u);
        if (u == res) {
            return true;
        }
        for (auto v : adj[u])if (v != p && !del[v]) {
            if (fps(v, u, res))return true;
        }
        stk.pop();
        return false;
        };
    std::vector<a3> ans;
    auto work = [&](int x) {
        // assert(del[x] == 0);

        int maxpos = x, maxlen = 0;
        dfs(x, -1, 0, maxpos, maxlen);
        int u = maxpos;
        maxpos = u, maxlen = 0;
        dfs(u, -1, 0, maxpos, maxlen);
        int v = maxpos;

        now.push_back(x);
        int i = 0;vis[x] = 1;
        while (i < now.size()) {
            for (auto v : adj[now[i]])if (!del[v] && !vis[v]) {
                now.push_back(v);
                vis[v] = 1;
            }
            ++i;
        }
        // std::cout << maxlen << '\n';
        // for (auto x : now)std::cout << x << ' ' << get_dis(x, v) << '\n';std::cout << '\n';
        ranges::sort(now, std::greater<int>());
        for (auto x : now)if (get_dis(x, v) == maxlen) {
            u = x;
            break;
        }
        for (auto x : now)if (get_dis(x, u) == maxlen) {
            v = x;
            break;
        }

        find_path(u, -1, v);
        while (stk.size()) {
            del[stk.top()] = 1;
            stk.pop();
        }
        if (u < v)std::swap(u, v);
        ans.push_back({ maxlen + 1,u,v });
        for (auto x : now)vis[x] = 0;
        now.clear();
        };
    // std::cout << get_dis(2, 4) << '\n';
    // work(1);
    // for (auto x : del)std::cout << x << ' ';std::cout << '\n';
    // work(4);
    // for (auto x : del)std::cout << x << ' ';std::cout << '\n';
    for (int i = 1;i <= n;++i) {
        while (!del[i]) {
            work(i);
        }
    }
    ranges::sort(ans, std::greater<a3>());
    for (auto [a, b, c] : ans)std::cout << a << ' ' << b << ' ' << c << ' ';

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