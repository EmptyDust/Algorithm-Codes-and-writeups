#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

std::vector<int> adj[MAXN];
int color[MAXN], Fa[MAXN], depth[MAXN], need[MAXN];
void dfs_p(int u, int p, int d) {
    Fa[u] = p;
    depth[u] = d;
    for (auto v : adj[u])if (v != p) {
        dfs_p(v, u, d + 1);
    }
}

void solve() {
    int n, k;std::cin >> n >> k;
    std::vector<int> b;b.reserve(k);

    for (int i = 0;i < k;++i) {
        int x;std::cin >> x;
        x--;
        b.push_back(x);
        color[x] = 1;
    }
    // std::vector adj(n, std::vector<int>());
    for (int i = 0;i < n - 1;++i) {
        int u, v;std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs_p(0, -1, 0);
    std::sort(b.begin(), b.end(), [&](int x, int y) {
        return depth[x] > depth[y];
        });
    auto fill = [&](int u) {
        color[u] = 2;
        for (auto v : adj[u]) if (color[v] == 0) {
            color[v] = 3;
        }
        };
    for (int u : b) {
        int p = Fa[u];
        if (p != -1 && color[p] == 0) {
            if (Fa[p] != -1 && color[Fa[p]] != 1)
                fill(Fa[p]);
            else
                fill(p);
        }
        for (auto v : adj[u])if (v != Fa[u]) {
            if (color[v] == 0) {
                color[v] = 2;
            }
        }
    }

    int ans = 0;
    for (int i = 0;i < n;++i)if (color[i] == 2) {
        ans++;
        // std::cout << i << ' ';
    }
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}