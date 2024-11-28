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

struct SCC {
    int n;
    std::vector<std::vector<pii>> adj;
    std::vector<int> stk;
    std::vector<int> dfn, low, bel, ans, p;
    std::vector<i64> sum;
    int cur, cnt;

    SCC() {}
    SCC(int n) {
        init(n);
    }

    void init(int n) {
        this->n = n;
        adj.assign(n, {});
        dfn.assign(n, -1);
        low.resize(n);
        bel.assign(n, -1);
        sum.assign(n, 0);
        ans.assign(n, 0);
        p.assign(n, 0);
        stk.clear();
        cur = cnt = 0;
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({ v,w });
    }

    void dfs(int x) {
        dfn[x] = low[x] = cur++;
        stk.push_back(x);

        for (auto [y, w] : adj[x]) {
            if (dfn[y] == -1) {
                sum[y] = sum[x] + w;
                dfs(y);
                low[x] = std::min(low[x], low[y]);
            }
            else if (bel[y] == -1) {
                if (dfn[y] <= dfn[x]) {
                    if (sum[y] - w != sum[x]) {
                        ans[x] = 1;
                    }
                }
                low[x] = std::min(low[x], dfn[y]);
            }
        }

        if (dfn[x] == low[x]) {
            int y;
            do {
                y = stk.back();
                bel[y] = cnt;
                p[cnt] |= ans[y];
                stk.pop_back();
            } while (y != x);
            cnt++;
        }
    }

    std::vector<int> work() {
        for (int i = 0; i < n; i++) {
            if (dfn[i] == -1) {
                dfs(i);
            }
        }
        std::vector<std::vector<int>> g(cnt);
        std::vector in(cnt, 0);
        for (int i = 0; i < n; i++) {
            int u = bel[i];
            for (auto [j, w] : adj[i]) {
                int v = bel[j];
                if (u == v) continue;
                g[v].push_back(u); in[u]++;
            }
        }
        std::queue<int> que;
        for (int i = 0; i < cnt; i++) if (!in[i]) que.push(i);
        while (que.size()) {
            int u = que.front(); que.pop();
            for (auto v : g[u]) {
                p[v] |= p[u];
                in[v]--;
                if (!in[v]) que.push(v);
            }
        }
        for (int i = 0; i < n; i++) ans[i] = p[bel[i]];
        return ans;
    }
};

void solve() {
    int n, m, q;std::cin >> n >> m >> q;
    SCC scc(2 * n);
    int N = 2 * n;
    for (int i = 0; i < m;++i) {
        int a, b;std::cin >> a >> b;
        if (!b)continue;
        int f = ((a % n) + n) % n;
        int t = ((a + b) % n + n) % n;
        scc.addEdge(f, t, b);
    }
    auto ans = scc.work();
    for (int i = 0;i < q;++i) {
        int x;std::cin >> x;
        x = (x % n + n) % n;
        std::cout << (ans[x] ? "Yes" : "No") << '\n';
    }
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