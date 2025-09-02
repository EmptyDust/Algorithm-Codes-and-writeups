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

struct EDCC {
    int n, m, now, cnt;
    std::vector<std::vector<a2>> ver;
    std::vector<int> dfn, low, col, S;

    EDCC(int n) : n(n), low(n + 1), ver(n + 1), dfn(n + 1), col(n + 1) {
        m = now = cnt = 0;
    }
    void add(int x, int y) { // 和 scc 相比多了一条连边
        ver[x].push_back({ y, m });
        ver[y].push_back({ x, m++ });
    }
    void tarjan(int x, int fa) {
        dfn[x] = low[x] = ++now;
        S.push_back(x);
        for (auto& [y, id] : ver[x]) {
            if (!dfn[y]) {
                tarjan(y, id);
                low[x] = std::min(low[x], low[y]);
            }
            else if (id != fa && dfn[y] < dfn[x]) {
                low[x] = std::min(low[x], dfn[y]);
            }
        }
        if (dfn[x] == low[x]) {
            int pre;
            cnt++;
            do {
                pre = S.back();
                col[pre] = cnt;
                S.pop_back();
            } while (pre != x);
        }
    }

    int work(std::vector<int>& a, int V) {
        tarjan(1, 0);
        // for (auto x : col)std::cerr << x << ' ';std::cerr << std::endl;
        i64 ans = 1;
        std::vector<int> vis(n + 1), white(n + 1);
        int cur = -1;
        bool f = true;
        auto dfs2 = [&](auto&& self, int u, int color, bool iswhite) {
            if (col[u] != color) return;
            if (vis[u]) {
                if (iswhite != white[u]) f = false;
                return;
            }
            white[u] = iswhite;
            vis[u] = 1;
            if (a[u] != cur && a[u] != -1) {
                if (cur == -1) cur = a[u];
                else ans = 0;
            }
            for (auto [v, id] : ver[u]) {
                self(self, v, color, !iswhite);
            }
            // std::cerr << u << " " << cur << std::endl;
            };
        for (int u = 1;u <= n;++u) if (!vis[u]) {
            f = true;
            cur = -1;
            dfs2(dfs2, u, col[u], 0);
            if (cur == -1 && f) {
                ans = ans * V % mod;
            }
            if (cur > 0 && !f) {
                ans = 0;
            }
            // std::cerr << u << ' ' << cur << ' ' << f << '\n';
        }
        return ans;
    }
};


void solve() {
    i64 n, m, V;std::cin >> n >> m >> V;
    std::vector<int> a(n + 1);
    for (int i = 1;i <= n;++i)std::cin >> a[i];
    EDCC edcc(n);
    for (int i = 0;i < m;++i) {
        int u, v;
        std::cin >> u >> v;
        edcc.add(u, v);
    }
    std::cout << edcc.work(a, V);
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